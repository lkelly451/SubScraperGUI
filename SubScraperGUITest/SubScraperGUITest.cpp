#include "pch.h"
#include "CppUnitTest.h"
#include "../SubScraperGUI/StringComparer.h"
#include "../SubScraperGUI/StringComparer.cpp"
#include "opencv2/imgcodecs.hpp"
#include "../SubScraperGUI/SubtitleBox.h"
#include "../SubScraperGUI/SubtitleBox.cpp"
#include "../SubScraperGUI/Output.h"
#include "../SubScraperGUI/Output.cpp"
#include "../SubScraperGUI/Frame.h"
#include "../SubScraperGUI/Frame.cpp"
//#include "../SubScraperGUI/Video.h"
//#include "../SubScraperGUI/Video.cpp"
//#include "qthread.h"
//#include "qstring.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SubScraperGUITest
{
	cv::Mat image;
	std::string testStringOne;
	SubtitleBox subtitleBox;
	cv::Mat doubleBoxImage;

	TEST_CLASS(SubScraperGUITest)
	{
		
	public:
		TEST_CLASS_INITIALIZE(TestData)
		{
			image = cv::imread("C:/Users/Luke/source/repos/SubScraperGUI/SubScraperGUITest/testFrame.png", CV_8UC1);
			testStringOne = "testString";
		}
		
		TEST_METHOD(TestStringComparerIdentical)
		{
			std::string testStringTwo = "testString";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 1.0);
		}

		TEST_METHOD(TestStringComparerDifferent)
		{
			std::string testStringTwo = "xyz";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 0.0);
		}

		TEST_METHOD(TestStringComparerSimilar)
		{
			std::string testStringTwo = "testStringSimilar";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 0.847647, 0.000001);
		}
		
		TEST_METHOD(TestSubtitleBoxOCR)
		{
			
			std::string frameText;
			std::string expectedText = "down your heating ";
			int confidence;
			int wordConfidence = 0;
			int lineConfidence = 0;
			

			subtitleBox.ocr(image, frameText, confidence, wordConfidence, lineConfidence);
			Assert::AreEqual(frameText, expectedText);
		}

		TEST_METHOD(TestSubtitleBoxReduceWidth)
		{
			std::vector<cv::Mat> imageHalves;
			imageHalves.push_back(image);
			subtitleBox.reduceWidth(imageHalves, 5, 5);
			Assert::AreEqual(imageHalves[0].cols, 402);
		}

		TEST_METHOD(TestFrameDetectSingleBoxes)
		{
			cv::Mat singleBoxImage = cv::imread("C:/Users/Luke/source/repos/SubScraperGUI/SubScraperGUITest/testBoxDetectionSingle.png");
			Frame frame(singleBoxImage);
			int height;
			std::vector <cv::Vec4i> lines;
			frame.detectSingleBoxes(height, lines);
			Assert::AreEqual(height, 58);
		}

		TEST_METHOD(TestFrameDetectDoubleBoxes)
		{
			doubleBoxImage = cv::imread("C:/Users/Luke/source/repos/SubScraperGUI/SubScraperGUITest/testBoxDetectionDouble.png");
			Frame frame(doubleBoxImage);
			int height;
			std::vector <cv::Vec4i> lines;
			frame.detectDoubleBoxes(height, lines);
			Assert::AreEqual(height, 109);
		}

		TEST_METHOD(TestFrameFrequencyRecorder)
		{
			doubleBoxImage = cv::imread("C:/Users/Luke/source/repos/SubScraperGUI/SubScraperGUITest/testBoxDetectionDouble.png");
			Frame frame(doubleBoxImage);
			map<int, int> frequency;
			std::vector<std::vector<cv::Point>> contours;
			std::vector<cv::Vec4i> hierarchy;
			frame.framePreprocessing(doubleBoxImage);
			frame.findDrawContours(doubleBoxImage,doubleBoxImage, contours, hierarchy);
			frame.differenceRecorder(doubleBoxImage, frequency);
			Assert::AreEqual(frequency.size(), (size_t)1);
		}

		TEST_METHOD(TestFrameDropByLength)
		{
			doubleBoxImage = cv::imread("C:/Users/Luke/source/repos/SubScraperGUI/SubScraperGUITest/testBoxDetectionDouble.png");
			Frame frame(doubleBoxImage);
			map<int, int> frequency;
			std::vector<std::vector<cv::Point>> contours;
			std::vector<cv::Vec4i> hierarchy;
			vector<cv::Vec4i> lines;
			vector<cv::Vec4i> filteredLines;
			frame.framePreprocessing(doubleBoxImage);
			frame.findDrawContours(doubleBoxImage, doubleBoxImage, contours, hierarchy);
			frame.detectHorizontalHough(doubleBoxImage, lines, filteredLines, 33, 74);
			frame.dropByLength(filteredLines, 10);
			Assert::AreEqual(filteredLines.size(), (size_t)0);
		}

		TEST_METHOD(TestOutputResults)
		{
			std::vector<std::string> frameTexts;
			std::string outTexts[2];
			std::string outputFileName;
			frameTexts.push_back(testStringOne);
			Output output(outputFileName);
			output.outputResults(frameTexts, outTexts);
			Assert::AreEqual(outTexts[0], testStringOne);
		}

		TEST_METHOD(TestOutputFinalLines)
		{
			std::string outputFileName = "testFile";
			std::string readInput;
			Output output(outputFileName);
			int matches = 0;
			output.outputFinalLines(testStringOne, testStringOne);
			ifstream input("testFileProv");
			while (getline(input, readInput)) {
				if (readInput == testStringOne || readInput == " " + testStringOne) {
					matches += 1;
				}
			}
			input.close();
			remove("testFileProv");
			Assert::AreEqual(matches, 2);
			
		}
		
		
		TEST_METHOD(TestOutputLetterConverter)
		{
			Output output("testFile.txt");
			ofstream outputFile("testFile.txtprov");
			outputFile << "III";
			output.letterConverter();
			outputFile.close();
			ifstream input("testFile.txtprov");
			std::string readInput;
			std::string expectedInput = "III";
			int matches = 0;
			while (getline(input, readInput)) {
				if (readInput == expectedInput) {
					matches += 1;
				}
			}
			input.close();
			remove("testFile.txtprov");
			Assert::AreEqual(matches, 1);
		}
		/*
		TEST_METHOD(TestVideoBoxCoordinateFrequency)
		{
			map<pair<int, int>, int> frequency;
			//build a set of boundaries
			vector<cv::Vec2i> horizontalBoundaries;
			cv::Vec2i vec1(1, 2);
			cv::Vec2i vec2(1, 2);
			cv::Vec2i vec3(1, 1);
			horizontalBoundaries.push_back(vec1);
			horizontalBoundaries.push_back(vec2);
			horizontalBoundaries.push_back(vec3);
			pair<int, int> expectedPairOne = make_pair(1, 2);
			pair<int, int> expectedPairTwo = make_pair(1, 1);
			Video video;
			int matches = 0;
			//convert boundaries into a frequency map
			frequency = video.boxCoordinateFrequency(frequency, horizontalBoundaries);
			auto it = frequency.find(expectedPairOne);
			if (it->second == 2) {
				matches += 1;
			}
			it = frequency.find(expectedPairTwo);
			if (it->second == 1) {
				matches += 1;
			}
			Assert::AreEqual(matches, 2);
		
		}
		*/
		
	};
}
