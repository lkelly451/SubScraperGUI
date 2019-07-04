#pragma once

#include <QWidget>
#include "ui_Diagnostics.h"

class Diagnostics : public QWidget
{
	Q_OBJECT

public:
	Diagnostics(QWidget *parent = Q_NULLPTR);
	Diagnostics(QString inputFileName, QWidget* parent = Q_NULLPTR);
	~Diagnostics();

private:
	Ui::Diagnostics ui;
};
