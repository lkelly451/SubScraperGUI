/********************************************************************************
** Form generated from reading UI file 'OutputSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTSELECT_H
#define UI_OUTPUTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputSelect
{
public:
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QLabel *outputLabel;
    QLabel *transcriptLabel;
    QLineEdit *transcriptLineEdit;
    QPushButton *transcriptFileSelect;
    QPushButton *goButton;
    QPushButton *backButton;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(564, 198);
        outputLineEdit = new QLineEdit(OutputSelect);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));
        outputLineEdit->setGeometry(QRect(30, 30, 241, 21));
        outputFileSelect = new QPushButton(OutputSelect);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setGeometry(QRect(280, 30, 31, 23));
        outputLabel = new QLabel(OutputSelect);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setGeometry(QRect(30, 10, 61, 16));
        transcriptLabel = new QLabel(OutputSelect);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));
        transcriptLabel->setGeometry(QRect(30, 70, 71, 16));
        transcriptLineEdit = new QLineEdit(OutputSelect);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));
        transcriptLineEdit->setGeometry(QRect(30, 90, 241, 21));
        transcriptFileSelect = new QPushButton(OutputSelect);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));
        transcriptFileSelect->setGeometry(QRect(280, 90, 31, 23));
        goButton = new QPushButton(OutputSelect);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setGeometry(QRect(240, 150, 75, 23));
        backButton = new QPushButton(OutputSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(30, 150, 75, 23));

        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "OutputSelect", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file:", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("OutputSelect", "Transcript file:", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputSelect: public Ui_OutputSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTSELECT_H
