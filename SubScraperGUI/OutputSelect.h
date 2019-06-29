#pragma once

#include <QWidget>
#include "ui_OutputSelect.h"

class OutputSelect : public QWidget
{
	Q_OBJECT

public:
	OutputSelect(QWidget *parent = Q_NULLPTR);
	OutputSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString singleHeight, QString doubleHeight, QWidget* parent = Q_NULLPTR);
	~OutputSelect();
	QPushButton* getBackButton();
	QPushButton* getGoButton();
	QPushButton* getOutputFileSelect();
	QLabel* getOutputLabel();
	QLineEdit* getOutputLineEdit();
	QPushButton* getTranscriptFileSelect();
	QLabel* getTranscriptLabel();
	QLineEdit* getTranscriptLineEdit();

private slots:
	void on_backButton_clicked();
	void on_outputFileSelect_clicked();
	void on_transcriptFileSelect_clicked();
	void on_goButton_clicked();
	void on_saveProfileButton_clicked();
	void on_lengthFilterLineEdit_editingFinished();
	void on_leftWindowLineEdit_editingFinished();
	void on_rightWindowLineEdit_editingFinished();
	void on_wordConfidenceLineEdit_editingFinished();
	void on_lineConfidenceLineEdit_editingFinished();
	void on_compareThresholdLineEdit_editingFinished();

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
};
