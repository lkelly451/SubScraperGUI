#pragma once
#include <opencv2/highgui.hpp>
#include <iostream>
#include <map>
#include "Frame.h"
#include "SubtitleBox.h"
#include "Output.h"
#include <QtWidgets\QWidget>
#include <QtWidgets\qprogressbar.h>
#include <QtWidgets\qpushbutton.h>

class Video
{
private:
	cv::VideoCapture cap;
public:
	Video(cv::VideoCapture cap, int singleHeight, int doubleHeight);
	~Video();
	int getSubtitles(int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, std::string outputFileName, int dropLength, int singleHeight, int doubleHeight, int windowSizeLeft, int windowSizeRight, bool autoDetectHeights, int wordConfidence, int lineConfidence, double compareThreshold, int dupeThreshold, QProgressBar* progressBar, QPushButton* cancelButton);
	void sortYCoords(std::map<std::pair<int, int>, int>& frequency, std::vector<std::pair<int, int>>& ROICoordinates);
	void sortYCoords(std::map<int, int>& frequency, std::vector<int>& heights);
	void getBoxCoordinates(std::vector<cv::Vec2i> heightBoundaries, std::vector<std::pair<int, int>>& ROICoordinates, int singleHeight, int doubleHeight);
	std::map<std::pair<int, int>, int> boxCoordinateFrequency(std::map<std::pair<int, int>, int> frequency, std::vector<cv::Vec2i> horizontalBoundaries);
	void printFrequencyMap(std::map<std::pair<int, int>, int>& frequency);
	void printFrequencyMap(std::map<int, int>& frequency);
	bool whitespaceAverageCheck(cv::Mat image, int singleHeight, int doubleHeight);
	bool whiteSpaceBottomLineCheck(cv::Mat image, int windowSize);
	void crop(cv::Mat image, cv::Mat& dst, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd);
	void getBoxHeights(std::map<int, int> frequency, int& singleHeight, int& doubleHeight);
	void markPotentialDuplicates(std::string outputFileName, int dupeThreshold);
};

