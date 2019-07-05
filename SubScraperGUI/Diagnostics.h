#pragma once

#include <QWidget>
#include "ui_Diagnostics.h"

class Diagnostics : public QWidget
{
	Q_OBJECT

public:
	Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, 
		int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, std::string inputFileName, std::string outputFileName, bool autoDetectHeights, QWidget *parent = Q_NULLPTR);
	Diagnostics(QString inputFileName, QWidget* parent = Q_NULLPTR);
	~Diagnostics();
	void showEvent(QShowEvent* ev);

signals: 
	void windowShown();

private slots:
	void on_windowShown();

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
};