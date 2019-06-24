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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubScraperGUIClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *selectLabel;
    QGridLayout *gridLayout;
    QPushButton *selectButton;
    QPushButton *buildButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SubScraperGUIClass)
    {
        if (SubScraperGUIClass->objectName().isEmpty())
            SubScraperGUIClass->setObjectName(QString::fromUtf8("SubScraperGUIClass"));
        SubScraperGUIClass->resize(600, 121);
        centralWidget = new QWidget(SubScraperGUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 20, 221, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        selectLabel = new QLabel(widget);
        selectLabel->setObjectName(QString::fromUtf8("selectLabel"));

        verticalLayout->addWidget(selectLabel);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selectButton = new QPushButton(widget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        gridLayout->addWidget(selectButton, 0, 0, 1, 1);

        buildButton = new QPushButton(widget);
        buildButton->setObjectName(QString::fromUtf8("buildButton"));

        gridLayout->addWidget(buildButton, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        SubScraperGUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SubScraperGUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SubScraperGUIClass->setStatusBar(statusBar);

        retranslateUi(SubScraperGUIClass);

        QMetaObject::connectSlotsByName(SubScraperGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *SubScraperGUIClass)
    {
        SubScraperGUIClass->setWindowTitle(QCoreApplication::translate("SubScraperGUIClass", "SubScraperGUI", nullptr));
        selectLabel->setText(QCoreApplication::translate("SubScraperGUIClass", "Select an existing profile or build a new one.", nullptr));
        selectButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Select existing profile", nullptr));
        buildButton->setText(QCoreApplication::translate("SubScraperGUIClass", "Build new profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubScraperGUIClass: public Ui_SubScraperGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSCRAPERGUI_H
