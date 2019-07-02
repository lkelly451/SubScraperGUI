#include "SubScraper.h"
#include <opencv2/videoio.hpp>
#include "Video.h"


SubScraper::SubScraper()
{
}


SubScraper::~SubScraper()
{
}

void SubScraper::getSubs(std::string inputFileName, std::string outputFileName, std::string transcriptFileDirectory, int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, int windowSizeRight, int wordConfidence, int lineConfidence, double compareThreshold, int dupeThreshold, bool autoDetectHeights)
{
	cv::VideoCapture cap(inputFileName);
	Video v(cap, singleHeight, doubleHeight);
	v.getSubtitles(cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, outputFileName, transcriptFileDirectory, dropLength, singleHeight, doubleHeight, windowSizeLeft, windowSizeRight, autoDetectHeights, wordConfidence, lineConfidence, compareThreshold, dupeThreshold);
}
