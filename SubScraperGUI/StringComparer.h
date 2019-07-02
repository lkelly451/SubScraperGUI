#include <string>
#include <opencv2/imgproc.hpp>
#pragma once

class StringComparer
{
public:
	StringComparer();
	~StringComparer();
	double jaroDistance(const std::string& a, const std::string& b);
	double jaroWinklerDistance(const std::string& a, const std::string& b);

};

