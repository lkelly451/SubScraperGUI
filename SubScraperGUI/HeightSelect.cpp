#include "HeightSelect.h"
#include "BuildProfile.h"
#include "OutputSelect.h"
#include "qvalidator.h"
#include <opencv2/imgcodecs.hpp>
#include "QGraphicsPixmapItem"
#include <iostream>
#include <Frame.h>
#include <qmenubar.h>
#include <QtWidgets\qmessagebox.h>


using namespace std;
using namespace cv;

HeightSelect::HeightSelect(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
}
HeightSelect::HeightSelect(QString widthBegin, QString widthEnd, QString heightBegin, QString heightEnd, QString videoDirectory, double position, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->widthBegin = widthBegin;
	this->widthEnd = widthEnd;
	this->heightBegin = heightBegin;
	this->heightEnd = heightEnd;
	this->videoDirectory = videoDirectory;
	this->position = position;
	//open video file from directory identified in previous window
	string vidFile = this->videoDirectory.toLocal8Bit();
	cap.open(vidFile);
	//set position in video to position it was when user switched screens
	cap.set(CAP_PROP_POS_FRAMES, this->position);
	cap >> frame;
	//use the width and height data identified in the previous window to make a region of interest
	frame = frame.rowRange(this->heightBegin.toInt(), this->heightEnd.toInt());
	frame = frame.colRange(this->widthBegin.toInt(), this->widthEnd.toInt());
	imwrite("frame.jpeg", frame);
	QImage image("frame.jpeg");
	//place the region of interest in the frame preview 
	scene = new QGraphicsScene(this);
	ui.framePreview->scene()->deleteLater();
	ui.framePreview->setScene(scene);
	item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
	scene->addItem(item);
	ui.framePreview->show();

	//the maximum box height is the height of the image
	int maxBoxHeight = frame.rows;
	//set validator to prevent non-numerical data or excessive values being input into box height fields
	QValidator* intValidatorBoxHeights = new QIntValidator(0, maxBoxHeight, this);
	ui.singleLineEdit->setValidator(intValidatorBoxHeights);
	ui.doubleLineEdit->setValidator(intValidatorBoxHeights);

	//Menu bar for QWidget based windows
	QMenuBar* menuBar = new QMenuBar();
	QMenu* helpMenu = new QMenu("Help");
	QAction* help = new QAction("Help", this);
	QAction* about = new QAction("About", this);
	menuBar->addMenu(helpMenu);
	helpMenu->addAction(help);
	helpMenu->addAction(about);

	this->layout()->setMenuBar(menuBar);

	connect(help, &QAction::triggered, this, &HeightSelect::on_help_clicked);
	connect(about, &QAction::triggered, this, &HeightSelect::on_about_clicked);
}

HeightSelect::~HeightSelect()
{
}

void HeightSelect::on_backButton_clicked()
{
	BuildProfile* buildProfile = new BuildProfile(videoDirectory);
	buildProfile->setAttribute(Qt::WA_DeleteOnClose);
	buildProfile->show();
	this->close();
}

void HeightSelect::on_continueButton_clicked() 
{
	bool autoBoxDetect = false;
	if (ui.autoCheckBox->isChecked()) {
		autoBoxDetect = true;
	}
	if (ui.autoCheckBox->isChecked() || !ui.doubleLineEdit->text().isEmpty() && !ui.doubleLineEdit->text().isEmpty()) {
		if (ui.doubleLineEdit->text().toInt() > frame.cols || ui.singleLineEdit->text().toInt() > frame.cols) {
			QMessageBox messageBox;
			messageBox.warning(0, "Box height cannot be larger than the image", "Please specify a box height that is within the image boundaries");
			messageBox.setFixedSize(500, 200);
		}
		else if (ui.doubleLineEdit->text().toInt() == 0 || ui.singleLineEdit->text().toInt()==0) {
			QMessageBox messageBox;
			messageBox.warning(0, "Box heights cannot be zero", "Please input a height for single and double line boxes that is greater than zero");
			messageBox.setFixedSize(500, 200);
		}
		else {
			cout << "At height select: " << autoBoxDetect << endl;
			OutputSelect* outputSelect = new OutputSelect(this->widthBegin, this->widthEnd, this->heightBegin, this->heightEnd, ui.singleLineEdit->text(), ui.doubleLineEdit->text(), videoDirectory, autoBoxDetect, frame.rows, position);
			outputSelect->setAttribute(Qt::WA_DeleteOnClose);
			outputSelect->show();
			this->close();
		}
	}
	else {
		QMessageBox messageBox;
		messageBox.warning(0, "Cannot continue without required information", "Please input heights for single and double subtitle boxes or check auto-detect box heights before continuing");
		messageBox.setFixedSize(500, 200);
	}
}

