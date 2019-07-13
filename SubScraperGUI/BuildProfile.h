#pragma once

#include <QWidget>
#include "ui_BuildProfile.h"
#include <opencv2/videoio.hpp>
#include "QMouseEvent"
#include <QtWidgets/QMainWindow>
#include <Help.h>
#include <About.h>

class BuildProfile : public QWidget
{
	Q_OBJECT

public:
	BuildProfile(QWidget *parent = Q_NULLPTR);
	BuildProfile(QString videoDirectory, QWidget* parent = Q_NULLPTR);
	~BuildProfile();


private slots:
	void on_backButton_clicked();
	void on_continueButton_clicked();
	void on_fileSelect_clicked();
	void on_previewButton_clicked();
	void on_frameForward_clicked();
	void on_frameBack_clicked();
	void on_help_clicked();
	void on_about_clicked();

private:
	Ui::BuildProfile ui;
	cv::VideoCapture cap;
	cv::Mat frame;
	QGraphicsScene* scene;
	QGraphicsPixmapItem* item;
	Help* help = NULL;
	About* about = NULL;
};
