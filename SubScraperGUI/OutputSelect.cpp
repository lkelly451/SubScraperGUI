#include "OutputSelect.h"
#include "HeightSelect.h"
#include "qvalidator.h"
#include <Diagnostics.h>
#include "qfiledialog.h"
#include <iostream>
#include <fstream>
#include <qmenubar.h>
#include <Help.h>
#include <About.h>

using namespace std;

OutputSelect::OutputSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
OutputSelect::OutputSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString singleHeight, QString doubleHeight, QString inputFileName, bool autoBoxDetect, int width, double position, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->widthBegin = widthBegin;
	this->widthEnd = widthEnd;
	this->heightBegin = heightBegin;
	this->heightEnd = heightEnd;
	this->singleHeight = singleHeight;
	this->doubleHeight = doubleHeight;
	this->dropLength = ui.lengthFilterLineEdit->text();
	this->windowSizeLeft = ui.leftWindowLineEdit->text();
	this->windowSizeRight = ui.rightWindowLineEdit->text();
	this->wordConfidence = ui.wordConfidenceLineEdit->text();
	this->lineConfidence = ui.lineConfidenceLineEdit->text();
	this->compareThreshold = ui.compareThresholdLineEdit->text();
	this->dupeThreshold = ui.dupeThresholdLineEdit->text();
	this->inputFileName = inputFileName;
	this->autoDetectHeights = autoBoxDetect;
	this->width = width;
	this->position = position;

	//validation for advanced options, prevents invalid data type/size being set
	//max size is width of the image
	QValidator* intValidatorFilterWindow = new QIntValidator(0, width, this);
	ui.lengthFilterLineEdit->setValidator(intValidatorFilterWindow);
	ui.rightWindowLineEdit->setValidator(intValidatorFilterWindow);
	ui.leftWindowLineEdit->setValidator(intValidatorFilterWindow);

	//max size is arbitrary
	QValidator* intValidatorDupe = new QIntValidator(0, 9999, this);
	ui.dupeThresholdLineEdit->setValidator(intValidatorDupe);

	//max size is 100
	QValidator* intValidatorWordLineConfidenceThreshold = new QIntValidator(0, 100, this);
	ui.lineConfidenceLineEdit->setValidator(intValidatorWordLineConfidenceThreshold);
	ui.wordConfidenceLineEdit->setValidator(intValidatorWordLineConfidenceThreshold);

	//max size is 1.0
	QValidator* doubleValidatorOutputComparisonThreshold = new QDoubleValidator(0.0, 1.0, 1, this);

	//set tooltips
	ui.toolTipBoxLength->setToolTip("Lines greater in length than this threshold will not be detected as potential subtitle boxes.");
	ui.toolTipLeftSlidingWindow->setToolTip("Sets the width of a sliding window that attempts to find the left boundary of the subtitle box and cut out extraneous pixels. Set to zero if cropped zone is flush with the left of the subtitle box.");
	ui.toolTipRightSlidingWindow->setToolTip("Sets the width of a sliding window that attempts to find the right boundary of the subtitle box and cut out extraneous pixels.");
	ui.toolTipWordConfidence->setToolTip("Sets the minimum percentage confidence the OCR engine must have in a word to output it.");
	ui.toolTipLineConfidence->setToolTip("Sets the minimum percentage confidence the OCR engine must have in a line to output it (average across all words).");
	ui.toolTipMarkDuplicates->setToolTip("Sets the minimum length that a series of repeated characters across two subtitle boxes must be to be marked as a potential duplicate in the output text file.");
	ui.toolTipComparisonThreshold->setToolTip("Sets the percentage difference two consecutive reads must have for the system to output them (from 0.10 to 1.00)." );

	//Menu bar for QWidget based windows
	QMenuBar* menuBar = new QMenuBar();
	QMenu* helpMenu = new QMenu("Help");
	QAction* help = new QAction("Help", this);
	QAction* about = new QAction("About", this);
	menuBar->addMenu(helpMenu);
	helpMenu->addAction(help);
	helpMenu->addAction(about);

	this->layout()->setMenuBar(menuBar);

	connect(help, &QAction::triggered, this, &OutputSelect::on_help_clicked);
	connect(about, &QAction::triggered, this, &OutputSelect::on_about_clicked);
}
OutputSelect::~OutputSelect()
{
}

void OutputSelect::on_backButton_clicked()
{
	HeightSelect* heightSelect = new HeightSelect(widthBegin, widthEnd, heightBegin, heightEnd, inputFileName, position);
	heightSelect->setAttribute(Qt::WA_DeleteOnClose);
	heightSelect->show();
	this->close();
}

void OutputSelect::on_outputFileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"), "C://", tr("Text files (*.txt)"));
	ui.outputLineEdit->setText(filename);
}

