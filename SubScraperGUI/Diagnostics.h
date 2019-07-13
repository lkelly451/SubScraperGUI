#pragma once

#include <QWidget>
#include "ui_Diagnostics.h"
#include <Video.h>

class Diagnostics : public QWidget
{
	Q_OBJECT

public:
	Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, 
		int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, std::string inputFileName, std::string outputFileName, bool autoDetectHeights, bool multiAnalysis, QWidget *parent = Q_NULLPTR);
	Diagnostics(QString inputFileName, QWidget* parent = Q_NULLPTR);
	~Diagnostics();

private slots:
	void on_cancelButton_clicked();
	void on_mainButton_clicked();
	void on_exitButton_clicked();
	void onVideoFinished();
	void onProgressUpdated(int progress);
	void onErrorEncountered(QString errorMessage);
	void getCurrentStep(QString currentStep);

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
	bool multiAnalysis;
	bool multiCancel = false;
	Video* video;
	std::vector<std::string> fileNames;
	std::vector<std::string> outputFileNames;
	int currentFile = 0;
	int numberOfFiles = 0;
	
};
