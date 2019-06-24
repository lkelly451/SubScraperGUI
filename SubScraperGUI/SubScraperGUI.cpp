#include "SubScraperGUI.h"
#include "BuildProfile.h"
#include "ExistingProfiles.h"
#include <iostream>

SubScraperGUI::SubScraperGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QPushButton* SubScraperGUI::getBuildButton()
{
	return ui.buildButton;
}

QPushButton* SubScraperGUI::getSelectButton()
{
	return ui.selectButton;
}

QLabel* SubScraperGUI::getSelectLabel()
{
	return ui.selectLabel;
}

void SubScraperGUI::on_buildButton_clicked()
{
	BuildProfile* buildProfile = new BuildProfile();
	buildProfile->show();
	this->close();
}

void SubScraperGUI::on_selectButton_clicked()
{
	ExistingProfiles* existingProfiles = new ExistingProfiles();
	existingProfiles->show();
	this->close();
}