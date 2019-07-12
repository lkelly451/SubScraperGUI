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
#include <qthread.h>
#include <QtWidgets\qlabel.h>

class Video: public QThread
{
	Q_OBJECT
private:
	std::string outputFileName;
	std::string inputFileName;
	int cropHeightStart; 
	int cropHeightEnd;
	int cropWidthStart;
	int cropWidthEnd;
	int dropLength;
	int singleHeight;
	int doubleHeight;
	int windowSizeLeft;
	int windowSizeRight;
	bool autoDetectHeights;
	int wordConfidence; 
	int lineConfidence; 
	double compareThreshold;
	int dupeThreshold; 
	bool cancelled = false;

signals:
	void progressUpdate(int progress);
	void error(QString errorMessage);
	void currentStep(QString currentStep);

private slots:
	void on_cancelButton_clicked();

public:
	Video(std::string inputFileName, std::string outputFileName, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd,  int dropLength, int singleHeight, int doubleHeight, int windowSizeLeft, int windowSizeRight,
		bool autoDetectHeights, int wordConfidence, int lineConfidence, double compareThreshold, int dupeThreshold);
	~Video();
	void run();
	void sortYCoords(std::map<std::pair<int, int>, int>& frequency, std::vector<std::pair<int, int>>& ROICoordinates);
	void sortYCoords(std::map<int, int>& frequency, std::vector<int>& heights);
	void getBoxCoordinates(std::vector<cv::Vec2i> heightBoundaries, std::vector<std::pair<int, int>>& ROICoordinates, int singleHeight, int doubleHeight);
	std::map<std::pair<int, int>, int> boxCoordinateFrequency(std::map<std::pair<int, int>, int> frequency, std::vector<cv::Vec2i> horizontalBoundaries);
	bool whitespaceAverageCheck(cv::Mat image, int singleHeight, int doubleHeight);
	bool whiteSpaceBottomLineCheck(cv::Mat image, int windowSize);
	void crop(cv::Mat image, cv::Mat& dst, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd);
	void getBoxHeights(std::map<int, int> frequency, int& singleHeight, int& doubleHeight);
	void markPotentialDuplicates(std::string outputFileName, int dupeThreshold);
};

