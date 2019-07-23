#include "SubScraperGUI.h"
#include "StringComparer.h"


SubScraperGUI::SubScraperGUI(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Menu bar for QWidget based windows
	QMenuBar* menuBar = new QMenuBar();
	QMenu* helpMenu = new QMenu("Help");
	QAction* help = new QAction("Help", this);
	QAction* about = new QAction("About", this);
	menuBar->addMenu(helpMenu);
	helpMenu->addAction(help);
	helpMenu->addAction(about);

	this->layout()->setMenuBar(menuBar);

	connect(help, &QAction::triggered, this, &SubScraperGUI::on_help_clicked);
	connect(about, &QAction::triggered, this, &SubScraperGUI::on_about_clicked);	
}
void SubScraperGUI::on_continueButton_clicked()
{
	//move to new window depending on radio button selection
	if (selection) {
		ExistingProfiles* existingProfiles = new ExistingProfiles();
		existingProfiles->setAttribute(Qt::WA_DeleteOnClose);
		existingProfiles->show();
		this->close();
		
	}
	else {
		BuildProfile* buildProfile = new BuildProfile();
		buildProfile->setAttribute(Qt::WA_DeleteOnClose);
		buildProfile->show();
		this->close();
	}
}

void SubScraperGUI::on_help_clicked()
{
	if(!help) {
		help = new Help();
		help->setAttribute(Qt::WA_DeleteOnClose);
		help->show();
	}
}

void SubScraperGUI::on_about_clicked()
{
	if(!about) {
		about = new About();
		about->setAttribute(Qt::WA_DeleteOnClose);
		about->show();
	}
}

void SubScraperGUI::on_buildProfileRadio_toggled()
//if radio button is toggled, set selection depending on which button is checked
{
	if (ui.buildProfileRadio->isChecked()) {
		selection = 1;
	}
	else {
		selection = 0;
	}
}