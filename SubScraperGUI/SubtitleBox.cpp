#include "SubtitleBox.h"


using namespace std;
using namespace cv;

SubtitleBox::SubtitleBox(cv::Mat frame, int heightStart, int heightEnd)
{
	//clone here to prevent original frame from being overwritten
	cv::Mat interimFrame = frame.clone();
	//convert to grayscale to facilitate OCR
	if (interimFrame.channels() > 1) {
		cv::cvtColor(interimFrame, interimFrame, cv::COLOR_BGR2GRAY);
	}
	//set height of subtitle box to boundaries identified during box scan
	interimFrame = interimFrame.rowRange(heightStart, heightEnd);

	this->Box = interimFrame;
}

SubtitleBox::~SubtitleBox()
{
}

void SubtitleBox::getText(string& textLineOne, string& textLineTwo, int& prevLineOneConfidence, int& prevLineTwoConfidence, vector<string> frameTexts, int doubleHeight, string outputFileName, string outTexts[2], int windowSizeLeft, int windowSizeRight, int wordConfidence, int lineConfidence, double compareThreshold)
{

	//split ROI 
	splitBox(Box, SubtitleBoxLines, doubleHeight);

	//reduce width
	reduceWidth(SubtitleBoxLines, windowSizeLeft, windowSizeRight);

	//add borders to images to improve OCR
	addBorders(SubtitleBoxLines);

	//multithread OCR
	multiOCR(SubtitleBoxLines, textLineOne, textLineTwo, frameTexts, prevLineOneConfidence, prevLineTwoConfidence, wordConfidence, lineConfidence, compareThreshold);

	//filter out duplicate text outputs from previous frames and output result
	Output o(outputFileName);
	o.multiOutputResults(frameTexts, outTexts, outputFileName);

}

void SubtitleBox::splitBox(cv::Mat box, vector<cv::Mat>& dst, int doubleHeight)
{
	//split the image if it is the size of a double line subtitle box or bigger
	if (box.rows >= doubleHeight) {
		//split off top line of subtitle box and add to vector of Mats
		cv::Mat BoxTop = box.rowRange(0, (box.rows / 2) + 3);
		//clone to prevent ROI referring back to same memory location as img
		cv::Mat boxHalf;
		boxHalf = BoxTop.clone();
		dst.push_back(boxHalf);
		//split off bottom line of subtitle box and add to vector of Mats
		cv::Mat boxBottom = box.rowRange((box.rows / 2) + 3, box.rows);
		boxHalf = boxBottom.clone();
		dst.push_back(boxHalf);

	}
	else {
		//add whole image to vector of Mats if it is smaller than a double line subtitle box
		dst.push_back(box);
	}
}

void SubtitleBox::ocr(cv::Mat image, std::string & frameText, int& confidence, int wordConfidence, int lineConfidence)
{
	//create tesseract object
	tesseract::TessBaseAPI* ocr = new tesseract::TessBaseAPI();
	//initialise tesseract to use English and the default ocr engine
	ocr->Init(NULL, "eng", tesseract::OEM_DEFAULT);
	//Set page segmentation mode to auto
	ocr->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
	//set image data
	ocr->SetImage(image.data, image.cols, image.rows, 1, (int)image.step);

	ocr->Recognize(0);
	//create iterator to iterate through word confidence scores
	tesseract::ResultIterator* ri = ocr->GetIterator();
	tesseract::ResultIterator* ri2 = ocr->GetIterator();
	tesseract::PageIteratorLevel wordLevel = tesseract::RIL_WORD;
	tesseract::PageIteratorLevel lineLevel = tesseract::RIL_BLOCK;
	//get words and confidence levels	
	if (ri2 != 0) {
		//store line level confidence
		confidence = ri2->Confidence(lineLevel);
		if (ri != 0) {
			frameText.clear();
			do {
				//only continue if confidence for the entire output averages over 70
				if (ri->Confidence(wordLevel) > wordConfidence && confidence > lineConfidence) {
					//print word to console if confidence level is higher than 80
					frameText.append(ri->GetUTF8Text(wordLevel));
					frameText.append(" ");
				}
			} while (ri->Next(wordLevel));
		}
	} while (ri2->Next(lineLevel))
		ocr->End();
	ocr->End();
}