void HeightSelect::on_frameForward_clicked()
{
	//get the total number of frames in the video
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);
	//get (rounded) 0.25% of that number
	int frameAdvance = totalFrames / 400;
	//replace preview with a more advanced frame when frameForward is clicked
	if (cap.isOpened()) {
		for (size_t i = 0; i < frameAdvance; i++) {
			cap.grab();
		}

		cap >> frame;
		//use the width and height data identified in the previous window to make a region of interest
		frame = frame.rowRange(this->heightBegin.toInt(), this->heightEnd.toInt());
		frame = frame.colRange(this->widthBegin.toInt(), this->widthEnd.toInt());
		imwrite("frame.jpeg", frame);
		QImage image("frame.jpeg");
		scene = new QGraphicsScene(this);
		ui.framePreview->scene()->deleteLater();
		ui.framePreview->setScene(scene);
		item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.framePreview->show();
	}

}

void HeightSelect::on_frameBack_clicked() 
{
	//get the total number of frames in the video
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);
	//get (rounded) 0.25% of that number
	int frameBack = totalFrames / 400;
	//replace preview with a less advanced frame (if possible) when frameBack is clicked
	if (cap.isOpened()) {
		double position = cap.get(CAP_PROP_POS_FRAMES);
		if (position >= frameBack) {
			cap.set(CAP_PROP_POS_FRAMES, (position - (double)frameBack));
			cap >> frame;
			//use the width and height data identified in the previous window to make a region of interest
			frame = frame.rowRange(this->heightBegin.toInt(), this->heightEnd.toInt());
			frame = frame.colRange(this->widthBegin.toInt(), this->widthEnd.toInt());
			imwrite("frame.jpeg", frame);
			QImage image("frame.jpeg");
			scene = new QGraphicsScene(this);
			ui.framePreview->scene()->deleteLater();
			ui.framePreview->setScene(scene);
			item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
			scene->addItem(item);
			ui.framePreview->show();
		}
	}

}

void HeightSelect::on_singleGetHeight_clicked()
{
	vector<cv::Vec2i> heightBoundaries;
	vector <cv::Vec4i> lines;
	Mat draw;
	int height;
	//construct frame 
	Frame f(frame);
	//detect box and get height
	f.detectSingleBoxes(height, lines);
	//set height on singleLineEdit
	ui.singleLineEdit->setText(QString::number(height));
	//draw potential subtitle box lines onto image for user to view
	if (lines.size() == 2) {
		f.drawHough(frame, lines);
		imwrite("frame.jpeg", frame);
		QImage image("frame.jpeg");
		scene = new QGraphicsScene(this);
		ui.framePreview->scene()->deleteLater();
		ui.framePreview->setScene(scene);
		item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.framePreview->show();
	}	
}

void HeightSelect::on_doubleGetHeight_clicked()
{
	vector<cv::Vec2i> heightBoundaries;
	vector <cv::Vec4i> lines;
	Mat draw;
	int height;
	//construct frame 
	Frame f(frame);
	//detect box
	f.detectDoubleBoxes(height, lines);
	//set height on doubleLineEdit
	ui.doubleLineEdit->setText(QString::number(height));
	//draw potential subtitle box lines onto image for user to view
	if (lines.size() == 2) {
		f.drawHough(frame, lines);
		imwrite("frame.jpeg", frame);
		QImage image("frame.jpeg");
		scene = new QGraphicsScene(this);
		ui.framePreview->scene()->deleteLater();
		ui.framePreview->setScene(scene);
		item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.framePreview->show();
	}
}

void HeightSelect::on_help_clicked()
{
	if (!help) {
		help = new Help();
		help->setAttribute(Qt::WA_DeleteOnClose);
		help->show();
	}
}

void HeightSelect::on_about_clicked()
{
	if (!about) {
		about = new About();
		about->setAttribute(Qt::WA_DeleteOnClose);
		about->show();
	}
}