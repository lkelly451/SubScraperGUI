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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputSelect
{
public:
    QGridLayout *gridLayout;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QLabel *transcriptLabel;
    QLineEdit *transcriptLineEdit;
    QPushButton *transcriptFileSelect;
    QPushButton *backButton;
    QPushButton *goButton;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(564, 198);
        gridLayout = new QGridLayout(OutputSelect);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        outputLabel = new QLabel(OutputSelect);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 0, 0, 1, 1);

        outputLineEdit = new QLineEdit(OutputSelect);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 1, 0, 1, 2);

        outputFileSelect = new QPushButton(OutputSelect);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayout->addWidget(outputFileSelect, 1, 2, 1, 1);

        transcriptLabel = new QLabel(OutputSelect);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        gridLayout->addWidget(transcriptLabel, 2, 0, 1, 1);

        transcriptLineEdit = new QLineEdit(OutputSelect);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        gridLayout->addWidget(transcriptLineEdit, 3, 0, 1, 2);

        transcriptFileSelect = new QPushButton(OutputSelect);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        gridLayout->addWidget(transcriptFileSelect, 3, 2, 1, 1);

        backButton = new QPushButton(OutputSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 4, 0, 1, 1);

        goButton = new QPushButton(OutputSelect);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 4, 1, 1, 2);


        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "OutputSelect", nullptr));
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file:", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("OutputSelect", "Transcript file:", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputSelect: public Ui_OutputSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTSELECT_H
