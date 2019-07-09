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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *buildButton;
    QLabel *selectLabel;
    QPushButton *selectButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHelp;

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
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(140, 50, 151, 17));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 30, 121, 17));
        buildButton = new QPushButton(centralWidget);
        buildButton->setObjectName(QString::fromUtf8("buildButton"));
        buildButton->setGeometry(QRect(500, 30, 86, 23));
        selectLabel = new QLabel(centralWidget);
        selectLabel->setObjectName(QString::fromUtf8("selectLabel"));
        selectLabel->setGeometry(QRect(120, 0, 381, 16));
        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(490, 80, 75, 23));
        selectButton->setMaximumSize(QSize(75, 23));
        SubScraperGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SubScraperGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SubScraperGUIClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(SubScraperGUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        SubScraperGUIClass->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionAbout);

        retranslateUi(SubScraperGUIClass);

        QMetaObject::connectSlotsByName(SubScraperGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SubScraperGUIClass)
    {
        SubScraperGUIClass->setWindowTitle(QCoreApplication::translate("SubScraperGUIClass", "Main", nullptr));
        actionHelp->setText(QCoreApplication::translate("SubScraperGUIClass", "Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("SubScraperGUIClass", "About", nullptr));
        radioButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Use existing profile", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SubScraperGUIClass", "Build new profile", nullptr));
        buildButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Build new profile", nullptr));
        selectLabel->setText(QCoreApplication::translate("SubScraperGUIClass", "To begin getting subtitles, choose to use an existing profile or build a new one.", nullptr));
        selectButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Continue", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("SubScraperGUIClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubScraperGUIClass: public Ui_SubScraperGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRAPERGUI_H
