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
	QPushButton* getTranscriptFileSelect();
	QLabel* getTranscriptLabel();
	QLineEdit* getTranscriptLineEdit();

private slots:
	void on_backButton_clicked();
	void on_fileSelect_clicked();
	void on_outputFileSelect_clicked();
	void on_transcriptFileSelect_clicked();
private:
	Ui::ExistingProfiles ui;
};
