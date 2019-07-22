#pragma once
#include <fstream>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include "StringComparer.h"

class Output
{
private:

	std::string outputFileName;

public:
	Output(std::string outputFileName);
	~Output();
	void letterConverter();
	void outputResults(std::vector<std::string>& frameTexts, std::string outTexts[2]);
	void outputResults(std::vector<std::string>& frameTexts, std::string outTexts[2], std::string outputFileName);
	void outputFinalLines(std::string textLineOne, std::string textLineTwo);
};

