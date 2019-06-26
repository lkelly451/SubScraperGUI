#pragma once

#include <QGraphicsView>
#include "QMouseEvent"
#include <QtWidgets\qrubberband.h>

class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphicsView(QWidget *parent);
	~MyGraphicsView();
private slots:
	void mousePressEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);

private:
	QRubberBand* rubberBand;
	QPoint origin;
};
