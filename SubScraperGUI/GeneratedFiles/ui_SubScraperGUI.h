/********************************************************************************
** Form generated from reading UI file 'SubScraperGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSCRAPERGUI_H
#define UI_SUBSCRAPERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubScraperGUIClass
{
public:
    QAction *actionHelp;
    QAction *actionAbout;
    QWidget *centralWidget;
    QRadioButton *buildProfileRadio;
    QRadioButton *existingProfileRadio;
    QLabel *selectLabel;
    QPushButton *continueButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SubScraperGUIClass)
    {
        if (SubScraperGUIClass->objectName().isEmpty())
            SubScraperGUIClass->setObjectName(QString::fromUtf8("SubScraperGUIClass"));
        SubScraperGUIClass->resize(600, 155);
        actionHelp = new QAction(SubScraperGUIClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(SubScraperGUIClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(SubScraperGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        buildProfileRadio = new QRadioButton(centralWidget);
        buildProfileRadio->setObjectName(QString::fromUtf8("buildProfileRadio"));
        buildProfileRadio->setGeometry(QRect(140, 50, 151, 17));
        existingProfileRadio = new QRadioButton(centralWidget);
        existingProfileRadio->setObjectName(QString::fromUtf8("existingProfileRadio"));
        existingProfileRadio->setGeometry(QRect(140, 30, 121, 17));
        existingProfileRadio->setChecked(true);
        selectLabel = new QLabel(centralWidget);
        selectLabel->setObjectName(QString::fromUtf8("selectLabel"));
        selectLabel->setGeometry(QRect(120, 0, 381, 16));
        continueButton = new QPushButton(centralWidget);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(490, 80, 75, 23));
        continueButton->setMaximumSize(QSize(75, 23));
        SubScraperGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SubScraperGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SubScraperGUIClass->setStatusBar(statusBar);

        retranslateUi(SubScraperGUIClass);

        QMetaObject::connectSlotsByName(SubScraperGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SubScraperGUIClass)
    {
        SubScraperGUIClass->setWindowTitle(QCoreApplication::translate("SubScraperGUIClass", "SubScraper", nullptr));
        actionHelp->setText(QCoreApplication::translate("SubScraperGUIClass", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("SubScraperGUIClass", "About", nullptr));
        buildProfileRadio->setText(QCoreApplication::translate("SubScraperGUIClass", "Use existing profile", nullptr));
        existingProfileRadio->setText(QCoreApplication::translate("SubScraperGUIClass", "Build new profile", nullptr));
        selectLabel->setText(QCoreApplication::translate("SubScraperGUIClass", "To begin getting subtitles, choose to use an existing profile or build a new one.", nullptr));
        continueButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubScraperGUIClass: public Ui_SubScraperGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRAPERGUI_H
