#include "Frame.h"


using namespace std;

Frame::Frame()
{

}

Frame::Frame(cv::Mat frame)
{
	//clone here to prevent underlying Video frame from being altered
	cv::Mat interimFrame = frame.clone();
	//convert frame to greyscale to facilitate box detection
	cv::cvtColor(interimFrame, interimFrame, cv::COLOR_BGR2GRAY);

	this->frame = interimFrame.clone();
}

Frame::~Frame()
{
}

//preprocesses frame to facilitate hough line detection
void Frame::framePreprocessing(cv::Mat& preprocessedFrame)
{
	//adaptive thresholding
	adaptiveThreshold(frame, preprocessedFrame, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 35, 20);
	//erodes and then dilates the image using the kernel to remove spots within objects
	//in this case, eliminates text from the subtitles box
	cv::Mat kernel(7, 7, CV_32F, cv::Scalar(1));
	morphologyEx(preprocessedFrame, preprocessedFrame, cv::MORPH_CLOSE, kernel);
}

//detects horizontal hough lines that may be subtitle box boundaries
void Frame::detectHorizontalHough(cv::Mat frame, vector<cv::Vec4i>& lines, vector<cv::Vec4i>& filteredLines, int singleHeight, int doubleHeight)
{
	//detect lines
	HoughLinesP(frame, lines, 1, 1.5708, 80, 150, 30);

	//sort lines
	std::sort(lines.begin(), lines.end(), [](const cv::Vec4i & a, const cv::Vec4i & b) {
		return (a[1] > b[1]);
		});

	//filter lines into results that match height of subtitle boxes
	//if there is a doubleHeight box, always want that rather than a smaller snippet
	if (!lines.empty()) {
		for (size_t i = 0; i < lines.size(); i++) {
			for (size_t j = 0; j < lines.size(); j++) {
				if (lines[i][1] - lines[j][1] == doubleHeight) {
					//put results at beginning of list, so that results with the highest y elevation (most likely to be subtitle box) are processed first
					filteredLines.insert(filteredLines.begin(), lines[i]);
					filteredLines.insert(filteredLines.begin(), lines[j]);
				}
				else if (lines[i][1] - lines[j][1] == singleHeight) {
					filteredLines.insert(filteredLines.begin(), lines[i]);
					filteredLines.insert(filteredLines.begin(), lines[j]);
				}
			}
		}
	}

}

void Frame::detectHorizontalHough(cv::Mat frame, vector<cv::Vec4i>& lines, int& height)
{
	//detect lines
	HoughLinesP(frame, lines, 1, 1.5708, 80, 150, 30);

	//sort lines
	std::sort(lines.begin(), lines.end(), [](const cv::Vec4i & a, const cv::Vec4i & b) {
		return (a[1] > b[1]);
		});
	//if there are exactly two, set the height to the difference between the y values for each
	if (lines.size() == 2) {
		height = lines[0][1] - lines[1][1];
	}
	else {
		height = 0;
	}
}
//draw hough lines onto an image, used for testing effectiveness of detection
void Frame::drawHough(cv::Mat& dst, vector<cv::Vec4i> filteredLines)
{
	//draw filtered lines
	if (!filteredLines.empty() && dst.channels() < 3) {
		for (size_t i = 0; i < filteredLines.size(); i++) {
			cv::Vec4i l = filteredLines[i];
			line(dst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), 255, 3, cv::LINE_AA);
		}
	}
	//additional handling for 3 channel images
	else {
		if (!filteredLines.empty()) {
			for (size_t i = 0; i < filteredLines.size(); i++) {
				cv::Vec4i l = filteredLines[i];
				line(dst, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(255, 255, 255), 2, cv::LINE_AA);
			}
		}
	}

}

//filter out hough lines that are too long or too spaced apart to be subtitle box boundaries
void Frame::dropByLength(vector<cv::Vec4i>& filteredLines, int dropLength)
{
	//filter lines again to remove lines that are too long and remove lines that are too spaced apart on the x axis, \
	droplength zero bypasses this filter
	if (dropLength != 0) {
		if (!filteredLines.empty()) {
			for (size_t i = 0; i < filteredLines.size(); i += 2) {
				if ((filteredLines[i][2] - filteredLines[i][0]) > dropLength || (filteredLines[i + 1][2] - filteredLines[i + 1][0]) > dropLength || (filteredLines[i][0] - filteredLines[i + 1][0] > dropLength)) {
					filteredLines.erase(filteredLines.begin() + i, filteredLines.begin() + (i + 2));
				}
			}
		}
	}
}

