#include "SubScraperGUI.h"
#include "BuildProfile.h"
#include "ExistingProfiles.h"
#include <iostream>
#include <Help.h>
#include <About.h>
#include <qmenubar.h>

SubScraperGUI::SubScraperGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Menu bar for QWidget based windows
	QMenuBar* menuBar = new QMenuBar();
	QMenu* helpMenu = new QMenu("Help");
	QAction* help = new QAction("Help", this);
	QAction* about = new QAction("About", this);
	menuBar->addMenu(helpMenu);
	helpMenu->addAction(help);
	helpMenu->addAction(about);

	this->layout()->setMenuBar(menuBar);

	connect(help, &QAction::triggered, this, &SubScraperGUI::on_help_clicked);
	connect(about, &QAction::triggered, this, &SubScraperGUI::on_about_clicked);
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
	buildProfile->setAttribute(Qt::WA_DeleteOnClose);
	buildProfile->show();
	this->close();
}

void SubScraperGUI::on_selectButton_clicked()
{
	ExistingProfiles* existingProfiles = new ExistingProfiles();
	existingProfiles->setAttribute(Qt::WA_DeleteOnClose);
	existingProfiles->show();
	this->close();
}

void SubScraperGUI::on_help_clicked()
{
	Help* help = new Help();
	help->setAttribute(Qt::WA_DeleteOnClose);
	help->show();
}

void SubScraperGUI::on_about_clicked()
{
	About* about = new About();
	about->setAttribute(Qt::WA_DeleteOnClose);
	about->show();
}