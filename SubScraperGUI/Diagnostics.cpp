#include "Diagnostics.h"
#include <opencv2/videoio.hpp>
#include <SubScraper.h>

using namespace cv;
using namespace std;
Diagnostics::Diagnostics(int singleHeight, int doubleHeight, int cropHeightStart, int cropHeightEnd, int cropWidthStart, int cropWidthEnd, int dropLength, int windowSizeLeft, 
	int windowSizeRight, int wordConfidence, int lineConfidence, int dupeThreshold, double compareThreshold, string inputFileName, string outputFileName, bool autoDetectHeights, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->singleHeight = singleHeight;
	this->doubleHeight = doubleHeight;
	this->cropHeightStart = cropHeightStart;
	this->cropHeightEnd = cropHeightEnd;
	this->cropWidthStart = cropWidthStart;
	this->cropWidthEnd = cropWidthEnd;
	this->dropLength = dropLength;
	this->windowSizeLeft = windowSizeLeft;
	this->windowSizeRight = windowSizeRight;
	this->wordConfidence = wordConfidence;
	this->lineConfidence = lineConfidence;
	this->dupeThreshold = dupeThreshold;
	this->compareThreshold = compareThreshold;
	this->inputFileName = inputFileName;
	this->outputFileName = outputFileName;
	this->autoDetectHeights = autoDetectHeights;

	connect(this, SIGNAL(windowShown()), this, SLOT(on_windowShown()), Qt::ConnectionType(Qt::QueuedConnection));
}

Diagnostics::Diagnostics(QString inputFileName, QWidget* parent)
	: QWidget(parent)
{
	VideoCapture cap;
	ui.setupUi(this);
	ui.progressBar->setMinimum(0);
	ui.progressBar->setMaximum(cap.get(CAP_PROP_FRAME_COUNT));
}

Diagnostics::~Diagnostics()
{
}

void Diagnostics::showEvent(QShowEvent* ev) {
	QWidget::showEvent(ev);
	QApplication::processEvents();
	emit windowShown();
}

void Diagnostics::on_windowShown() {
	SubScraper subscraper;
	subscraper.getSubs(inputFileName, outputFileName, singleHeight, doubleHeight, cropHeightStart, cropHeightEnd, cropWidthStart, cropWidthEnd, dropLength,
		windowSizeLeft, windowSizeRight, wordConfidence, lineConfidence, compareThreshold, dupeThreshold, autoDetectHeights, ui.progressBar);
}
