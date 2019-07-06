#include "ExistingProfiles.h"
#include "SubScraperGUI.h"
#include "qfiledialog.h"
#include <fstream>
#include <iostream>
#include <SubScraper.h>
#include <Diagnostics.h>

using namespace std;

ExistingProfiles::ExistingProfiles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//load the names of any saved profiles into the profile list
	ifstream loadProfile("Profiles.txt");
	if (loadProfile) {
		string profileName;
		while (!loadProfile.eof()) {
			getline(loadProfile, profileName);
			name = QString::fromStdString(profileName);
			if (!name.isEmpty()) {
				QListWidgetItem* item = new QListWidgetItem(name, ui.profileList);
				ui.profileList->setCurrentItem(item);
			}
			for (size_t i = 0; i < 15; i++) {
				loadProfile.ignore(256, '\n');
			}
		}
		loadProfile.close();
		//load attributes of default selected profile
		on_item_clicked(ui.profileList->currentItem());

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
				name = QString::fromStdString(profileName);
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
		Diagnostics* diagnostics = new Diagnostics(singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength, windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence,
			dupeThreshold, compareThreshold, inputFileName.toStdString(), outputFileName.toStdString(), autoDetectHeights);
		diagnostics->setAttribute(Qt::WA_DeleteOnClose);
		diagnostics->show();
		this->close();
	}
	//else print a warning
	else {
		ui.goWarningLabel->setText("Please select a saved profile, a video to analyse and a destination for the subtitle output before continuing.");
	}
}

void ExistingProfiles::on_deleteProfileButton_clicked()
{
	ifstream loadProfile("Profiles.txt");
	if (loadProfile) {
		string line;
		string selectedProfile = name.toStdString();
		string interim;
		while (getline(loadProfile, line)) {
			//if the currently selected profile name matches an entry in Profiles.txt, delete the entry
			if (line == selectedProfile) {
				for (size_t i = 0; i < 15; i++) {
					loadProfile.ignore(256, '\n');
					ui.goWarningLabel->setText("Profile deleted.");
				}
			}
			else {
				interim.append(line);
				interim.append("\n");
			}
			
			
		}
		loadProfile.close();
		ofstream overWriteProfile("Profiles.txt");
		overWriteProfile << interim;
		overWriteProfile.close();
	}
	//reload the list of saved profiles
	loadProfile.open("Profiles.txt");
	ui.profileList->clear();
	if (loadProfile) {
		string profileName;
		while (!loadProfile.eof()) {
			getline(loadProfile, profileName);
			name = QString::fromStdString(profileName);
			if (!name.isEmpty()) {
				QListWidgetItem* item = new QListWidgetItem(name, ui.profileList);
				ui.profileList->setCurrentItem(item);
			}
			for (size_t i = 0; i < 15; i++) {
				loadProfile.ignore(256, '\n');
			}
		}
		loadProfile.close();
		//load attributes of default selected profile
		on_item_clicked(ui.profileList->currentItem());
	}

}