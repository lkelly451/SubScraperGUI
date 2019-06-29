#include "OutputSelect.h"
#include "HeightSelect.h"
#include "qfiledialog.h"
#include <iostream>
#include <fstream>

using namespace std;

OutputSelect::OutputSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}
OutputSelect::OutputSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString singleHeight, QString doubleHeight, QWidget* parent)
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

QPushButton* OutputSelect::getTranscriptFileSelect()
{
	return ui.transcriptFileSelect;
}

QLabel* OutputSelect::getTranscriptLabel()
{
	return ui.transcriptLabel;
}

QLineEdit* OutputSelect::getTranscriptLineEdit()
{
	return ui.transcriptLineEdit;
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

void OutputSelect::on_transcriptFileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"), "C://", tr("Text files (*.txt)"));
	ui.transcriptLineEdit->setText(filename);
}

void OutputSelect::on_goButton_clicked()
{
	if (ui.outputLineEdit->text().isEmpty()) {
		ui.continueWarning->setText("Please select where to save the subtitle output before continuing.");
	}
	else {
		//Go!
		cout << "Width begin: " << this->widthBegin.toInt();
		cout << "Width end: " << this->widthEnd.toInt();
		cout << "Height begin: " << this->heightBegin.toInt();
		cout << "Height end: " << this->heightEnd.toInt();
		cout << "Single height: " << this->singleHeight.toInt();
		cout << "Double height: " << this->doubleHeight.toInt();
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
