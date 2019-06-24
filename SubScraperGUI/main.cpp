#include "SubScraperGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SubScraperGUI w;
	w.show();
	return a.exec();
}