void SubtitleBox::addBorders(vector<cv::Mat> & SubtitleBoxLines)
{
	//loop through the ROI areas
	for (size_t i = 0; i < SubtitleBoxLines.size(); i++) {

		//add a border to the ROI to further facilitate OCR
		copyMakeBorder(SubtitleBoxLines[i], SubtitleBoxLines[i], 5, 5, 5, 5, cv::BORDER_CONSTANT, 0);
		copyMakeBorder(SubtitleBoxLines[i], SubtitleBoxLines[i], 15, 15, 15, 15, cv::BORDER_CONSTANT, 255);

	}
}

void SubtitleBox::multiOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, string & textLineTwo, vector<string> & frameTexts, int& prevLineOneConfidence, int& prevLineTwoConfidence, int wordConfidence, int lineConfidence, double compareThreshold)
{
	string readTextLineOne;
	string readTextLineTwo;
	double JWdistance;
	double JWdistance2;
	int lineOneConfidence;
	int lineTwoConfidence;

	//OCR the subtitle line(s) and add them to a vector of strings
	//Multithread and wait for completion before adding output to frameTexts
	if (SubtitleBoxLines.size() > 1) {
		//if textLineOne and textLineTwo vars are empty (i.e. at first pass)
		if (textLineOne.empty() && textLineTwo.empty()) {
			doubleFirstPassOCR(SubtitleBoxLines, textLineOne, textLineTwo, prevLineOneConfidence, prevLineTwoConfidence, wordConfidence, lineConfidence);
		}
		//when moving from a single line read to a double line read, print out the single line read and then fill in the string
		//vars with the new double line read to prevent the single line and the second double line getting mixed up
		else if (!textLineOne.empty() && textLineTwo.empty()) {
			singleToDoubleOCR(SubtitleBoxLines, textLineOne, textLineTwo, readTextLineOne, readTextLineTwo, lineOneConfidence, lineTwoConfidence, prevLineOneConfidence, prevLineTwoConfidence, frameTexts, wordConfidence, lineConfidence);
		}
		//after first pass, compare with previous OCR
		//if the two are similar, take the longer one
		//if both are not, then put the existing string vars into frameText for output
		//then overwrite the string vars with the new lines for upcoming comparison
		else {
			doubleToDoubleOCR(SubtitleBoxLines, textLineOne, textLineTwo, readTextLineOne, readTextLineTwo, lineOneConfidence, lineTwoConfidence, prevLineOneConfidence, prevLineTwoConfidence, frameTexts, wordConfidence, lineConfidence, compareThreshold);
		}
	}
	else {
		//if switching from a two line read to a single line read, output strings, 
		//clear them both, then read in the new single text line
		if (!textLineOne.empty() && !textLineTwo.empty()) {
			doubleToSingleOCR(SubtitleBoxLines, textLineOne, textLineTwo, lineOneConfidence, prevLineOneConfidence, prevLineTwoConfidence, frameTexts, wordConfidence, lineConfidence);
		}
		else {
			//if only one ROI in ROIhalves and textLineOne var is empty (i.e. at first pass)
			if (textLineOne.empty()) {
				singleFirstPassOCR(SubtitleBoxLines, textLineOne, lineOneConfidence, prevLineOneConfidence, wordConfidence, lineConfidence);
			}
			//if there is previous output stored for this line
			else {
				singleToSingleOCR(SubtitleBoxLines, readTextLineOne, textLineOne, lineOneConfidence, prevLineOneConfidence, frameTexts, wordConfidence, lineConfidence, compareThreshold);
			}
		}
	}
	//clear the ROI halves for the next frame
	SubtitleBoxLines.clear();
}
//trim right side of image to improve OCR accuracy
int SubtitleBox::widthCutterRight(cv::Mat image, int sliceWidth)
{
	int start = 0;
	int pixelCount;
	int whiteCount;
	int blackCount;
	float averageBlack;
	float averageWhite;
	vector<int> sliceAt;
	for (int slices = 0; slices < (image.cols - sliceWidth); slices++) {
		cv::Mat slice = image.colRange(start, start + sliceWidth);
		pixelCount = slice.cols * slice.rows;
		whiteCount = countNonZero(slice);
		blackCount = pixelCount - whiteCount;
		averageBlack = (float)blackCount / pixelCount;
		averageWhite = (float)whiteCount / pixelCount;

		if (averageWhite >= 0.80) {
			sliceAt.push_back(start + sliceWidth);
		}

		start += 1;


	}
	//return rightmost identified white zone as a cutoff point
	if (!sliceAt.empty()) {
		//allow a three pixel leeway to prevent letters being cut off, if possible
		if ((sliceAt[sliceAt.size() - 1]) + 3 <= image.cols) {
			return sliceAt[sliceAt.size() - 1];
		}
		else {
			return sliceAt[sliceAt.size() - 1];
		}
	}
	//if none were identified, return the length of the whole image
	else {
		return image.cols;
	}
}
//trim left side of image to improve OCR accuracy
int SubtitleBox::widthCutterLeft(cv::Mat image, int sliceWidth)
{
	int start = 0;
	int pixelCount;
	int whiteCount;
	int blackCount;
	float averageBlack;
	float averageWhite;
	vector<int> sliceAt;
	//return zero if no window is used
	if (sliceWidth == 0) {
		return 0;
	}
	for (int slices = 0; slices < (image.cols - sliceWidth); slices++) {
		cv::Mat slice = image.colRange(start, start + sliceWidth);
		pixelCount = slice.cols * slice.rows;
		whiteCount = countNonZero(slice);
		blackCount = pixelCount - whiteCount;
		averageBlack = (float)blackCount / pixelCount;
		averageWhite = (float)whiteCount / pixelCount;

		if (averageWhite >= 0.60) {
			sliceAt.push_back(start);
		}

		start += 1;
	}
	//return leftmost identified white zone
	if (!sliceAt.empty()) {
		return sliceAt[0];
	}
	//if none were identified, return 0
	else {
		return 0;
	}
}

