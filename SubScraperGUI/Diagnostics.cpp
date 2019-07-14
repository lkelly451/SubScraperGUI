#include "Diagnostics.h"
#include <opencv2/videoio.hpp>
#include <SubScraperGUI.h>
#include <iostream>
#include <Video.h>
#include <filesystem>
#include <QtWidgets\qmessagebox.h>

using namespace cv;
using namespace std;
Diagnostics::Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft,
	int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, string inputFileName, string outputFileName, bool autoDetectHeights, bool multiAnalysis, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->singleHeight = singleHeight;
	this->doubleHeight = doubleHeight;
	this->cropHeightStart = cropHeightStart;
	this->cropHeightEnd = cropHeightEnd;
	this->cropWidthStart = cropWidthStart;
	this->cropWidthEnd = cropWidthEnd;
	this->dropLength = dropLength;
	this->windowSizeLeft = windowSizeLeft;
	this->windowSizeRight = windowSizeRight;
	this->wordConfidence = wordConfidence;
	this->lineConfidence = lineConfidence;
	this->dupeThreshold = dupeThreshold;
	this->compareThreshold = compareThreshold;
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
	this->autoDetectHeights = autoDetectHeights;
	this->multiAnalysis = multiAnalysis;

	//hide exit and main menu buttons while the analysis loads
	ui.exitButton->hide();
	ui.mainButton->hide();
	//set a link to the output file and then hide it until the analysis is complete
	ui.outputLabel->setText(QString::fromStdString("<a href= 'file:///") + QString::fromStdString(outputFileName) + "'> Click here to view subtitles.</a>");
	ui.outputLabel->setOpenExternalLinks(true);
	ui.outputLabel->hide();

	//begin subtitle analysis thread when Diagnostics screen loads
	if (!multiAnalysis) {
		video = new Video(inputFileName, outputFileName, singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft,
			windowSizeRight, autoDetectHeights, wordConfidence, lineConfidence, compareThreshold, dupeThreshold);
		video->start();
	}
	else {
		//make a list of fileNames and output file names, then start thread for first file
		for (auto& files : std::filesystem::directory_iterator(inputFileName)) {
			string fileName = files.path().string();
			//base name of output files on the name of the files they are scanned from
			size_t nameStart = fileName.find_last_of("\\") + 1;
			size_t nameEnd = fileName.find_last_of(".");
			string outputName = outputFileName + "\\" + fileName.substr(nameStart, (nameEnd - nameStart)) + ".txt";
			outputFileNames.push_back(outputName);
			fileNames.push_back(fileName);
			numberOfFiles += 1;
		}
		video = new Video(fileNames[0], outputFileNames[0], singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft,
			windowSizeRight, autoDetectHeights, wordConfidence, lineConfidence, compareThreshold, dupeThreshold);
		video->start();
		currentFile += 1;
		//update GUI to show current video being analysed
		ui.vidLabel->setText(QString::fromStdString("Video " + std::to_string(currentFile) + " of " + std::to_string(numberOfFiles)));
	}

	//connection between cancel button clicked signal and its function
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(on_cancelButton_clicked()));

	//connection between video thread signals and their functions
	connect(video, SIGNAL(finished()), this, SLOT(onVideoFinished()));
	connect(video, SIGNAL(progressUpdate(int)), this, SLOT(onProgressUpdated(int)));
	connect(ui.cancelButton, SIGNAL(clicked()), video, SLOT(on_cancelButton_clicked()));
	connect(video, SIGNAL(error(QString)), this, SLOT(onErrorEncountered(QString)));
	connect(video, SIGNAL(currentStep(QString)), this, SLOT(getCurrentStep(QString)));
}

Diagnostics::Diagnostics(QString inputFileName, QWidget* parent)
	: QWidget(parent)
{
	VideoCapture cap;
	ui.setupUi(this);
	ui.progressBar->setMinimum(0);
	ui.progressBar->setMaximum(cap.get(CAP_PROP_FRAME_COUNT));
}

Diagnostics::~Diagnostics()
{
}


