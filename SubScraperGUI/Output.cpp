#include "Output.h"

using namespace std;

Output::Output(string outputFileName)
{

	this->outputFileName = outputFileName;


}


Output::~Output()
{

}
//Deletes and replaces some common OCR mistakes
void Output::letterConverter()
{
	string provisionalFileName = outputFileName + "prov";
	ifstream output(provisionalFileName);
	ofstream outputFile(outputFileName);
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

		outputFile << interimOutput << endl;
		cout << "Executed" << endl;
		cout << interimOutput << endl;
	}


	output.close();
	outputFile.close();
	remove(provisionalFileName.c_str());
}

void Output::multiOutputResults(vector<string>& frameTexts, string outTexts[2])
{
	double JWdistance;
	StringComparer stringComparer;

	for (size_t i = 0; i < frameTexts.size(); i++) {
		JWdistance = stringComparer.jaroWinklerDistance(frameTexts[i], outTexts[i]);
		//store text if it isn't too similar to previously identified text (and isn't empty)
		//then print it to console
		if (JWdistance < 0.7 && !frameTexts[i].empty()) {
			outTexts[i] = frameTexts[i];
			cout << i << outTexts[i] << endl;
		}

	}
	//clear frameTexts to prevent overflow
	frameTexts.clear();

}

void Output::multiOutputResults(vector<string>& frameTexts, string outTexts[2], string outputFileName)
{
	ofstream outputFile;
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
			cout << "frameText/output: " << output << endl;
			cout << "frameText/output length: " << output.length() << endl;
			cout << "outText: " << outTexts[i] << endl;
			cout << "JW distance: " << JWdistance << endl;


			//store text if it isn't too similar to previously output text (and isn't empty), then output to text file
			if (JWdistance < 0.75 && !output.empty()) {

				outputFile.open(outputFileName + "prov", ios_base::app);
				outputFile << output << endl;
				outputFile.close();
				outTexts[i] = output;

			}

		}
		//clear frametexts to prevent overflowing
		frameTexts.clear();
	}
}
//outputs final lines, which will be left in textLineOne and textLineTwo just before the program OCR loop terminates
void Output::outputFinalLines(string textLineOne, string textLineTwo)
{
	ofstream outputFile;

	if (!textLineOne.empty()) {
		outputFile.open(outputFileName + "prov", ios_base::app);
		outputFile << textLineOne << "\n ";
		outputFile.close();
	}

	if (!textLineTwo.empty()) {
		outputFile.open(outputFileName + "prov", ios_base::app);
		outputFile << textLineTwo << "\n ";
		outputFile.close();
	}
}


