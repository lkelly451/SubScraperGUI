#include "ExistingProfiles.h"
#include "SubScraperGUI.h"
#include "qfiledialog.h"
#include <fstream>
#include <iostream>
#include <SubScraper.h>

using namespace std;

ExistingProfiles::ExistingProfiles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//load the names of any saved profiles into the profile list
	ifstream loadProfile("Profiles.txt");
	if (loadProfile) {
		string name;
		while (!loadProfile.eof()) {
			getline(loadProfile, name);
			QString profileName = QString::fromStdString(name);
			if (!profileName.isEmpty()) {
				QListWidgetItem* item = new QListWidgetItem(profileName, ui.profileList);
				ui.profileList->setCurrentItem(item);
			}
			for (size_t i = 0; i < 15; i++) {
				loadProfile.ignore(256, '\n');
			}
		}
		loadProfile.close();
	}
	connect(ui.profileList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(on_item_clicked(QListWidgetItem*)));
}

ExistingProfiles::~ExistingProfiles()
{
}

QPushButton* ExistingProfiles::getBackButton()
{
	return ui.backButton;
}

QLabel* ExistingProfiles::getExistingLabel()
{
	return ui.existingLabel;
}


QPushButton* ExistingProfiles::getFileSelect()
{
	return ui.fileSelect;
}

QPushButton* ExistingProfiles::getGoButton()
{
	return ui.goButton;
}

QLabel* ExistingProfiles::getInputLabel()
{
	return ui.inputLabel;
}

QLineEdit* ExistingProfiles::getInputLineEdit()
{
	return ui.inputLineEdit;
}

QPushButton* ExistingProfiles::getOutputFileSelect()
{
	return ui.outputFileSelect;
}

QLabel* ExistingProfiles::getOutputLabel()
{
	return ui.outputLabel;
}

QLineEdit* ExistingProfiles::getOutputLineEdit()
{
	return ui.outputLineEdit;
}

void ExistingProfiles::on_backButton_clicked()
{
	SubScraperGUI* subScraperGUI = new SubScraperGUI();
	subScraperGUI->setAttribute(Qt::WA_DeleteOnClose);
	subScraperGUI->show();
	this->close();
}

void ExistingProfiles::on_fileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"), "C://", tr("Videos (*.mkv *.avi *.mp4 *.wmv)"));
	ui.inputLineEdit->setText(filename);
}

void ExistingProfiles::on_outputFileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"), "C://", tr("Text files (*.txt)"));
	ui.outputLineEdit->setText(filename);
}

void ExistingProfiles::on_item_clicked(QListWidgetItem* item)
{
	ifstream loadProfile("Profiles.txt");
	if (loadProfile) {
		string profileName;
		while (!loadProfile.eof()) {
			getline(loadProfile, profileName);
			//load the profile's saved variables
			if (profileName == item->text().toStdString()) {
				loadProfile >> cropWidthStart;
				loadProfile >> cropWidthEnd;
				loadProfile >> cropHeightStart;
				loadProfile >> cropHeightEnd;
				loadProfile >> singleHeight;
				loadProfile >> doubleHeight;
				loadProfile >> dropLength;				
				loadProfile >> windowSizeLeft;				
				loadProfile >> windowSizeRight;			
				loadProfile >> wordConfidence; 			
				loadProfile >> lineConfidence;
				loadProfile >> compareThreshold;
				loadProfile >> dupeThreshold;
				loadProfile >> autoDetectHeights;

				cout << cropWidthStart << endl;
				cout << cropWidthEnd << endl;
				cout << cropHeightStart << endl;
				cout << cropHeightEnd << endl;
				cout << singleHeight << endl;
				cout << doubleHeight << endl;
				cout << dropLength << endl;
				cout << windowSizeLeft << endl;
				cout << windowSizeRight << endl;
				cout << wordConfidence << endl;
				cout << lineConfidence << endl;
				cout << compareThreshold << endl;
				break;
			}
		}
	}
	
}

void ExistingProfiles::on_goButton_clicked()
{
	inputFileName = ui.inputLineEdit->text();
	outputFileName = ui.outputLineEdit->text();

	//if inputs are all filled, get subtitles
	if (!inputFileName.isEmpty() && !outputFileName.isEmpty() && cropWidthStart >= 0 && cropWidthEnd >= 0 && cropHeightStart >= 0 && cropHeightEnd >= 0 && singleHeight >= 0 && doubleHeight >= 0 && dropLength >=0
		&& windowSizeLeft >= 0 && windowSizeRight >= 0 && wordConfidence >= 0 && lineConfidence >= 0 && compareThreshold >= 0) {
		SubScraper subscraper;
		this->close();
		subscraper.getSubs(inputFileName.toStdString(), outputFileName.toStdString(), singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength,
			windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence, compareThreshold, dupeThreshold, autoDetectHeights);
	}
	//else print a warning
	else {
		ui.goWarningLabel->setText("Please select a saved profile, a video to analyse and a destination for the subtitle output before continuing.");
	}
}