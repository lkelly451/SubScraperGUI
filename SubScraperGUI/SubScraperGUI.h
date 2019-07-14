#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SubScraperGUI.h"
#include <Help.h>
#include <About.h>
#include "BuildProfile.h"
#include "ExistingProfiles.h"
#include <iostream>
#include <qmenubar.h>

class SubScraperGUI : public QMainWindow
{
	Q_OBJECT

public:
	SubScraperGUI(QWidget *parent = Q_NULLPTR);

private slots:
	void on_help_clicked();
	void on_about_clicked();
	void on_continueButton_clicked();
	void on_buildProfileRadio_toggled();
private:
	Ui::SubScraperGUIClass ui;
	bool selection = 0;
	Help* help = NULL;
	About* about = NULL;
};
