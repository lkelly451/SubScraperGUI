#include "Video.h"



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

//gets subtitles from video and outputs to text file
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
		cancelled = true;
		emit error(QString::fromStdString("Could not open video file, please check that file path and file type are correct. For accepted file types, see the 'Help' menu. This video will be skipped."));
	}

	if (wordConfidence < 0 || wordConfidence > 100) {
		cancelled = true;
		emit error(QString("The word confidence value is not set between 0 and 100. Please try a different profile, or use build profile to build a new one with a valid word confidence value. This video will be skipped."));
	}

	if (lineConfidence < 0 || lineConfidence > 100) {
		cancelled = true;
		emit error(QString("The line confidence value is not set between 0 and 100. Please try a different profile, or use build profile to build a new one with a valid line confidence value. This video will be skipped."));
	}

	if (compareThreshold < 0.0 || compareThreshold > 1.0) {
		cancelled = true;
		emit error(QString("The output comparison threshold is not set between 0.0 and 1.0. Please try a different profile, or use build profile to build a new one with a valid output comparison threshold. This video will be skipped."));
	}


	
	//Auto detect subtitle heights
	if (autoDetectHeights) {
		while (1) {
			//cancel the function if cancel button is checked
			if (cancelled) {
				break;
			}

			cap >> frame;

			if (cropHeightStart <= frame.rows || cropHeightEnd <= frame.rows || cropWidthStart <= frame.cols || cropWidthEnd <= frame.cols) {
				cancelled = true;
				emit error(QString("The profile crop parameters are outside the range of this video. Please try a different profile, or use build profile to build a new one with a smaller cropped area. This video will be skipped."));
			}
			if (singleHeight > frame.rows || doubleHeight > frame.rows) {
				cancelled = true;
				emit error(QString("The subtitle height parameters are outside the range of this video. Please try a different profile, or use build profile to build a new one with smaller height parameters. This video will be skipped."));
			}
			if (dropLength > frame.cols) {
				cancelled = true;
				emit error(QString("The box length filter threshold is wider than the video frames. Please try a different profile, or use build profile to build a new one with a lower threshold. This video will be skipped."));
			}
			if (windowSizeLeft > frame.cols) {
				cancelled = true;
				emit error(QString("The left sliding window is wider than the video frames. Please try a different profile, or use build profile to build a new one with a smaller sliding window value. This video will be skipped."));
			}
			if (windowSizeRight > frame.cols) {
				cancelled = true;
				emit error(QString("The right sliding window is wider than the video frames. Please try a different profile, or use build profile to build a new one with a smaller sliding window value. This video will be skipped."));
			}

			//skip 15 frames
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

			//mark progress in loading bar up to 25% 
			frameProgress = (cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 25;

			//update progress bar
			emit progressUpdate(frameProgress);
			emit currentStep(QString::fromStdString("Detecting heights..."));

		}
		if (!cancelled) {
			//get most frequent box heights and use to set singleHeight and doubleHeight
			getBoxHeights(frequency, singleHeight, doubleHeight);
			
			//reset video
			cap.set(cv::CAP_PROP_POS_FRAMES, 0);
		}
	}
	//pass through video and get y coordinates of areas that fit the subtitle heights, then rank by frequency
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

		//construct frame object
		Frame f(frame);

		//detect box(es) on the frame and store their y coordinates in heightBoundaries
		f.detectBoxes(singleHeight, doubleHeight, heightBoundaries, dropLength);

		if (autoDetectHeights == true) {
			//mark progress in loading bar up to 25% (50% total)
			frameProgress = ((cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 25 + 25);

			emit progressUpdate(frameProgress);
			emit currentStep(QString::fromStdString("Detecting subtitle boxes..."));
		}
		else {
			//mark progress in loading bar up to 50%
			frameProgress = (cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 50;

			emit progressUpdate(frameProgress);
			emit currentStep(QString::fromStdString("Detecting subtitle boxes..."));
		}

	}
	if (!cancelled) {
		//get most frequent ROI coordinates from heightBoundaries
		getBoxCoordinates(heightBoundaries, ROICoordinates, singleHeight, doubleHeight);

		//reset video
		cap.set(cv::CAP_PROP_POS_FRAMES, 0);
	}
	//Check each frame at identified coordinates and OCR if whitespace check suggests there may be a subtitle box there
	while (1) {
		try {
			//interrupt if cancel clicked
			if (cancelled) {
				break;
			}

			cap >> frame;

			//skip 15 frames
			for (int i = 0; i < 15; i++) {
				cap.grab();
			}

			if (frame.empty()) {
				break;
			}
			//crop frame image
			crop(frame, frame, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd);

			//construct frame object
			Frame f(frame);

			//set morphFrame, which will be used for whitespace check
			cv::cvtColor(frame, morphFrame, cv::COLOR_BGR2GRAY);

			//preprocess for whitespace checking
			f.framePreprocessing(morphFrame);
 
			for (size_t i = 0; i < ROICoordinates.size(); i++) {
				//crop frame height to subtitleBox boundaries for whitespace check
				whiteSpaceCheck = morphFrame.rowRange(ROICoordinates[i].first, ROICoordinates[i].second);

				//if whitespace check passed on area, create a subtitle box and OCR it for text
				if (subtitleBoxCheck(whiteSpaceCheck, singleHeight, doubleHeight)) {
					//construct subtitleBox
					SubtitleBox s(frame, ROICoordinates[i].first, ROICoordinates[i].second);

					//detect text in box
					s.getText(textLineOne, textLineTwo, prevLineOneConfidence, prevLineTwoConfidence, frameTexts, doubleHeight, outputFileName, outTexts, windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence, compareThreshold);

					//break and don't check other location if whitespace average check has been met
					break;
				}
			}
		}
		catch (const exception & ex) {
			cout << ex.what();
		}

		//mark progress in progress bar up to 50% (total 100%)
		frameProgress = ((cap.get(CAP_PROP_POS_FRAMES) / cap.get(CAP_PROP_FRAME_COUNT)) * 50) + 50;
		emit progressUpdate(frameProgress);
		emit currentStep(QString::fromStdString("Reading text..."));
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
	else {
		//if cancel has left a temp file behind, delete it
		string provisionalFileName = outputFileName + "prov";
		remove(provisionalFileName.c_str());
	}
	//release the VideoCapture object
	cap.release();
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
//sorts the Y coordinates in a map of coordinates and returns a vector of ints (used for automatic height detection functionality)
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


//gets the Y coordinates of potential single and double subtitle boxes
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

	//get most frequent double sub and single sub coords and add to ROICoordinates
	sortYCoords(frequencyDoubles, ROICoordinates);
	sortYCoords(frequencySingles, ROICoordinates);


	for (size_t i = 0; i < ROICoordinates.size(); i++) {
		cout << ROICoordinates[i].first << ", " << ROICoordinates[i].second << endl;
	}

}

//builds a frequency map of the potential subtitle box height coordinates identified when scanning frames \
  this can be used to identify the most frequently occurring coordinates to scan using OCR
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
//checks if a frame has a subtitle box on it
bool Video::subtitleBoxCheck(cv::Mat image, int singleHeight, int doubleHeight)
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

		//get the whitespace in the box halves
		int whiteSpaceTop = countNonZero(ROIhalves[0]);
		int totalPixelsTop = ROIhalves[0].cols * ROIhalves[0].rows;
		float averageWhiteSpaceTop = (float)whiteSpaceTop / (float)totalPixelsTop;

		//as the bottom subtitle line is often in different positions, run a 30px sliding window over the area and check for whitespace concentration of 85% \
		(higher concentration is due to the much smaller area checked)
		if (averageWhiteSpaceTop > 0.4 && subtitleBoxBottomLineCheck(ROIhalves[1], 50)) {
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
//Supporting method for whitespaceAverageCheck. Compensates for varying alignments of bottom lines in double-line subtitles
bool Video::subtitleBoxBottomLineCheck(cv::Mat image, int windowSize)
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

//crops frames to subtitle area
void Video::crop(cv::Mat image, cv::Mat& dst, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd)
{
	if (cropHeightStart <= image.rows && cropHeightEnd <= image.rows && cropWidthStart <= image.cols && cropWidthEnd <= image.cols) {
		cv::Mat interimFrame = image.rowRange(cropHeightStart, cropHeightEnd);
		interimFrame = interimFrame.colRange(cropWidthStart, cropWidthEnd);
		dst = interimFrame.clone();
	}
	else {
		cancelled = true;
		emit error(QString("The profile crop parameters are outside the range of this video. Please try a different profile, or use build profile to build a new one. This video will be skipped."));
	}
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
	for (size_t i = 0; i < heights.size(); i++) {
		cout << heights[i] << endl;
	}
	secondHeight = heights[0];

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
//marks potential duplicate text in output in style "[instance1, instance2]"
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
			//count the number of consecutive matches at the end of prevLine and beginning of line
			if (line != " ") {
				//iterate through line, checking if the previous line contains each character
				string substring = line.substr(0, 1);
				while (prevLine.find(substring) != string::npos) {
					//increment matches for each character shared between the two
					matches++;
					if (matches > (line.length()) || matches > (prevLine.length())) {
						break;
					}
					substring = line.substr(0, matches);
				}
			}
			//remove one from matches, as the while loop will increment it once more than the number \
			  of matching characters before breaking
			if (matches != 0) {
				matches--;
			}
			//compare a match-length end slice of previous line with the beginning of line
			if (matches > 0) {
				for (size_t i = 0; i < matches; i++) {
					if (line[i] == prevLine[((prevLine.length()) - matches) + i]) {
						locationCheck += 1;
					}
				}
				if (matches == locationCheck) {
					flag = true;
				}
			}

			//if number of matches equals the duplicate threshold, mark the duplicate in the text
			if (matches > dupeThreshold && flag) {
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