//create a version of the frame made of contour data, to facilitate Hough line detection
void Frame::findDrawContours(cv::Mat frame, cv::Mat & dst, std::vector<std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy)
{
	findContours(frame, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
	//ensure Mat is correct size to draw onto
	dst = cv::Mat::zeros(frame.size(), CV_8UC1);
	//iterate through the contour data, drawing each contour on
	for (size_t i = 0; i < contours.size(); i++) {
		cv::Scalar color = cv::Scalar(255, 255, 255);
		drawContours(dst, contours, (int)i, color);
	}
	contours.clear();
	hierarchy.clear();
}

//records the height boundaries of potentially identified subtitle boxes
void Frame::heightBoundaryRecorder(vector<cv::Vec4i> filteredLines, vector<cv::Vec2i> & heightBoundaries)
{
	if (!filteredLines.empty()) {
		int rangeStart = (int)filteredLines[0][1];
		int rangeEnd = (int)filteredLines[1][1];
		cv::Vec2i boxHeightRecord(rangeStart, rangeEnd);
		heightBoundaries.push_back(boxHeightRecord);
	}
}



void Frame::detectBoxes(int singleHeight, int doubleHeight, vector<cv::Vec2i> & heightBoundaries, int dropLength)
{
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	vector <cv::Vec4i> lines;
	vector<cv::Vec4i> filteredLines;
	cv::Mat draw;

	//image preprocessing
	framePreprocessing(frame);

	//find and draw contours
	findDrawContours(frame, draw, contours, hierarchy);

	//hough line detection
	detectHorizontalHough(draw, lines, filteredLines, singleHeight, doubleHeight);

	//filter lines again by length to exclude lines that exceed the length of the subtitle box/are too far apart on the x axis to be part of the same box
	dropByLength(filteredLines, dropLength);

	//record the y coordinates of the identified lines
	heightBoundaryRecorder(filteredLines, heightBoundaries);
}

//Detects double-line boxes in HeightSelect
void Frame::detectDoubleBoxes(int& height, vector <cv::Vec4i> & lines) {
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	vector<cv::Vec4i> filteredLines;
	cv::Mat draw;

	//image preprocessing
	framePreprocessing(frame);

	//find and draw contours
	findDrawContours(frame, draw, contours, hierarchy);

	//detect box and get height 
	detectHorizontalHough(draw, lines, height);
}
//Detects single-line boxes in HeightSelect
void Frame::detectSingleBoxes(int& height, vector <cv::Vec4i> & lines) {
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	vector<cv::Vec4i> filteredLines;
	cv::Mat draw;

	//half image height to refine search for single box
	frame = frame.rowRange(0, frame.rows / 2);

	//image preprocessing
	framePreprocessing(frame);

	//find and draw contours
	findDrawContours(frame, draw, contours, hierarchy);

	//detect box and get height 
	detectHorizontalHough(draw, lines, height);
}
//record heights of subtitle boxes to get most common heights across video
void Frame::differenceRecorder(cv::Mat draw, map<int, int> & frequency) {
	vector<cv::Vec4i> lines;
	//detect lines
	HoughLinesP(draw, lines, 1, 1.5708, 80, 150, 30);
	//sort lines
	std::sort(lines.begin(), lines.end(), [](const cv::Vec4i & a, const cv::Vec4i & b) {
		return (a[1] > b[1]);
		});
	//if exactly two lines in the frame
	if (lines.size() == 2) {
		//add to a frequency map of the difference in y coordinates between the 2 lines (the 'height' of the area identified)
		int lineHeight = lines[0][1] - lines[1][1];
		if (frequency.find(lineHeight) != frequency.end()) {
			frequency.find(lineHeight)->second += 1;
		}
		else {
			frequency.insert({ lineHeight, 1 });
		}
	}

}

void Frame::detectHeights(map<int, int> & frequency) {
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	cv::Mat draw;

	//image preprocessing for hough line detection
	framePreprocessing(frame);
	findDrawContours(frame, draw, contours, hierarchy);

	//detect and record box heights on frame
	differenceRecorder(draw, frequency);
}

