#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SubScraperGUI.h"

class SubScraperGUI : public QMainWindow
{
	Q_OBJECT

public:
	SubScraperGUI(QWidget *parent = Q_NULLPTR);
	QPushButton* getBuildButton();
	QPushButton* getSelectButton();
	QLabel* getSelectLabel();

private slots:
	void on_buildButton_clicked();
	void on_selectButton_clicked();
private:
	Ui::SubScraperGUIClass ui;
};
