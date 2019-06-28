#pragma once
#include <map>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Frame
{
private:
	cv::Mat frame;
public:
	Frame(cv::Mat frame);
	~Frame();

	void framePreprocessing(cv::Mat& dst);
	void detectHorizontalHough(cv::Mat frame, std::vector<cv::Vec4i>& lines, std::vector<cv::Vec4i>& filteredLines, int singleHeight, int doubleHeight);
	void detectHorizontalHough(cv::Mat frame, std::vector<cv::Vec4i>& lines, int& height);
	void drawHough(cv::Mat& dst, std::vector<cv::Vec4i> filteredLines);
	void dropByLength(std::vector<cv::Vec4i>& filteredLines, int dropLength);
	void detectVerticalHough(cv::Mat frame, std::vector<cv::Vec4i>& lines, std::vector<cv::Vec4i>& filteredLines, int rangeStart, int rangeEnd);
	void printHoughlines(std::vector<cv::Vec4i> filteredLines);
	void findDrawContours(cv::Mat frame, cv::Mat& dst, std::vector<std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy);
	void heightBoundaryRecorder(std::vector<cv::Vec4i> filteredLines, std::vector<cv::Vec2i>& heightBoundaries);
	void detectBoxes(int singleHeight, int doubleHeight, std::vector<cv::Vec2i>& heightBoundaries, int dropLength);
	void detectDoubleBoxes(int& height, std::vector <cv::Vec4i>& lines);
	void detectSingleBoxes(int& height, std::vector <cv::Vec4i>& lines);
	void differenceRecorder(cv::Mat draw, std::map<int, int>& frequency);
	void detectHeights(std::map<int, int>& frequency);
};

