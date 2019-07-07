#include "Diagnostics.h"
#include <opencv2/videoio.hpp>
#include <SubScraper.h>
#include <SubScraperGUI.h>
#include <iostream>
#include <Video.h>
using namespace cv;
using namespace std;
Diagnostics::Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, 
	int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, string inputFileName, string outputFileName, bool autoDetectHeights, QWidget *parent)
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

	//hide exit and main menu buttons while the analysis loads
	ui.exitButton->hide();
	ui.mainButton->hide();

	connect(this, SIGNAL(windowShown()), this, SLOT(on_windowShown()), Qt::ConnectionType(Qt::QueuedConnection));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(on_cancelButton_clicked()));
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

void Diagnostics::showEvent(QShowEvent* ev) 
{
	QWidget::showEvent(ev);
	QApplication::processEvents();
	emit windowShown();
}

void Diagnostics::on_windowShown() 
{
	//begin subtitle analysis thread when Diagnostics screen loads
	video = new Video(inputFileName, outputFileName, singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft,
		windowSizeRight, autoDetectHeights, wordConfidence, lineConfidence, compareThreshold, dupeThreshold,  ui.progressBar, ui.cancelButton, ui.exitButton, ui.mainButton, ui.progressBarLabel, ui.outputLabel);
	video->start();

}

void Diagnostics::on_cancelButton_clicked() 
{	
	//set cancel button to checked in order to trigger Subscraper::getSubs() to cancel
	//hide the cancel button and show the main menu and exit buttons
	//set label to tell user that process has been cancelled
	ui.cancelButton->setFlat(true);
	ui.cancelButton->hide();
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


