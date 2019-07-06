/********************************************************************************
** Form generated from reading UI file 'Diagnostics.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICS_H
#define UI_DIAGNOSTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diagnostics
{
public:
    QProgressBar *progressBar;
    QLabel *progressBarLabel;
    QLabel *outputLabel;
    QPushButton *exitButton;
    QPushButton *mainButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Diagnostics)
    {
        if (Diagnostics->objectName().isEmpty())
            Diagnostics->setObjectName(QString::fromUtf8("Diagnostics"));
        Diagnostics->resize(400, 300);
        progressBar = new QProgressBar(Diagnostics);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(140, 110, 141, 23));
        progressBar->setValue(0);
        progressBarLabel = new QLabel(Diagnostics);
        progressBarLabel->setObjectName(QString::fromUtf8("progressBarLabel"));
        progressBarLabel->setGeometry(QRect(70, 110, 61, 16));
        outputLabel = new QLabel(Diagnostics);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setGeometry(QRect(140, 160, 111, 20));
        exitButton = new QPushButton(Diagnostics);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(290, 250, 75, 23));
        mainButton = new QPushButton(Diagnostics);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));
        mainButton->setGeometry(QRect(20, 250, 75, 23));
        cancelButton = new QPushButton(Diagnostics);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(290, 110, 75, 23));

        retranslateUi(Diagnostics);

        QMetaObject::connectSlotsByName(Diagnostics);
    } // setupUi

    void retranslateUi(QWidget *Diagnostics)
    {
        Diagnostics->setWindowTitle(QCoreApplication::translate("Diagnostics", "Diagnostics", nullptr));
        progressBarLabel->setText(QCoreApplication::translate("Diagnostics", "Analysing:", nullptr));
        outputLabel->setText(QCoreApplication::translate("Diagnostics", "l", nullptr));
        exitButton->setText(QCoreApplication::translate("Diagnostics", "Exit", nullptr));
        mainButton->setText(QCoreApplication::translate("Diagnostics", "Main menu", nullptr));
        cancelButton->setText(QCoreApplication::translate("Diagnostics", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diagnostics: public Ui_Diagnostics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICS_H
