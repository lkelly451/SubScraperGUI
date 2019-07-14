#include "BuildProfile.h"


using namespace cv;
using namespace std;

BuildProfile::BuildProfile(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//the maximum valid height to set with no frame loaded is 0
	int maxValidHeight = 0;
	//as above, but with width
	int maxValidWidth = 0;

	//set validators to prevent non-numerical data and data of an invalid size being set in crop fields
	QValidator* intValidatorWidth = new QIntValidator(0, maxValidWidth, this);
	QValidator* intValidatorHeight  = new QIntValidator(0, maxValidHeight, this);
	ui.widthBegin->setValidator(intValidatorWidth);
	ui.widthEnd->setValidator(intValidatorWidth);
	ui.heightBegin->setValidator(intValidatorHeight);
	ui.heightEnd->setValidator(intValidatorHeight);

	//Menu bar for QWidget based windows
	QMenuBar* menuBar = new QMenuBar();
	QMenu* helpMenu = new QMenu("Help");
	QAction* help = new QAction("Help", this);
	QAction* about = new QAction("About", this);
	menuBar->addMenu(helpMenu);
	helpMenu->addAction(help);
	helpMenu->addAction(about);

	this->layout()->setMenuBar(menuBar);

	connect(help, &QAction::triggered, this, &BuildProfile::on_help_clicked);
	connect(about, &QAction::triggered, this, &BuildProfile::on_about_clicked);
}
//called when back button takes user back to here from HeightSelect
BuildProfile::BuildProfile(QString videoDirectory, QWidget* parent)
	: QWidget(parent)
{
	//perform usual window set up
	ui.setupUi(this);
	//the maximum valid height to set with no frame loaded is 0
	int maxValidHeight = 0;
	//as above, but with width
	int maxValidWidth = 0;

	//set validators to prevent non-numerical data and data of an invalid size being set in crop fields
	QValidator* intValidatorWidth = new QIntValidator(0, maxValidWidth, this);
	QValidator* intValidatorHeight = new QIntValidator(0, maxValidHeight, this);
	ui.widthBegin->setValidator(intValidatorWidth);
	ui.widthEnd->setValidator(intValidatorWidth);
	ui.heightBegin->setValidator(intValidatorHeight);
	ui.heightEnd->setValidator(intValidatorHeight);

	//also load in previously selected video directory and set it to preview
	ui.inputLineEdit->setText(videoDirectory);
	on_previewButton_clicked();


}

BuildProfile::~BuildProfile()
{
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
	if (ui.widthBegin->text().isEmpty() || ui.widthEnd->text().isEmpty() || ui.heightBegin->text().isEmpty() || ui.heightEnd->text().isEmpty() || ui.inputLineEdit->text().isEmpty() || frame.empty()) {
		QMessageBox messageBox;
		messageBox.warning(0, "Cannot continue without required information", "Please select a video file, click preview to check it and ensure all crop height and width parameters are filled before continuing.");
		messageBox.setFixedSize(500, 200);
	}
	else if ((ui.widthEnd->text().toInt() - ui.widthBegin->text().toInt()) > frame.cols || (ui.heightEnd->text().toInt() - ui.heightBegin->text().toInt()) > frame.rows 
		|| (ui.widthEnd->text().toInt() - ui.widthBegin->text().toInt()) <= 0 || (ui.heightEnd->text().toInt() - ui.heightBegin->text().toInt()) <= 0){
		QMessageBox messageBox;
		messageBox.warning(0, "Crop parameters outside image bounds", "Please crop an area within the image");
		messageBox.setFixedSize(500, 200);
	}
	else {
		HeightSelect* heightSelect = new HeightSelect(ui.widthBegin->text(), ui.widthEnd->text(), ui.heightBegin->text(), ui.heightEnd->text(), ui.inputLineEdit->text(), cap.get(CAP_PROP_POS_FRAMES));
		heightSelect->setAttribute(Qt::WA_DeleteOnClose);
		heightSelect->show();
		this->close();
	}
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
	//the maximum valid height to set with no frame loaded is 0
	int maxValidHeight = 0;
	//if a frame is loaded, allow anything up to the height of the image in pixels to be set
	if (!frame.empty()) {
		maxValidHeight = frame.rows;
	}
	//as above, but with width
	int maxValidWidth = 0;

	if (!frame.empty()) {
		maxValidWidth = frame.cols;
	}

	//set validators to prevent non-numerical data and data of an invalid size being set in crop fields
	QValidator* intValidatorWidth = new QIntValidator(0, maxValidWidth, this);
	QValidator* intValidatorHeight = new QIntValidator(0, maxValidHeight, this);
	ui.widthBegin->setValidator(intValidatorWidth);
	ui.widthEnd->setValidator(intValidatorWidth);
	ui.heightBegin->setValidator(intValidatorHeight);
	ui.heightEnd->setValidator(intValidatorHeight);

	filename.clear();
	vidFile.clear();
}
//leaks!
void BuildProfile::on_frameForward_clicked()
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

void BuildProfile::on_help_clicked()
{
	if (!help) {
		help = new Help();
		help->setAttribute(Qt::WA_DeleteOnClose);
		help->show();
	}
}

void BuildProfile::on_about_clicked()
{
	if (!about) {
		about = new About();
		about->setAttribute(Qt::WA_DeleteOnClose);
		about->show();
	}
}
