#include "Video.h"
#include <iostream>
#include <QtWidgets\qprogressbar.h>

using namespace std;
using namespace cv;

Video::Video(std::string inputFileName, std::string outputFileName, int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd,  int dropLength, int windowSizeLeft,
	int windowSizeRight, bool autoDetectHeights, int wordConfidence, int lineConfidence, double compareThreshold, int dupeThreshold) {
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
	this->cropHeightStart = cropHeightStart;
	this->cropHeightEnd = cropHeightEnd;
	this->cropWidthStart = cropWidthStart;
	this->cropWidthEnd = cropWidthEnd;
	this->dropLength = dropLength;
	this->singleHeight = singleHeight;
	this->doubleHeight = doubleHeight;
	this->windowSizeLeft = windowSizeLeft;
	this->windowSizeRight = windowSizeRight;
	this->autoDetectHeights = autoDetectHeights;
	this->wordConfidence = wordConfidence;
	this->lineConfidence = lineConfidence;
	this->compareThreshold = compareThreshold;
	this->dupeThreshold = dupeThreshold;
}

Video::~Video() {
}

void Video::run(){
	VideoCapture cap(inputFileName);
	string textLineOne;
	string textLineTwo;
	int prevLineOneConfidence = 0;
	int prevLineTwoConfidence = 0;
	vector <cv::Vec2i> heightBoundaries;
	vector<pair<int, int>> ROICoordinates;
	vector<string> frameTexts;
	string outTexts[2];
	cv::Mat whiteSpaceCheck;
	cv::Mat frame;
	cv::Mat morphFrame;
	map<int, int> frequency;
	double frameProgress;

	if (!cap.isOpened()) {
		//pass this to GUI
		cout << "Error opening video file" << endl;
		//interrupt
	}
	if (autoDetectHeights) {
		while (1) {
			//cancel the function if cancel button is checked
			if (cancelled) {
				break;
			}

			cap >> frame;

			for (int i = 0; i < 15; i++) {
				cap.grab();
			}

			if (frame.empty()) {
				break;
			}
			//crop frame image
			crop(frame, frame, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd);
			//construct frame
			Frame f(frame);
			//detect and record box heights
			f.detectHeights(frequency);
			//allocate box heights

			//mark progress in loading bar up to 25% 
			frameProgress = (cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 25;
			emit progressUpdate(frameProgress);

		}
		if (!cancelled) {
			getBoxHeights(frequency, singleHeight, doubleHeight);
			//print out the height frequencies
			printFrequencyMap(frequency);

			//reset video
			cap.set(cv::CAP_PROP_POS_FRAMES, 0);
		}
	}
	//challenging contrast at 153k
	//single at 32k
	//double at 12k
	//cap.set(CAP_PROP_POS_MSEC, 180000);
	//cout << cap.get(CAP_PROP_POS_MSEC);
	while (1) {
		//interrupt if cancel clicked
		if (cancelled) {
			break;
		}


		cap >> frame;

		//skip 15 frames (around half a second at 30fps - most subs are up for four, shortest seems to be around one)
		for (int i = 0; i < 15; i++) {
			cap.grab();
		}

		if (frame.empty()) {
			break;
		}
		//crop frame image
		crop(frame, frame, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd);
		//imshow("image", frame);
		//waitKey(0);
		//construct frame object
		Frame f(frame);

		//detect box(es) on the frame and store their y coordinates in heightBoundaries
		f.detectBoxes(singleHeight, doubleHeight, heightBoundaries, dropLength);

		if (autoDetectHeights == true) {
			//mark progress in loading bar up to 25% (50% total)
			frameProgress = ((cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 25 + 25);
			emit progressUpdate(frameProgress);
		}
		else {
			//mark progress in loading bar up to 50%
			frameProgress = (cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 50;
			cout << "FrameProgress: " << frameProgress;
			emit progressUpdate(frameProgress);
		}

	}
	cout << "Done" << endl;
	if (!cancelled) {
		//get most frequent ROI coordinates from heightBoundaries
		getBoxCoordinates(heightBoundaries, ROICoordinates, singleHeight, doubleHeight);

		//reset video
		cap.set(cv::CAP_PROP_POS_FRAMES, 0);
	}

	while (1) {
		try {
			//interrupt if cancel clicked
			if (cancelled) {
				break;
			}

			cap >> frame;


			//skip 15 frames, as seeing more frames increases accuracy of OCR

			for (int i = 0; i < 15; i++) {
				cap.grab();
			}


			if (frame.empty()) {
				break;
			}
			//crop frame image
			crop(frame, frame, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd);
			//imshow("image", frame);
			//waitKey(0);
			//construct frame object
			Frame f(frame);
			//set morphFrame, which will be used for whitespace check
			cv::cvtColor(frame, morphFrame, cv::COLOR_BGR2GRAY);
			//preprocess for whitespace checking
			f.framePreprocessing(morphFrame);
			//how to negotiate multiOCR between different objects? textLineOne etc may need to be part of Video. Or alternatively just part of this method? 
			for (size_t i = 0; i < ROICoordinates.size(); i++) {
				//crop frame height to subtitleBox boundaries for whitespace check
				whiteSpaceCheck = morphFrame.rowRange(ROICoordinates[i].first, ROICoordinates[i].second);
				//imshow("image", whiteSpaceCheck);
				//waitKey(0);
				//if whitespace check passed on area, create a subtitle box and OCR it for text
				if (whitespaceAverageCheck(whiteSpaceCheck, singleHeight, doubleHeight)) {
					//construct subtitleBox
					//need to crop frame before passing it into sub!
					SubtitleBox s(frame, ROICoordinates[i].first, ROICoordinates[i].second);
					//detect text in box
					s.getText(textLineOne, textLineTwo, prevLineOneConfidence, prevLineTwoConfidence, frameTexts, doubleHeight, outputFileName, outTexts, windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence, compareThreshold);
					//break and don't check other location if whitespace average check has been met
					break;
				}
				else {
					//cout << "Whitespace check failed: " << ROICoordinates[i].first << ", " << ROICoordinates[i].second << endl;
				}
			}
		}
		catch (const exception & ex) {
			cout << ex.what();
		}

		//mark progress in progress bar up to 50% (total 100%)
		frameProgress = ((cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 50) + 50;
		emit progressUpdate(frameProgress);
	}
	if (!cancelled) {
		//add in any outputs from the last set of frames
		Output o(outputFileName);
		o.outputFinalLines(textLineOne, textLineTwo);

		//Change | to I and filter various characters in output
		o.letterConverter();

		//Mark doubles
		markPotentialDuplicates(outputFileName, dupeThreshold);
	}
	cout << "ended" << endl;
}


//sorts the Y coordinates in a map of coordinates and returns a vector of pairs
void Video::sortYCoords(map<pair<int, int>, int>& frequency, vector<pair<int, int>>& ROICoordinates)
{
	if (frequency.size() != 0) {
		for (size_t i = 0; i <= frequency.size(); i++) {
			map<pair<int, int>, int>::iterator freqIterator = frequency.begin();
			pair<int, int> mostFrequent = freqIterator->first;
			int frequencyValue = freqIterator->second;

			while (freqIterator != frequency.end()) {
				if (freqIterator->second > frequencyValue) {
					mostFrequent = freqIterator->first;
					frequencyValue = freqIterator->second;
				}

				freqIterator++;

			}
			frequency.erase(mostFrequent);
			ROICoordinates.push_back(mostFrequent);
		}
	}
}

void Video::sortYCoords(map<int, int>& frequency, vector<int>& heights)
{
	if (frequency.size() != 0) {
		for (size_t i = 0; i <= frequency.size(); i++) {
			map<int, int>::iterator freqIterator = frequency.begin();
			int mostFrequent = freqIterator->first;
			int frequencyValue = freqIterator->second;

			while (freqIterator != frequency.end()) {
				if (freqIterator->second > frequencyValue) {
					mostFrequent = freqIterator->first;
					frequencyValue = freqIterator->second;
				}

				freqIterator++;

			}
			frequency.erase(mostFrequent);
			heights.push_back(mostFrequent);
		}
	}
}


//get the Y coordinates of potential single and double subtitle boxes
void Video::getBoxCoordinates(vector<cv::Vec2i> heightBoundaries, vector<pair<int, int>>& ROICoordinates, int singleHeight, int doubleHeight)
{

	map<pair<int, int>, int> frequencySingles;
	map<pair<int, int>, int> frequencyDoubles;
	vector<cv::Vec2i> heightBoundariesSingles;
	vector<cv::Vec2i> heightBoundariesDoubles;

	//split horizontal boundaries into single subs and double subs
	for (size_t i = 0; i < heightBoundaries.size(); i++) {
		if (heightBoundaries[i][1] - heightBoundaries[i][0] == singleHeight) {
			heightBoundariesSingles.push_back(heightBoundaries[i]);
		}
		else if (heightBoundaries[i][1] - heightBoundaries[i][0] == doubleHeight) {
			heightBoundariesDoubles.push_back(heightBoundaries[i]);
		}
		else {
			//error
		}
	}

	//map frequency of double and single sub coords
	frequencySingles = boxCoordinateFrequency(frequencySingles, heightBoundariesSingles);
	frequencyDoubles = boxCoordinateFrequency(frequencyDoubles, heightBoundariesDoubles);



	//print frequency maps
	//cout << "Frequency singles: " << endl;
	printFrequencyMap(frequencySingles);
	//cout << "Frequency doubles: " << endl;
	printFrequencyMap(frequencyDoubles);

	//get most frequent double sub and single sub coords and add to ROICoordinates
	sortYCoords(frequencyDoubles, ROICoordinates);
	sortYCoords(frequencySingles, ROICoordinates);


	for (size_t i = 0; i < ROICoordinates.size(); i++) {
		cout << ROICoordinates[i].first << ", " << ROICoordinates[i].second << endl;
	}

}

//builds a frequency map of the potential subtitle box height coordinates identified when scanning frames
//this can be used to identify the most frequently occurring coordinates to scan using OCR
map<pair<int, int>, int> Video::boxCoordinateFrequency(map<pair<int, int>, int> frequency, vector<cv::Vec2i> horizontalBoundaries)
{
	vector<pair<int, int>> boxCoordinates;
	for (size_t i = 0; i < horizontalBoundaries.size(); i++) {
		pair<int, int> boxCoordinate;
		boxCoordinate = make_pair((int)horizontalBoundaries[i][0], (int)horizontalBoundaries[i][1]);
		boxCoordinates.push_back(boxCoordinate);
	}

	for (size_t i = 0; i < boxCoordinates.size(); i++) {
		//if coords are already in map, increment frequency
		if (frequency.find(boxCoordinates[i]) != frequency.end()) {
			//increment existing frequency
			frequency.find(boxCoordinates[i])->second += 1;
		}
		else {
			//else, add coordinates to the map with frequency 1
			frequency.insert({ boxCoordinates[i], 1 });
		}
	}

	return frequency;
}



//print subtitle box frequency map to console, used for testing
void Video::printFrequencyMap(map<pair<int, int>, int>& frequency)
{
	map<pair<int, int>, int>::iterator freqIterator = frequency.begin();
	while (freqIterator != frequency.end()) {
		cout << freqIterator->first.first << "," << freqIterator->first.second << " : " << freqIterator->second << endl;
		freqIterator++;
	}

}

void Video::printFrequencyMap(map<int, int>& frequency)
{
	cout << "Height Frequencies begin: " << endl;
	map<int, int>::iterator freqIterator = frequency.begin();
	while (freqIterator != frequency.end()) {
		cout << freqIterator->first << " : " << freqIterator->second << endl;
		freqIterator++;
	}
	cout << "Height Frequencies end: " << endl;
}

bool Video::whitespaceAverageCheck(cv::Mat image, int singleHeight, int doubleHeight)
{

	int whitespace = countNonZero(image);
	int totalPixels = image.cols * image.rows;
	vector<cv::Mat> ROIhalves;
	float averageWhitespace = (float)whitespace / (float)totalPixels;
	//if the image is the size of a double subtitle box, return true if top and bottom halves both meet whitespace threshold
	if (image.rows == doubleHeight) {
		//make image into a subtitle box
		SubtitleBox s(image, 0, image.rows);
		//split the box
		s.splitBox(image, ROIhalves, doubleHeight);
		//analyse the whitespace in the box halves
		int whiteSpaceTop = countNonZero(ROIhalves[0]);
		int totalPixelsTop = ROIhalves[0].cols * ROIhalves[0].rows;
		float averageWhiteSpaceTop = (float)whiteSpaceTop / (float)totalPixelsTop;



		//cout << "checking as double" << endl;
		//cout << "whitespace top: " << averageWhiteSpaceTop << endl;
		//cout << "average whitespace bottom: " << whiteSpaceBottomLineCheck(ROIhalves[1], 50) << endl;

		//as the bottom subtitle line is often in different positions, run a 30px sliding window over the area and check for whitespace concentration of 60%
		//if an area is returned by widthCutterLeft, then an area has been detected
		if (averageWhiteSpaceTop > 0.4 && whiteSpaceBottomLineCheck(ROIhalves[1], 50)) {
			return true;
		}
		else {
			return false;
		}

	}
	else if (image.rows == singleHeight) {
		//single line subtitles tend to be shorter in length than double line subs, so reduce width of image before checking the whitespace average
		image = image.colRange(0, (image.cols / 2));
		whitespace = countNonZero(image);
		totalPixels = image.cols * image.rows;
		averageWhitespace = (float)whitespace / (float)totalPixels;

		//cout << "checking as single" << endl;
		//cout << "whitespace: " << averageWhitespace << endl;

		if (averageWhitespace > 0.4) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Video::whiteSpaceBottomLineCheck(cv::Mat image, int windowSize)
{
	int start = 0;
	int pixelCount;
	int whiteCount;
	int blackCount;
	float averageBlack;
	float averageWhite;
	vector<int> sliceAt;
	for (int slices = 0; slices < (image.cols - windowSize); slices++) {
		cv::Mat slice = image.colRange(start, start + windowSize);
		pixelCount = slice.cols * slice.rows;
		whiteCount = countNonZero(slice);
		blackCount = pixelCount - whiteCount;
		averageBlack = (float)blackCount / pixelCount;
		averageWhite = (float)whiteCount / pixelCount;
		if (averageWhite >= 0.85) {
			return true;
		}
		start += 1;
	}

	return false;
}

void Video::crop(cv::Mat image, cv::Mat& dst, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd)
{
	cv::Mat interimFrame = image.rowRange(cropHeightStart, cropHeightEnd);
	interimFrame = interimFrame.colRange(cropWidthStart, cropWidthEnd);
	dst = interimFrame.clone();
}

void Video::getBoxHeights(map<int, int> frequency, int& singleHeight, int& doubleHeight)
{
	vector<int> heights;
	map<int, int> frequencySort = frequency;
	map<int, int> frequencySecondHeightPossibles;
	int firstHeight;
	int secondHeight;

	//get most frequently occurring height and set to firstHeight
	sortYCoords(frequencySort, heights);
	firstHeight = heights[0];
	heights.clear();
	//make a map of values that are around half or double firstHeight
	std::map<int, int>::iterator freqIt = frequency.begin();
	int halfFirst = firstHeight / 2;
	int doubleFirst = firstHeight * 2;
	while (freqIt != frequency.end()) {
		//add entries that are around half of the most frequent height
		if (freqIt->first == halfFirst || freqIt->first == halfFirst + 1 || freqIt->first == halfFirst - 1) {
			frequencySecondHeightPossibles.emplace(freqIt->first, freqIt->second);
		} //add entries that are around double the most frequent height
		else if (freqIt->first == firstHeight * 2 || freqIt->first == (firstHeight + 1) * 2 || freqIt->first == (firstHeight - 1) * 2) {
			frequencySecondHeightPossibles.emplace(freqIt->first, freqIt->second);
		}
		freqIt++;
	}

	//set secondHeight to the most frequent of the values in the second map
	sortYCoords(frequencySecondHeightPossibles, heights);
	cout << "secondHeights: " << endl;
	for (size_t i = 0; i < heights.size(); i++) {
		cout << heights[i] << endl;
	}
	secondHeight = heights[0];

	cout << "firstHeight: " << firstHeight << endl;
	cout << "secondHeight: " << secondHeight << endl;

	//set singleHeight to the lower value and doubleHeight to the higher value
	if (secondHeight > firstHeight) {
		doubleHeight = secondHeight;
		singleHeight = firstHeight;
	}
	else {
		doubleHeight = firstHeight;
		singleHeight = secondHeight;
	}

}

void Video::markPotentialDuplicates(string outputFileName, int dupeThreshold)
{
	ifstream outputFile(outputFileName);
	ofstream output;
	string line;
	string prevLine;
	string interim;
	int matches = 0;
	int locationCheck = 0;
	int shorterLength;


	while (getline(outputFile, line)) {
		bool flag = false;
		cout << "entered" << endl;
		//first pass - append first line and store following line for future comparisons
		if (prevLine.empty()) {
			getline(outputFile, prevLine);
			interim.append(line);
			if (line[line.length() - 1] != ' ') {
				interim.append(" ");
			}
			interim.append(prevLine);
			if (prevLine[prevLine.length() - 1] != ' ') {
				interim.append(" ");
			}
			line.clear();
		}
		else {
			cout << "PrevLine: " << prevLine << endl;
			cout << "Line: " << line << endl;

			//count the number of consecutive matches at the end of prevLine and beginning of line
			if (line != " ") {
				//need to establish that this match can only be at the end of prevLine/beginning of line
				cout << "match check" << endl;
				string substring = line.substr(0, 1);
				while (prevLine.find(substring) != string::npos) {
					matches++;
					substring = line.substr(0, matches);
				}
			}
			//remove one from matches, as the while loop will increment it once more than the number
			//of matching characters before breaking
			if (matches != 0) {
				matches--;
			}

			cout << "Matches: " << matches << endl;
			cout << endl;
			//supposed to compare a match-length end slice of previous line with the beginning of line, but doesn't work?
			if (matches > 0) {
				for (size_t i = 0; i < matches; i++) {
					if (line[i] == prevLine[((prevLine.length()) - matches) + i]) {
						cout << "Line: " << line[i] << endl;
						cout << "Prevline: " << prevLine[((prevLine.length()) - matches) + i] << endl;
						locationCheck += 1;
					}
				}
				cout << "LocationCheck: " << locationCheck << endl;

				if (matches == locationCheck) {
					flag = true;
				}
			}

			//if number of matches equals the duplicate threshold, mark the duplicate in the text
			if (matches > dupeThreshold && flag) {
				cout << "match mark" << endl;
				//delete old prevLine
				for (size_t i = 0; i < prevLine.length(); i++) {
					interim.pop_back();
				}

				std::string::iterator it = (prevLine.end() - matches);
				prevLine.insert(it, '[');
				it = prevLine.end();
				prevLine.insert(it, ',');
				it = (line.begin() + matches);
				line.insert(it, ']');

				interim.append(prevLine);
				if (prevLine[prevLine.length() - 1] != ' ') {
					interim.append(" ");
				}
				interim.append(line);
				if (line[line.length() - 1] != ' ') {
					interim.append(" ");
				}
				prevLine = line;
			}
			else {
				cout << "no match" << endl;
				interim.append(line);
				if (line[line.length() - 1] != ' ') {
					interim.append(" ");
				}
				prevLine = line;
			}
		}
		matches = 0;
		locationCheck = 0;
	}
	cout << "output" << endl;
	output.open(outputFileName, ofstream::trunc);
	output << interim;
	output.close();

}

void Video::on_cancelButton_clicked()
{
	cancelled = true;
}



