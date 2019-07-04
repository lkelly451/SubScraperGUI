#include "MyGraphicsView.h"
#include <iostream>
#include <QtWidgets\qlineedit.h>
#include <QtWidgets\qrubberband.h>

using namespace std;

MyGraphicsView::MyGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
}

MyGraphicsView::~MyGraphicsView()
{
}
void MyGraphicsView::mousePressEvent(QMouseEvent* e)
{
	//hide any previously made rubber bands
	rubberBand->hide();

	//create a selection visual so the user can see the area they are targeting
	origin = e->pos();
	rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
	rubberBand->setGeometry(QRect(origin, QSize()));
	rubberBand->show();
	//get the pixel coordinates where the user clicked and set these as the beginning values for the
	//height and width of the crop
	if (e->button() == Qt::LeftButton) {
		QPoint globalPoint = this->mapFromGlobal(e->globalPos());
		QPointF mousePoint = this->mapToScene(globalPoint);
		QLineEdit* widthBegin = parent()->findChild<QLineEdit*>("widthBegin");
		widthBegin->setText(QString::number(mousePoint.x()));
		QLineEdit* heightBegin = parent()->findChild<QLineEdit*>("heightBegin");
		heightBegin->setText(QString::number(mousePoint.y()));
	}
}
void MyGraphicsView::mouseReleaseEvent(QMouseEvent* e) 
{
	
	if (e->button() == Qt::LeftButton) {
		//get the pixel coordinates where the user released a click and set these as the end values for the 
		//height and width of the crop
		QPoint globalPoint = this->mapFromGlobal(e->globalPos());
		QPointF mousePoint = this->mapToScene(globalPoint);
		QLineEdit* widthEnd = parent()->findChild<QLineEdit*>("widthEnd");
		widthEnd->setText(QString::number(mousePoint.x()));
		QLineEdit* heightEnd = parent()->findChild<QLineEdit*>("heightEnd");
		heightEnd->setText(QString::number(mousePoint.y()));
	}
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* e) 
{
	rubberBand->setGeometry(QRect(origin, e->pos()).normalized());
}
