#include "Diagnostics.h"
#include <opencv2/videoio.hpp>

using namespace cv;
Diagnostics::Diagnostics(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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
