#include "BuildProfile.h"
#include "SubScraperGUI.h"
#include "HeightSelect.h"
#include "qfiledialog.h"
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <qgraphicspixmapitem>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <fstream>


using namespace cv;
using namespace std;

BuildProfile::BuildProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

BuildProfile::~BuildProfile()
{
}

QPushButton* BuildProfile::getBackButton()
{
	return ui.backButton;
}

QPushButton* BuildProfile::getContinueButton()
{
	return ui.continueButton;
}

QPushButton* BuildProfile::getFileSelect()
{
	return ui.fileSelect;
}

QPushButton* BuildProfile::getFrameBack()
{
	return ui.frameBack;
}

QPushButton* BuildProfile::getFrameForward()
{
	return ui.frameForward;
}

QGraphicsView* BuildProfile::getFramePreview()
{
	return ui.framePreview;
}

QLabel* BuildProfile::getInputLabel()
{
	return ui.inputLabel;
}

QLineEdit* BuildProfile::getInputLineEdit()
{
	return ui.inputLineEdit;
}

void BuildProfile::on_backButton_clicked()
{
	SubScraperGUI* subScraperGUI = new SubScraperGUI();
	subScraperGUI->setAttribute(Qt::WA_DeleteOnClose);
	subScraperGUI->show();
	this->close();
}

void BuildProfile::on_continueButton_clicked()
{
	HeightSelect* heightSelect = new HeightSelect();
	heightSelect->setAttribute(Qt::WA_DeleteOnClose);
	heightSelect->show();
	this->close();
}

void BuildProfile::on_fileSelect_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
	this, tr("Open File"), "C://", tr("Videos (*.mkv *.avi *.mp4 *.wmv)"));
	ui.inputLineEdit->setText(filename);
}


void BuildProfile::on_previewButton_clicked()
{
	//get video file directory from inputLineEdit
	QString filename = ui.inputLineEdit->text();
	string vidFile = filename.toLocal8Bit().constData();

	//open video (if not already open)
	if (!cap.isOpened()) {
		cap.open(vidFile);
	}

	//get frame from video and show on preview zone
	if (cap.isOpened()) {
		cap >> frame;
		imwrite("frame.jpeg", frame);
		QImage image("frame.jpeg");
		scene = new QGraphicsScene(this);
		ui.framePreview->scene()->deleteLater();
		ui.framePreview->setScene(scene);
		item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.framePreview->show();
	}
	
	filename.clear();
	vidFile.clear();
}
//leaks!
void BuildProfile::on_frameForward_clicked()
{
	//replace preview with a more advanced frame when frameForward is clicked
	if (cap.isOpened()) {
		for (size_t i = 0; i < 5; i++) {
			cap.grab();
		}

		cap >> frame;
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
//leaks!
void BuildProfile::on_frameBack_clicked()
{
	//replace preview with a less advanced frame (if possible) when frameBack is clicked
	if (cap.isOpened()) {
		int position = cap.get(CAP_PROP_POS_FRAMES);
		if (position >= 6) {
			cap.set(CAP_PROP_POS_FRAMES, (position - 5));
			cap >> frame;
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