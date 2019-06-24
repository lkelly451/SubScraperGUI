#pragma once

#include <QWidget>
#include "ui_BuildProfile.h"

class BuildProfile : public QWidget
{
	Q_OBJECT

public:
	BuildProfile(QWidget *parent = Q_NULLPTR);
	~BuildProfile();
	QPushButton* getBackButton();
	QPushButton* getContinueButton();
	QPushButton* getFileSelect();
	QPushButton* getFrameBack();
	QPushButton* getFrameForward();
	QGraphicsView* getFramePreview();
	QLabel* getInputLabel();
	QLineEdit* getInputLineEdit();
private slots:
	void on_backButton_clicked();
	void on_continueButton_clicked();
	void on_fileSelect_clicked();
private:
	Ui::BuildProfile ui;
};
