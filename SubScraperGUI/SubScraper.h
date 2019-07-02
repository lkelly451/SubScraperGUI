#include <string>
#pragma once
class SubScraper
{
public:
	SubScraper();
	~SubScraper();
	void getSubs(std::string inputFileName, std::string outputFileName, std::string transcriptFileDirectory, int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, int windowSizeRight, int wordConfidence, int lineConfidence, double compareThreshold, int dupeThreshold, bool autoDetectHeights);
};

