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
	else {
		ofstream saveFile;
		string fileName = "Profiles.txt";
		saveFile.open(fileName, ios_base::app);
		saveFile  << ui.profileName->text().toStdString() << endl;
		saveFile  << this->widthBegin.toStdString() << endl;
		saveFile  << this->widthEnd.toStdString() << endl;
		saveFile  << this->heightBegin.toStdString() << endl;
		saveFile  << this->heightEnd.toStdString() << endl;
		saveFile  << this->singleHeight.toStdString() << endl;
		saveFile  << this->doubleHeight.toStdString() << endl;
		saveFile << endl;
		saveFile.close();
		ui.profileNameWarning->setText("Profile saved!");
	}
}