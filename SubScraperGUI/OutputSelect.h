#pragma once

#include <QWidget>
#include "ui_OutputSelect.h"

class OutputSelect : public QWidget
{
	Q_OBJECT

public:
	OutputSelect(QWidget *parent = Q_NULLPTR);
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

private:
	Ui::OutputSelect ui;
};
