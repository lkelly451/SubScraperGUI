#include "ExistingProfiles.h"
#include "SubScraperGUI.h"
#include "qfiledialog.h"

ExistingProfiles::ExistingProfiles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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

QListView* ExistingProfiles::getExistingList()
{
	return ui.existingList;
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