#include "OutputSelect.h"
#include "HeightSelect.h"
#include "qfiledialog.h"

OutputSelect::OutputSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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