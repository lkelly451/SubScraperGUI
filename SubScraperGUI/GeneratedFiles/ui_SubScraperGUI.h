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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubScraperGUIClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *selectLabel;
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
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectLabel = new QLabel(centralWidget);
        selectLabel->setObjectName(QString::fromUtf8("selectLabel"));

        horizontalLayout->addWidget(selectLabel);

        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        horizontalLayout->addWidget(selectButton);

        buildButton = new QPushButton(centralWidget);
        buildButton->setObjectName(QString::fromUtf8("buildButton"));

        horizontalLayout->addWidget(buildButton);

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
