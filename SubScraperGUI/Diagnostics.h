#pragma once

#include <QWidget>
#include "ui_Diagnostics.h"
#include <Video.h>

class Diagnostics : public QWidget
{
	Q_OBJECT

public:
	Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, 
		int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, std::string inputFileName, std::string outputFileName, bool autoDetectHeights, QWidget *parent = Q_NULLPTR);
	Diagnostics(QString inputFileName, QWidget* parent = Q_NULLPTR);
	~Diagnostics();

private slots:
	void on_cancelButton_clicked();
	void on_mainButton_clicked();
	void on_exitButton_clicked();
	void onVideoFinished();
	void onProgressUpdated(int progress);

private:
	Ui::Diagnostics ui;
	int singleHeight;
	int doubleHeight;
	int cropHeightStart;
	int cropHeightEnd;
	int cropWidthStart;
	int cropWidthEnd;
	int dropLength;
	int windowSizeLeft;
	int windowSizeRight;
	int wordConfidence;
	int lineConfidence;
	int dupeThreshold;
	double compareThreshold;
	std::string inputFileName;
	std::string outputFileName;
	bool autoDetectHeights;
	Video* video;
	
};
