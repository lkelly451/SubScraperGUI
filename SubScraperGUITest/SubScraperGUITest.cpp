#include "pch.h"
#include "CppUnitTest.h"
#include "../SubScraperGUI/StringComparer.h"
#include "../SubScraperGUI/StringComparer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace SubScraperGUITest
{
	TEST_CLASS(SubScraperGUITest)
	{
	public:
		
		TEST_METHOD(TestStringComparerIdentical)
		{
			string testStringOne = "testString";
			string testStringTwo = "testString";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 1.0);
		}

		TEST_METHOD(TestStringComparerDifferent)
		{
			string testStringOne = "testString";
			string testStringTwo = "xyz";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 0.0);
		}

		TEST_METHOD(TestStringComparerSimilar)
		{
			string testStringOne = "testString";
			string testStringTwo = "testStringSimilar";
			StringComparer stringComparer;
			Assert::AreEqual(stringComparer.jaroWinklerDistance(testStringOne, testStringTwo), 0.847647, 0.000001);
		}
	};
}
