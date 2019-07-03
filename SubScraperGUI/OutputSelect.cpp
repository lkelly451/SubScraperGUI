#include "OutputSelect.h"
#include "HeightSelect.h"
#include "qfiledialog.h"
#include <iostream>
#include <fstream>
#include "SubScraper.h"

using namespace std;

OutputSelect::OutputSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
OutputSelect::OutputSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString singleHeight, QString doubleHeight, QString inputFileName, bool autoBoxDetect, QWidget* parent)
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
}
OutputSelect::~OutputSelect()
{
}

QPushButton* OutputSelect::getBackButton()
{
	return ui.backButton;
}

QPushButton* OutputSelect::getGoButton()
{
	return ui.goButton;
}

QPushButton* OutputSelect::getOutputFileSelect()
{
	return ui.outputFileSelect;
}

QLabel* OutputSelect::getOutputLabel()
{
	return ui.outputLabel;
}

QLineEdit* OutputSelect::getOutputLineEdit()
{
	return ui.outputLineEdit;
}

void OutputSelect::on_backButton_clicked()
{
	HeightSelect* heightSelect = new HeightSelect();
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
		
		cout << "singleHeight: " << singleHeight << endl;
		cout << "doubleHeight: " << doubleHeight << endl;
		cout << "cropHeightStart: " << heightBegin.toInt() << endl;
		cout << "cropHeightEnd: " << heightEnd.toInt() << endl;
		cout << "cropWidthStart: " << widthBegin.toInt() << endl;
		cout << "cropWidthEnd: " << widthEnd.toInt() << endl;
		cout << "dropLength: " << ui.lengthFilterLineEdit->text().toInt() << endl;
		cout << "windowSizeLeft: " << ui.leftWindowLineEdit->text().toInt() << endl;
		cout << "windowSizeRight: " << ui.rightWindowLineEdit->text().toInt() << endl;
		cout << "wordConfidence: " << ui.wordConfidenceLineEdit->text().toInt() << endl;
		cout << "lineConfidence: " << ui.lineConfidenceLineEdit->text().toInt() << endl;
		cout << "dupeThreshold: " << ui.dupeThresholdLineEdit->text().toInt() << endl;
		cout << "compareThreshold: " << ui.compareThresholdLineEdit->text().toDouble() << endl;
		cout << "inputFileName: " << this->inputFileName.toStdString() << endl;
		cout << "outputFileName: " << ui.outputLineEdit->text().toStdString() << endl;
		cout << "autoDetectHeights: " << autoDetectHeights << endl;

		SubScraper subscraper;
		this->close();
		subscraper.getSubs(inputFileName, outputFileName, singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength,
			windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence, compareThreshold, dupeThreshold, autoDetectHeights);
		
	}
}

void OutputSelect::on_saveProfileButton_clicked()
{
	if (ui.profileName->text().isEmpty()) {
		ui.profileNameWarning->setText("Please enter a profile name to save a profile.");
	}
	else if (!widthBegin.isEmpty() && !widthEnd.isEmpty() && !heightBegin.isEmpty() && !heightEnd.isEmpty() && !singleHeight.isEmpty() && !doubleHeight.isEmpty() && !dropLength.isEmpty()
		&& !windowSizeLeft.isEmpty() && !windowSizeRight.isEmpty() && !wordConfidence.isEmpty() && !lineConfidence.isEmpty() && !compareThreshold.isEmpty()){
		ofstream saveFile;
		string fileName = "Profiles.txt";
		saveFile.open(fileName, ios_base::app);
		saveFile  << ui.profileName->text().toStdString() << endl;
		saveFile  << widthBegin.toStdString() << endl;
		saveFile  << widthEnd.toStdString() << endl;
		saveFile  << heightBegin.toStdString() << endl;
		saveFile  << heightEnd.toStdString() << endl;
		saveFile  << singleHeight.toStdString() << endl;
		saveFile  << doubleHeight.toStdString() << endl;
		saveFile << dropLength.toStdString() << endl;
		saveFile << windowSizeLeft.toStdString() << endl;
		saveFile << windowSizeRight.toStdString() << endl;
		saveFile << wordConfidence.toStdString() << endl;
		saveFile << lineConfidence.toStdString() << endl;
		saveFile << compareThreshold.toStdString() << endl;
		saveFile << endl;
		saveFile.close();
		ui.profileNameWarning->setText("Profile saved!");
	} else {
		ui.profileNameWarning->setText("Please ensure all fields are filled before saving a profile.");
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
