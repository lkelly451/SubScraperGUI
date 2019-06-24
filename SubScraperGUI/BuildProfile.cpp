#include "BuildProfile.h"
#include "SubScraperGUI.h"
#include "HeightSelect.h"
#include "qfiledialog.h"

BuildProfile::BuildProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

BuildProfile::~BuildProfile()
{
}

QPushButton* BuildProfile::getBackButton()
{
	return ui.backButton;
}

QPushButton* BuildProfile::getContinueButton()
{
	return ui.continueButton;
}

QPushButton* BuildProfile::getFileSelect()
{
	return ui.fileSelect;
}

QPushButton* BuildProfile::getFrameBack()
{
	return ui.frameBack;
}

QPushButton* BuildProfile::getFrameForward()
{
	return ui.frameForward;
}

QGraphicsView* BuildProfile::getFramePreview()
{
	return ui.framePreview;
}

QLabel* BuildProfile::getInputLabel()
{
	return ui.inputLabel;
}

QLineEdit* BuildProfile::getInputLineEdit()
{
	return ui.inputLineEdit;
}

void BuildProfile::on_backButton_clicked()
{
	SubScraperGUI* subScraperGUI = new SubScraperGUI();
	subScraperGUI->show();
	this->close();
}

void BuildProfile::on_continueButton_clicked()
{
	HeightSelect* heightSelect = new HeightSelect();
	heightSelect->show();
	this->close();
}

void BuildProfile::on_fileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
	this, tr("Open File"), "C://", tr("Videos (*.mkv *.avi *.mp4 *.wmv)"));
	ui.inputLineEdit->setText(filename);
}