void SubtitleBox::boxPreprocessing(cv::Mat image, cv::Mat & dst)
{
	//adaptive thresholding
	adaptiveThreshold(image, dst, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY_INV, 35, 20);
	//erodes and then dilates the image using the kernel to remove spots within objects
	//in this case, eliminates text from the subtitles box
	cv::Mat kernel(7, 7, CV_32F, cv::Scalar(1));
	morphologyEx(dst, dst, cv::MORPH_CLOSE, kernel);
}

void SubtitleBox::reduceWidth(vector<cv::Mat> & SubtitleBoxLines, int windowSizeLeft, int windowSizeRight)
{
	cv::Mat morph;
	for (size_t i = 0; i < SubtitleBoxLines.size(); i++) {
		//process image to break into whitespace and blackspace
		boxPreprocessing(SubtitleBoxLines[i], morph);
		//reduce ROIhalves width based on where whitespace is cut off in preprocessed image
		SubtitleBoxLines[i] = SubtitleBoxLines[i].colRange(widthCutterLeft(morph, windowSizeLeft), widthCutterRight(morph, windowSizeRight));
		SubtitleBoxLines[i] = SubtitleBoxLines[i].clone();
	}
}

void SubtitleBox::doubleFirstPassOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, string & textLineTwo, int& prevLineOneConfidence, int& prevLineTwoConfidence, int wordConfidence, int lineConfidence)
{
	thread t1(ocr, SubtitleBoxLines[0], ref(textLineOne), ref(prevLineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	thread t2(ocr, SubtitleBoxLines[1], ref(textLineTwo), ref(prevLineTwoConfidence), ref(wordConfidence), ref(lineConfidence));

	t1.join();
	t2.join();
}

void SubtitleBox::singleToDoubleOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, string & textLineTwo, string & readTextLineOne, string & readTextLineTwo, int& lineOneConfidence, int& lineTwoConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, vector<string> & frameTexts, int wordConfidence, int lineConfidence)
{
	frameTexts.push_back(textLineOne);

	thread t1(ocr, SubtitleBoxLines[0], ref(readTextLineOne), ref(lineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	thread t2(ocr, SubtitleBoxLines[1], ref(readTextLineTwo), ref(lineTwoConfidence), ref(wordConfidence), ref(lineConfidence));

	t1.join();
	t2.join();

	textLineOne = readTextLineOne;
	prevLineOneConfidence = lineOneConfidence;

	textLineTwo = readTextLineTwo;
	prevLineTwoConfidence = lineTwoConfidence;
}

void SubtitleBox::doubleToDoubleOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, string & textLineTwo, string & readTextLineOne, string & readTextLineTwo, int& lineOneConfidence, int& lineTwoConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, vector<string> & frameTexts, int wordConfidence, int lineConfidence, double compareThreshold)
{
	StringComparer stringComparer;
	double JWdistance;
	double JWdistance2;

	thread t1(ocr, SubtitleBoxLines[0], ref(readTextLineOne), ref(lineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	thread t2(ocr, SubtitleBoxLines[1], ref(readTextLineTwo), ref(lineTwoConfidence), ref(wordConfidence), ref(lineConfidence));

	t1.join();
	t2.join();

	JWdistance = stringComparer.jaroWinklerDistance(readTextLineOne, textLineOne);
	JWdistance2 = stringComparer.jaroWinklerDistance(readTextLineTwo, textLineTwo);

	if (readTextLineOne.empty() && readTextLineTwo.empty()) {
		//if both lines read in are empty, keep previous stored text so that the system does not treat the next read as a first-time input
	}
	else {

		//if line one texts are similar (or the stored text is empty), take the one with a higher confidence level
		if (JWdistance >= compareThreshold || textLineOne.empty()) {
			if (lineOneConfidence >= prevLineOneConfidence) {
				textLineOne = readTextLineOne;
				prevLineOneConfidence = lineOneConfidence;

			}
		}
		//if line two texts are similar (or the stored text is empty), take the one with a higher confidence level
		if (JWdistance2 >= compareThreshold || textLineTwo.empty()) {
			if (lineTwoConfidence >= prevLineTwoConfidence) {
				textLineTwo = readTextLineTwo;
				prevLineTwoConfidence = lineTwoConfidence;
			}
		}
		//if both new lines are dissimilar to the previously scanned ones, then
		//output the old lines to be written to text file and put the new text lines
		//in the textline strings for future comparisons
		if (JWdistance < compareThreshold && JWdistance2 < compareThreshold) {
			frameTexts.push_back(textLineOne);
			frameTexts.push_back(textLineTwo);

			textLineOne = readTextLineOne;
			textLineTwo = readTextLineTwo;

			prevLineOneConfidence = lineOneConfidence;
			prevLineTwoConfidence = lineTwoConfidence;
		}
	}
}

void SubtitleBox::singleFirstPassOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, int& lineOneConfidence, int& prevLineOneConfidence, int wordConfidence, int lineConfidence)
{
	thread t1(ocr, SubtitleBoxLines[0], ref(textLineOne), ref(lineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	t1.join();
	prevLineOneConfidence = lineOneConfidence;
}

void SubtitleBox::doubleToSingleOCR(vector<cv::Mat> & SubtitleBoxLines, string & textLineOne, string & textLineTwo, int& lineOneConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, vector<string> & frameTexts, int wordConfidence, int lineConfidence)
{
	frameTexts.push_back(textLineOne);
	frameTexts.push_back(textLineTwo);

	textLineOne.clear();
	textLineTwo.clear();

	thread t1(ocr, SubtitleBoxLines[0], ref(textLineOne), ref(lineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	t1.join();
	prevLineOneConfidence = lineOneConfidence;
	prevLineTwoConfidence = 0;
}

void SubtitleBox::singleToSingleOCR(vector<cv::Mat> & SubtitleBoxLines, string & readTextLineOne, string & textLineOne, int& lineOneConfidence, int& prevLineOneConfidence, vector<string> & frameTexts, int wordConfidence, int lineConfidence, double compareThreshold)
{
	StringComparer stringComparer;

	thread t1(ocr, SubtitleBoxLines[0], ref(readTextLineOne), ref(lineOneConfidence), ref(wordConfidence), ref(lineConfidence));
	t1.join();

	int JWdistance = stringComparer.jaroWinklerDistance(readTextLineOne, textLineOne);

	if (!readTextLineOne.empty()) {
		//if the text read in is empty, retain the previously stored text to prevent the next read input from being treated as a first-ever read
	}
	else {
		//if line one texts are similar, take the one with a higher confidence level
		if (JWdistance > compareThreshold) {
			if (lineOneConfidence >= prevLineOneConfidence) {
				textLineOne = readTextLineOne;
			}
		}

		//if the new line is dissimilar to the previously stored one, then
		//output the old lines to be written to text file and put the new text lines
		//in the textline strings for future comparisons
		else {
			frameTexts.push_back(textLineOne);
			textLineOne = readTextLineOne;
		}
	}
}
