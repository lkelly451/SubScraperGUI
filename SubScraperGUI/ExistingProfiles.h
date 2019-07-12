#pragma once

#include <QWidget>
#include "ui_ExistingProfiles.h"

class ExistingProfiles : public QWidget
{
	Q_OBJECT

public:
	ExistingProfiles(QWidget *parent = Q_NULLPTR);
	~ExistingProfiles();

private slots:
	void on_backButton_clicked();
	void on_fileSelect_clicked();
	void on_outputFileSelect_clicked();
	void on_item_clicked(QListWidgetItem* item);
	void on_goButton_clicked();
	void on_deleteProfileButton_clicked();
	void on_help_clicked();
	void on_about_clicked();
private:
	Ui::ExistingProfiles ui;
	QString name;
	QString inputFileName;
	QString outputFileName;
	int cropWidthStart;
	int cropWidthEnd;
	int cropHeightStart;
	int cropHeightEnd;
	int singleHeight;
	int doubleHeight;
	int dropLength;
	int windowSizeLeft;
	int windowSizeRight;
	int wordConfidence;
	int lineConfidence;
	int dupeThreshold;
	double compareThreshold;
	bool autoDetectHeights;
};