void OutputSelect::on_goButton_clicked()
{
	if (ui.outputLineEdit->text().isEmpty()) {
		ui.continueWarning->setText("Please select where to save the subtitle output before continuing.");
	}
	else {
		//Go!
		if (!singleHeight.isEmpty() && !doubleHeight.isEmpty() && !heightBegin.isEmpty() && !heightEnd.isEmpty() && !widthBegin.isEmpty() && !widthEnd.isEmpty() && !ui.lengthFilterLineEdit->text().isEmpty()
			&& !ui.leftWindowLineEdit->text().isEmpty() && !ui.rightWindowLineEdit->text().isEmpty() && !ui.wordConfidenceLineEdit->text().isEmpty() && !ui.lineConfidenceLineEdit->text().isEmpty()
			&& !ui.dupeThresholdLineEdit->text().isEmpty() && !ui.compareThresholdLineEdit->text().isEmpty() && !inputFileName.isEmpty() && !ui.outputLineEdit->text().isEmpty()) {
			if (ui.lengthFilterLineEdit->text().toInt() < width && ui.leftWindowLineEdit->text().toInt() < width && ui.rightWindowLineEdit->text().toInt() < width) {
				int singleHeight = this->singleHeight.toInt();
				int doubleHeight = this->doubleHeight.toInt();
				int cropHeightStart = this->heightBegin.toInt();
				int cropHeightEnd = this->heightEnd.toInt();
				int cropWidthStart = this->widthBegin.toInt();
				int cropWidthEnd = this->widthEnd.toInt();
				int dropLength = ui.lengthFilterLineEdit->text().toInt();
				int windowSizeLeft = ui.leftWindowLineEdit->text().toInt();
				int windowSizeRight = ui.rightWindowLineEdit->text().toInt();
				int wordConfidence = ui.wordConfidenceLineEdit->text().toInt();
				int lineConfidence = ui.lineConfidenceLineEdit->text().toInt();
				int dupeThreshold = ui.dupeThresholdLineEdit->text().toInt();
				double compareThreshold = ui.compareThresholdLineEdit->text().toDouble();
				string inputFileName = this->inputFileName.toStdString();
				string outputFileName = ui.outputLineEdit->text().toStdString();


				Diagnostics* diagnostics = new Diagnostics(singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence,
					dupeThreshold, compareThreshold, inputFileName, outputFileName, autoDetectHeights, false);
				diagnostics->setAttribute(Qt::WA_DeleteOnClose);
				diagnostics->show();
				this->close();

			
			}
			else {
				ui.continueWarning->setText("Sliding windows and box filter must be set to less than the width of the cropped image.");
			}
		}
		else {
			ui.continueWarning->setText("Please ensure all fields are filled before continuing.");
		}
	}
}

void OutputSelect::on_saveProfileButton_clicked()
{
	if (ui.profileName->text().isEmpty()) {
		ui.continueWarning->setText("Please enter a profile name to save a profile.");
	}
	else if (!widthBegin.isEmpty() && !widthEnd.isEmpty() && !heightBegin.isEmpty() && !heightEnd.isEmpty() && !singleHeight.isEmpty() && !doubleHeight.isEmpty() && !dropLength.isEmpty()
		&& !windowSizeLeft.isEmpty() && !windowSizeRight.isEmpty() && !wordConfidence.isEmpty() && !lineConfidence.isEmpty() && !compareThreshold.isEmpty() && !ui.dupeThresholdLineEdit->text().isEmpty()){
		//check that profile name is not already in use
		ifstream loadProfile("Profiles.txt");
		bool taken = false;
		if (loadProfile) {
			string name;
			while (!loadProfile.eof()) {
				getline(loadProfile, name);
				if (name == ui.profileName->text().toStdString()) {
					taken = true;
				}
				for (size_t i = 0; i < 15; i++) {
					loadProfile.ignore(256, '\n');
				}
			}
			loadProfile.close();
		}
		if (!taken) {
			ofstream saveFile;
			string fileName = "Profiles.txt";
			saveFile.open(fileName, ios_base::app);
			saveFile << ui.profileName->text().toStdString() << endl;
			saveFile << widthBegin.toStdString() << endl;
			saveFile << widthEnd.toStdString() << endl;
			saveFile << heightBegin.toStdString() << endl;
			saveFile << heightEnd.toStdString() << endl;
			saveFile << singleHeight.toStdString() << endl;
			saveFile << doubleHeight.toStdString() << endl;
			saveFile << dropLength.toStdString() << endl;
			saveFile << windowSizeLeft.toStdString() << endl;
			saveFile << windowSizeRight.toStdString() << endl;
			saveFile << wordConfidence.toStdString() << endl;
			saveFile << lineConfidence.toStdString() << endl;
			saveFile << compareThreshold.toStdString() << endl;
			saveFile << ui.dupeThresholdLineEdit->text().toStdString() << endl;
			saveFile << autoDetectHeights << endl;
			saveFile << endl;
			saveFile.close();
			ui.continueWarning->setText("Profile saved!");
		}
		else {
			ui.continueWarning->setText("This profile name is taken, please enter another.");
		}
	} else {
		ui.continueWarning->setText("Please ensure all fields are filled before saving a profile.");
	}
}

void OutputSelect::on_lengthFilterLineEdit_editingFinished()
{
	this->dropLength = ui.lengthFilterLineEdit->text();
}

void OutputSelect::on_leftWindowLineEdit_editingFinished()
{
	this->windowSizeLeft = ui.leftWindowLineEdit->text();
}

void OutputSelect::on_rightWindowLineEdit_editingFinished()
{
	this->windowSizeRight = ui.rightWindowLineEdit->text();
}

void OutputSelect::on_wordConfidenceLineEdit_editingFinished()
{
	this->wordConfidence = ui.wordConfidenceLineEdit->text();
}

void OutputSelect::on_lineConfidenceLineEdit_editingFinished()
{
	this->lineConfidence = ui.lineConfidenceLineEdit->text();
}

void OutputSelect::on_compareThresholdLineEdit_editingFinished()
{
	this->compareThreshold = ui.compareThresholdLineEdit->text();
}

void OutputSelect::on_dupeThresholdLineEdit_editingFinished()
{
	this->dupeThreshold = ui.dupeThresholdLineEdit->text();
}

void OutputSelect::on_help_clicked()
{
	Help* help = new Help();
	help->setAttribute(Qt::WA_DeleteOnClose);
	help->show();
}

void OutputSelect::on_about_clicked()
{
	About* about = new About();
	about->setAttribute(Qt::WA_DeleteOnClose);
	about->show();
}