void Diagnostics::on_cancelButton_clicked() 
{	
	//if analysing multiple videos, cancel all of them
	if (multiAnalysis) {
		multiCancel = true;
	}
	//hide the cancel button and step label, and show the main menu and exit buttons
	//set label to tell user that process has been cancelled
	ui.cancelButton->hide();
	ui.stepLabel->hide();
	ui.mainButton->show();
	ui.exitButton->show();
	ui.progressBarLabel->setText("Analysis cancelled.");
	
}

void Diagnostics::on_mainButton_clicked() 
{
	//return to main menu
	SubScraperGUI* subScraperGUI = new SubScraperGUI();
	subScraperGUI->setAttribute(Qt::WA_DeleteOnClose);
	subScraperGUI->show();
	this->close();
}

void Diagnostics::on_exitButton_clicked()
{
	//terminate the program
	exit(0);
}

void Diagnostics::onVideoFinished()
{
	//inconsistent, why?
	if (!multiAnalysis) {
		cout << "Not MA" << endl;
		cout << "MA: " << multiAnalysis; 
		//if loading has not finished, then these values are not set to avoid conflicting with the on_cancelButton_clicked() setup
		if (ui.progressBar->value() == 100) {
			//change the progress bar label to notify the user that analysis is complete
			ui.progressBarLabel->setText("Complete");
			//clear current step label
			ui.stepLabel->setText(" ");
			//hide the cancel button
			ui.cancelButton->hide();
			//show the exit and main menu buttons, and output link
			ui.exitButton->show();
			ui.mainButton->show();
			ui.outputLabel->show();
		}
	}
	else {
		//launch analysis of next file if there is one
		if (currentFile < numberOfFiles && !multiCancel) {
			cout << "Videos remaining" << endl;
			cout << "currentfile: " << currentFile << endl;
			cout << "numberOfFiles: " << numberOfFiles << endl;
			video->wait();
			delete video;
			video = new Video(fileNames[currentFile], outputFileNames[currentFile], singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft,
				windowSizeRight, autoDetectHeights, wordConfidence, lineConfidence, compareThreshold, dupeThreshold);
			video->start();
			currentFile += 1;
			ui.vidLabel->setText(QString::fromStdString("Video " + std::to_string(currentFile) + " of " + std::to_string(numberOfFiles)));

			connect(video, SIGNAL(finished()), this, SLOT(onVideoFinished()));
			connect(video, SIGNAL(progressUpdate(int)), this, SLOT(onProgressUpdated(int)));
			connect(ui.cancelButton, SIGNAL(clicked()), video, SLOT(on_cancelButton_clicked()));
			connect(video, SIGNAL(error(QString)), this, SLOT(onErrorEncountered(QString)));
			connect(video, SIGNAL(currentStep(QString)), this, SLOT(getCurrentStep(QString)));
		}
		//otherwise finish
		else {
			cout << "no videos remaining" << endl;
			cout << "currentfile: " << currentFile << endl;
			cout << "numberOfFiles: " << numberOfFiles << endl;
			if (ui.progressBar->value() == 100) {
				ui.progressBarLabel->setText("Complete");
				ui.stepLabel->setText(" ");
				ui.cancelButton->hide();
				ui.exitButton->show();
				ui.mainButton->show();
				ui.outputLabel->show();
			}
		}
	}
}

void Diagnostics::onProgressUpdated(int progress)
{
	ui.progressBar->setValue(progress);
}

void Diagnostics::onErrorEncountered(QString errorMessage)
{
	QMessageBox messageBox;
	messageBox.critical(0, "Video Analysis Error", errorMessage);
	messageBox.setFixedSize(500, 200);
	ui.progressBarLabel->setText("Cancelled");
	//if there are no more videos remaining, change the UI accordingly
	if (!multiAnalysis || currentFile == numberOfFiles) {
		ui.cancelButton->hide();
		ui.mainButton->show();
		ui.exitButton->show();
	}
}

void Diagnostics::getCurrentStep(QString currentStep)
{
	ui.stepLabel->setText(currentStep);
}
