#pragma once

#include <QWidget>
#include "ui_Help.h"

class Help : public QWidget
{
	Q_OBJECT

public:
	Help(QWidget *parent = Q_NULLPTR);
	~Help();

private:
	Ui::Help ui;
};
