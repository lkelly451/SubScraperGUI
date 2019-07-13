#pragma once

#include <QWidget>
#include "ui_HeightSelect.h"
#include <opencv2/videoio.hpp>
#include <Help.h>
#include <About.h>

class HeightSelect : public QWidget
{
	Q_OBJECT

public:
	HeightSelect(QWidget* parent = Q_NULLPTR);
	HeightSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString videoDirectory, double position, QWidget* parent = Q_NULLPTR);
	~HeightSelect();
private slots:
	void on_backButton_clicked();
	void on_continueButton_clicked();
	void on_frameForward_clicked();
	void on_frameBack_clicked();
	void on_singleGetHeight_clicked();
	void on_doubleGetHeight_clicked();
	void on_help_clicked();
	void on_about_clicked();
private:
	Ui::HeightSelect ui;
	QString widthBegin;
	QString widthEnd;
	QString heightBegin;
	QString heightEnd;
	QString videoDirectory;
	cv::VideoCapture cap;
	QGraphicsScene* scene;
	QGraphicsPixmapItem* item;
	cv::Mat frame;
	double position;
	Help* help = NULL;
	About* about = NULL;

};
