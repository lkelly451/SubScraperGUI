#pragma once

#include <QWidget>
#include "ui_ExistingProfiles.h"

class ExistingProfiles : public QWidget
{
	Q_OBJECT

public:
	ExistingProfiles(QWidget *parent = Q_NULLPTR);
	~ExistingProfiles();
	QPushButton* getBackButton();
	QLabel* getExistingLabel();
	QListView* getExistingList();
	QPushButton* getFileSelect();
	QPushButton* getGoButton();
	QLabel* getInputLabel();
	QLineEdit* getInputLineEdit();
	QPushButton* getOutputFileSelect();
	QLabel* getOutputLabel();
	QLineEdit* getOutputLineEdit();

private slots:
	void on_backButton_clicked();
	void on_fileSelect_clicked();
	void on_outputFileSelect_clicked();
	void on_item_clicked(QListWidgetItem* item);
	void on_goButton_clicked();
private:
	Ui::ExistingProfiles ui;
	QString name;
	int widthBegin;
	int widthEnd;
	int heightBegin;
	int heightEnd;
	int singleHeight;
	int doubleHeight;
	int dropLength;
	int windowSizeLeft;
	int windowSizeRight;
	int wordConfidence;
	int lineConfidence;
	double compareThreshold;
};
