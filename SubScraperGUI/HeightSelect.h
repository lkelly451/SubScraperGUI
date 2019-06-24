#pragma once

#include <QWidget>
#include "ui_HeightSelect.h"

class HeightSelect : public QWidget
{
	Q_OBJECT

public:
	HeightSelect(QWidget *parent = Q_NULLPTR);
	~HeightSelect();
	QCheckBox* getAutoCheckBox();
	QLabel* getAutoLabel();
	QPushButton* getBackButton();
	QPushButton* getContinueButton();
	QLabel* getDoubleLabel();
	QLineEdit* getDoubleLineEdit();
	QPushButton* getFrameBack();
	QPushButton* getFrameForward();
	QGraphicsView* getFramePreview();
	QLabel* getSingleLabel();
	QLineEdit* getSingleLineEdit();
private slots:
	void on_backButton_clicked();
	void on_continueButton_clicked();
private:
	Ui::HeightSelect ui;
};
