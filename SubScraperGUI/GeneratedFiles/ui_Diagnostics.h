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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diagnostics
{
public:
    QProgressBar *progressBar;
    QLabel *progressBarLabel;

    void setupUi(QWidget *Diagnostics)
    {
        if (Diagnostics->objectName().isEmpty())
            Diagnostics->setObjectName(QString::fromUtf8("Diagnostics"));
        Diagnostics->resize(400, 300);
        progressBar = new QProgressBar(Diagnostics);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(120, 110, 141, 23));
        progressBar->setValue(0);
        progressBarLabel = new QLabel(Diagnostics);
        progressBarLabel->setObjectName(QString::fromUtf8("progressBarLabel"));
        progressBarLabel->setGeometry(QRect(60, 110, 61, 16));

        retranslateUi(Diagnostics);

        QMetaObject::connectSlotsByName(Diagnostics);
    } // setupUi

    void retranslateUi(QWidget *Diagnostics)
    {
        Diagnostics->setWindowTitle(QCoreApplication::translate("Diagnostics", "Diagnostics", nullptr));
        progressBarLabel->setText(QCoreApplication::translate("Diagnostics", "Analysing:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diagnostics: public Ui_Diagnostics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICS_H
