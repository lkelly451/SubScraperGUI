#include "HeightSelect.h"
#include "BuildProfile.h"
#include "OutputSelect.h"
#include "qvalidator.h"
#include <opencv2/imgcodecs.hpp>
#include "QGraphicsPixmapItem"
#include <iostream>
#include <Frame.h>

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
}

HeightSelect::~HeightSelect()
{
}

QCheckBox* HeightSelect::getAutoCheckBox()
{
	return ui.autoCheckBox;
}

QLabel* HeightSelect::getAutoLabel()
{
	return ui.autoLabel;
}

QPushButton* HeightSelect::getBackButton()
{
	return ui.backButton;
}

QPushButton* HeightSelect::getContinueButton()
{
	return ui.continueButton;
}

QLabel* HeightSelect::getDoubleLabel()
{
	return ui.doubleLabel;
}

QLineEdit* HeightSelect::getDoubleLineEdit()
{
	return ui.doubleLineEdit;
}

QPushButton* HeightSelect::getFrameBack()
{
	return ui.frameBack;
}

QPushButton* HeightSelect::getFrameForward()
{
	return ui.frameForward;
}

QGraphicsView* HeightSelect::getFramePreview()
{
	return ui.framePreview;
}

QLabel* HeightSelect::getSingleLabel()
{
	return ui.singleLabel;
}

QLineEdit* HeightSelect::getSingleLineEdit()
{
	return ui.singleLineEdit;
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
			ui.continueWarning->setText("Box height cannot be larger than the image!");
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
		ui.continueWarning->setText("Please input heights for single and double subtitle boxes or check auto detect box heights before continuing.");
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

