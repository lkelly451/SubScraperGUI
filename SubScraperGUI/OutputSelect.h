#pragma once

#include <QWidget>
#include "ui_OutputSelect.h"
#include <Help.h>
#include <About.h>
#include "HeightSelect.h"
#include "qvalidator.h"
#include <Diagnostics.h>
#include "qfiledialog.h"
#include <iostream>
#include <fstream>
#include <qmenubar.h>
#include <QtWidgets\qmessagebox.h>

class OutputSelect : public QWidget
{
	Q_OBJECT

public:
	OutputSelect(QWidget *parent = Q_NULLPTR);
	OutputSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString singleHeight, QString doubleHeight, QString inputFileName, bool autoBoxDetect, int width, double position, QWidget* parent = Q_NULLPTR);
	~OutputSelect();

private slots:
	void on_backButton_clicked();
	void on_outputFileSelect_clicked();
	void on_goButton_clicked();
	void on_saveProfileButton_clicked();
	void on_lengthFilterLineEdit_editingFinished();
	void on_leftWindowLineEdit_editingFinished();
	void on_rightWindowLineEdit_editingFinished();
	void on_wordConfidenceLineEdit_editingFinished();
	void on_lineConfidenceLineEdit_editingFinished();
	void on_compareThresholdLineEdit_editingFinished();
	void on_dupeThresholdLineEdit_editingFinished();
	void on_help_clicked();
	void on_about_clicked();

private:
	Ui::OutputSelect ui;
	QString widthBegin;
	QString widthEnd;
	QString heightBegin;
	QString heightEnd;
	QString singleHeight;
	QString doubleHeight;
	QString dropLength;
	QString windowSizeLeft;
	QString windowSizeRight;
	QString wordConfidence;
	QString lineConfidence;
	QString compareThreshold;
	QString dupeThreshold;
	QString inputFileName;
	bool autoDetectHeights;
	int width;
	double position;
	Help* help = NULL;
	About* about = NULL;
};
