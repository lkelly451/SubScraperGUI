#pragma once
#include <opencv2/imgproc.hpp>
#include <baseapi.h>
#include <iostream>
#include <allheaders.h>
#include "StringComparer.h"
#include "Output.h"
#include "../../../../../../opencv/build/include/opencv2/highgui.hpp"
#include <stdio.h>

class SubtitleBox
{
private:
	cv::Mat Box;
	std::vector<cv::Mat> SubtitleBoxLines;
public:
	SubtitleBox();
	SubtitleBox(cv::Mat frame, int heightStart, int heightEnd);
	~SubtitleBox();

	void getText(std::string& textLineOne, std::string& textLineTwo, int& prevLineOneConfidence, int& prevLineTwoConfidence, std::vector<std::string> frameTexts, int doubleHeight, std::string outputFileName, std::string outTexts[2], int windowSizeLeft, int windowSizeRight, int wordConfidence, int lineConfidence, double compareThreshold);
	void splitBox(cv::Mat img, std::vector<cv::Mat>& dst, int doubleHeight);
	static void ocr(cv::Mat image, std::string& frameText, int& confidence, int wordConfidence, int lineConfidence);
	void addBorders(std::vector<cv::Mat>& SubtitleBoxLines);
	void multiOCR(std::vector<cv::Mat>& ROIhalves, std::string& textLineOne, std::string& textLineTwo, std::vector<std::string>& frameTexts, int& prevLineOneConfidence, int& prevLineTwoConfidence, int wordConfidence, int lineConfidence, double compareThreshold);
	int widthCutterRight(cv::Mat image, int sliceWidth);
	int widthCutterLeft(cv::Mat image, int sliceWidth);
	void boxPreprocessing(cv::Mat image, cv::Mat& dst);
	void reduceWidth(std::vector<cv::Mat>& SubtitleBoxLines, int windowSizeLeft, int windowSizeRight);
	void doubleFirstPassOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& textLineOne, std::string& textLineTwo, int& prevLineOneConfidence, int& prevLineTwoConfidence, int wordConfidence, int lineConfidence);
	void singleToDoubleOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& textLineOne, std::string& textLineTwo, std::string& readTextLineOne, std::string& readTextLineTwo, int& lineOneConfidence, int& lineTwoConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, std::vector<std::string>& frameTexts, int wordConfidence, int lineConfidence);
	void doubleToDoubleOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& textLineOne, std::string& textLineTwo, std::string& readTextLineOne, std::string& readTextLineTwo, int& lineOneConfidence, int& lineTwoConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, std::vector<std::string>& frameTexts, int wordConfidence, int lineConfidence, double compareThreshold);
	void singleFirstPassOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& textLineOne, int& lineOneConfidence, int& prevLineOneConfidence, int wordConfidence, int lineConfidence);
	void doubleToSingleOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& textLineOne, std::string& textLineTwo, int& lineOneConfidence, int& prevLineOneConfidence, int& prevLineTwoConfidence, std::vector<std::string>& frameTexts, int wordConfidence, int lineConfidence);
	void singleToSingleOCR(std::vector<cv::Mat>& SubtitleBoxLines, std::string& readTextLineOne, std::string& textLineOne, int& lineOneConfidence, int& prevLineOneConfidence, std::vector<std::string>& frameTexts, int wordConfidence, int lineConfidence, double compareThreshold);
};

