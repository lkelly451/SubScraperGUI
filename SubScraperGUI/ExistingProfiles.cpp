#include "ExistingProfiles.h"
#include "SubScraperGUI.h"
#include "qfiledialog.h"
#include <fstream>
#include <iostream>

using namespace std;

ExistingProfiles::ExistingProfiles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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
			for (size_t i = 0; i < 7; i++) {
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

QPushButton* ExistingProfiles::getTranscriptFileSelect()
{
	return ui.transcriptFileSelect;
}

QLabel* ExistingProfiles::getTranscriptLabel()
{
	return ui.transcriptLabel;
}

QLineEdit* ExistingProfiles::getTranscriptLineEdit()
{
	return ui.transcriptLineEdit;
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

void ExistingProfiles::on_transcriptFileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this, tr("Open File"), "C://", tr("Text files (*.txt)"));
	ui.transcriptLineEdit->setText(filename);
}

void ExistingProfiles::on_item_clicked(QListWidgetItem* item)
{
	ifstream loadProfile("Profiles.txt");
	if (loadProfile) {
		string name;
		while (!loadProfile.eof()) {
			getline(loadProfile, name);
			//load the profile's saved variables
			if (name == item->text().toStdString()) {
				loadProfile >> widthBegin;
				loadProfile >> widthEnd;
				loadProfile >> heightBegin;
				loadProfile >> heightEnd;
				loadProfile >> singleHeight;
				loadProfile >> doubleHeight;
				break;
			}
		}
	}
	
}

void ExistingProfiles::on_goButton_clicked()
{
	if (widthBegin > 0 && widthEnd > 0 && heightBegin > 0 && heightEnd > 0 && singleHeight > 0 && doubleHeight > 0) {
		//go
	}
	else {
		ui.goWarningLabel->setText("Please click on a saved profile to select it before continuing.");
	}
}