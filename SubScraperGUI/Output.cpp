#include "Output.h"


Output::Output(std::string outputFileName)
{

	this->outputFileName = outputFileName;


}


Output::~Output()
{

}
//Deletes and replaces some common OCR mistakes
void Output::letterConverter()
{
	std::string provisionalFileName = outputFileName + "prov";
	std::ifstream output(provisionalFileName);
	std::ofstream outputFile(outputFileName);
	cv::String interimOutput;

	while (getline(output, interimOutput)) {
		for (size_t i = 0; i < interimOutput.length(); i++) {
			if (interimOutput[i] == '|') {
				interimOutput[i] = 'I';
			}

			if (interimOutput[i] == '[') {
				interimOutput[i] = ' ';
			}
			if (interimOutput[i] == ']') {
				interimOutput[i] = ' ';
			}
		}

		outputFile << interimOutput << std::endl;
		std::cout << "Executed" << std::endl;
		std::cout << interimOutput << std::endl;
	}


	output.close();
	outputFile.close();
	remove(provisionalFileName.c_str());
}
//Outputs results to console
void Output::outputResults(std::vector<std::string>& frameTexts, std::string outTexts[2])
{
	double JWdistance;
	StringComparer stringComparer;

	for (size_t i = 0; i < frameTexts.size(); i++) {
		JWdistance = stringComparer.jaroWinklerDistance(frameTexts[i], outTexts[i]);
		//store text if it isn't too similar to previously identified text (and isn't empty)
		//then print it to console
		if (JWdistance < 0.7 && !frameTexts[i].empty()) {
			outTexts[i] = frameTexts[i];
			std::cout << i << outTexts[i] << std::endl;
		}

	}
	//clear frameTexts to prevent overflow
	frameTexts.clear();

}
//Outputs results to text file
void Output::outputResults(std::vector<std::string>& frameTexts, std::string outTexts[2], std::string outputFileName)
{
	std::ofstream outputFile;
	double JWdistance;
	StringComparer stringComparer;
	if (!frameTexts.empty()) {
		for (size_t i = 0; i < frameTexts.size(); i++) {
			cv::String output = frameTexts[i];
			if (!output.empty()) {
				//remove space from end of new output if string not empty
				output.pop_back();
			}
			//check last letter of string
			char lastLetter = output.back();
			//if it is | then it is probably an OCR artifact, delete it
			if (lastLetter == '|' || lastLetter == '\\' || lastLetter == '/' || lastLetter == '4') {
				output.pop_back();
			}
			JWdistance = stringComparer.jaroWinklerDistance(output, outTexts[i]);
			std::cout << "frameText/output: " << output << std::endl;
			std::cout << "frameText/output length: " << output.length() << std::endl;
			std::cout << "outText: " << outTexts[i] << std::endl;
			std::cout << "JW distance: " << JWdistance << std::endl;


			//store text if it isn't too similar to previously output text (and isn't empty), then output to text file
			if (JWdistance < 0.75 && !output.empty()) {

				outputFile.open(outputFileName + "prov", std::ios_base::app);
				outputFile << output << std::endl;
				outputFile.close();
				outTexts[i] = output;

			}

		}
		//clear frametexts to prevent overflowing
		frameTexts.clear();
	}
}
//outputs final lines, which will be left in textLineOne and textLineTwo just before the program OCR loop terminates
void Output::outputFinalLines(std::string textLineOne, std::string textLineTwo)
{
	std::ofstream outputFile;

	if (!textLineOne.empty()) {
		outputFile.open(outputFileName + "prov", std::ios_base::app);
		outputFile << textLineOne << "\n ";
		outputFile.close();
	}

	if (!textLineTwo.empty()) {
		outputFile.open(outputFileName + "prov", std::ios_base::app);
		outputFile << textLineTwo << "\n ";
		outputFile.close();
	}
}


