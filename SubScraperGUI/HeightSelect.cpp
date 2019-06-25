#include "HeightSelect.h"
#include "BuildProfile.h"
#include "OutputSelect.h"

HeightSelect::HeightSelect(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

HeightSelect::~HeightSelect()
{
}

QCheckBox* HeightSelect::getAutoCheckBox()
{
	return ui.autoCheckBox;
}

QLabel* HeightSelect::getAutoLabel()
{
	return ui.autoLabel;
}

QPushButton* HeightSelect::getBackButton()
{
	return ui.backButton;
}

QPushButton* HeightSelect::getContinueButton()
{
	return ui.continueButton;
}

QLabel* HeightSelect::getDoubleLabel()
{
	return ui.doubleLabel;
}

QLineEdit* HeightSelect::getDoubleLineEdit()
{
	return ui.doubleLineEdit;
}

QPushButton* HeightSelect::getFrameBack()
{
	return ui.frameBack;
}

QPushButton* HeightSelect::getFrameForward()
{
	return ui.frameForward;
}

QGraphicsView* HeightSelect::getFramePreview()
{
	return ui.framePreview;
}

QLabel* HeightSelect::getSingleLabel()
{
	return ui.singleLabel;
}

QLineEdit* HeightSelect::getSingleLineEdit()
{
	return ui.singleLineEdit;
}

void HeightSelect::on_backButton_clicked()
{
	BuildProfile* buildProfile = new BuildProfile();
	buildProfile->setAttribute(Qt::WA_DeleteOnClose);
	buildProfile->show();
	this->close();
}

void HeightSelect::on_continueButton_clicked() 
{
	OutputSelect* outputSelect = new OutputSelect();
	outputSelect->setAttribute(Qt::WA_DeleteOnClose);
	outputSelect->show();
	this->close();
}