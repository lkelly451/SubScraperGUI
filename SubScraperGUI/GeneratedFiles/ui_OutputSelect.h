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
    QWidget *layoutWidget;
    QGridLayout *gridLayoutOutput;
    QLabel *outputLabel;
    QLabel *profileLabel;
    QLineEdit *profileName;
    QPushButton *saveProfileButton;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QLabel *continueWarning;
    QLabel *transcriptLabel;
    QLabel *profileNameWarning;
    QPushButton *transcriptFileSelect;
    QLineEdit *transcriptLineEdit;
    QPushButton *backButton;
    QPushButton *goButton;
    QLabel *advancedLabel;
    QLabel *lengthFilterLabel;
    QLineEdit *lengthFilterLineEdit;
    QLabel *leftWindowLabel;
    QLineEdit *leftWindowLineEdit;
    QLabel *rightWindowLabel;
    QLineEdit *rightWindowLineEdit;
    QLabel *wordConfidenceLabel;
    QLineEdit *wordConfidenceLineEdit;
    QLabel *lineConfidenceLabel;
    QLineEdit *lineConfidenceLineEdit;
    QLabel *compareThresholdLabel;
    QLineEdit *compareThresholdLineEdit;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(652, 552);
        layoutWidget = new QWidget(OutputSelect);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 5, 570, 284));
        gridLayoutOutput = new QGridLayout(layoutWidget);
        gridLayoutOutput->setSpacing(6);
        gridLayoutOutput->setContentsMargins(11, 11, 11, 11);
        gridLayoutOutput->setObjectName(QString::fromUtf8("gridLayoutOutput"));
        gridLayoutOutput->setContentsMargins(0, 0, 0, 0);
        outputLabel = new QLabel(layoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayoutOutput->addWidget(outputLabel, 0, 0, 1, 2);

        profileLabel = new QLabel(layoutWidget);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));

        gridLayoutOutput->addWidget(profileLabel, 0, 6, 1, 1);

        profileName = new QLineEdit(layoutWidget);
        profileName->setObjectName(QString::fromUtf8("profileName"));

        gridLayoutOutput->addWidget(profileName, 0, 7, 1, 2);

        saveProfileButton = new QPushButton(layoutWidget);
        saveProfileButton->setObjectName(QString::fromUtf8("saveProfileButton"));

        gridLayoutOutput->addWidget(saveProfileButton, 0, 9, 2, 1);

        outputLineEdit = new QLineEdit(layoutWidget);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayoutOutput->addWidget(outputLineEdit, 1, 0, 2, 3);

        outputFileSelect = new QPushButton(layoutWidget);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayoutOutput->addWidget(outputFileSelect, 1, 5, 2, 1);

        continueWarning = new QLabel(layoutWidget);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        gridLayoutOutput->addWidget(continueWarning, 2, 6, 1, 4);

        transcriptLabel = new QLabel(layoutWidget);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        gridLayoutOutput->addWidget(transcriptLabel, 3, 0, 2, 2);

        profileNameWarning = new QLabel(layoutWidget);
        profileNameWarning->setObjectName(QString::fromUtf8("profileNameWarning"));

        gridLayoutOutput->addWidget(profileNameWarning, 4, 1, 2, 1);

        transcriptFileSelect = new QPushButton(layoutWidget);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        gridLayoutOutput->addWidget(transcriptFileSelect, 5, 5, 2, 1);

        transcriptLineEdit = new QLineEdit(layoutWidget);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        gridLayoutOutput->addWidget(transcriptLineEdit, 6, 0, 1, 3);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayoutOutput->addWidget(backButton, 6, 6, 1, 2);

        goButton = new QPushButton(layoutWidget);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayoutOutput->addWidget(goButton, 6, 8, 1, 1);

        advancedLabel = new QLabel(layoutWidget);
        advancedLabel->setObjectName(QString::fromUtf8("advancedLabel"));

        gridLayoutOutput->addWidget(advancedLabel, 7, 1, 1, 1);

        lengthFilterLabel = new QLabel(layoutWidget);
        lengthFilterLabel->setObjectName(QString::fromUtf8("lengthFilterLabel"));

        gridLayoutOutput->addWidget(lengthFilterLabel, 8, 1, 1, 1);

        lengthFilterLineEdit = new QLineEdit(layoutWidget);
        lengthFilterLineEdit->setObjectName(QString::fromUtf8("lengthFilterLineEdit"));

        gridLayoutOutput->addWidget(lengthFilterLineEdit, 8, 2, 1, 4);

        leftWindowLabel = new QLabel(layoutWidget);
        leftWindowLabel->setObjectName(QString::fromUtf8("leftWindowLabel"));

        gridLayoutOutput->addWidget(leftWindowLabel, 9, 1, 1, 2);

        leftWindowLineEdit = new QLineEdit(layoutWidget);
        leftWindowLineEdit->setObjectName(QString::fromUtf8("leftWindowLineEdit"));

        gridLayoutOutput->addWidget(leftWindowLineEdit, 9, 3, 1, 4);

        rightWindowLabel = new QLabel(layoutWidget);
        rightWindowLabel->setObjectName(QString::fromUtf8("rightWindowLabel"));

        gridLayoutOutput->addWidget(rightWindowLabel, 10, 1, 1, 2);

        rightWindowLineEdit = new QLineEdit(layoutWidget);
        rightWindowLineEdit->setObjectName(QString::fromUtf8("rightWindowLineEdit"));

        gridLayoutOutput->addWidget(rightWindowLineEdit, 10, 3, 1, 4);

        wordConfidenceLabel = new QLabel(layoutWidget);
        wordConfidenceLabel->setObjectName(QString::fromUtf8("wordConfidenceLabel"));

        gridLayoutOutput->addWidget(wordConfidenceLabel, 11, 1, 1, 3);

        wordConfidenceLineEdit = new QLineEdit(layoutWidget);
        wordConfidenceLineEdit->setObjectName(QString::fromUtf8("wordConfidenceLineEdit"));

        gridLayoutOutput->addWidget(wordConfidenceLineEdit, 11, 4, 1, 3);

        lineConfidenceLabel = new QLabel(layoutWidget);
        lineConfidenceLabel->setObjectName(QString::fromUtf8("lineConfidenceLabel"));

        gridLayoutOutput->addWidget(lineConfidenceLabel, 12, 1, 1, 3);

        lineConfidenceLineEdit = new QLineEdit(layoutWidget);
        lineConfidenceLineEdit->setObjectName(QString::fromUtf8("lineConfidenceLineEdit"));

        gridLayoutOutput->addWidget(lineConfidenceLineEdit, 12, 4, 1, 3);

        compareThresholdLabel = new QLabel(layoutWidget);
        compareThresholdLabel->setObjectName(QString::fromUtf8("compareThresholdLabel"));

        gridLayoutOutput->addWidget(compareThresholdLabel, 13, 1, 1, 4);

        compareThresholdLineEdit = new QLineEdit(layoutWidget);
        compareThresholdLineEdit->setObjectName(QString::fromUtf8("compareThresholdLineEdit"));

        gridLayoutOutput->addWidget(compareThresholdLineEdit, 13, 5, 1, 2);


        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "OutputSelect", nullptr));
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file:", nullptr));
        profileLabel->setText(QCoreApplication::translate("OutputSelect", "Profile name:", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("OutputSelect", "Save Profile", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        continueWarning->setText(QString());
        transcriptLabel->setText(QCoreApplication::translate("OutputSelect", "Transcript file:", nullptr));
        profileNameWarning->setText(QString());
        transcriptFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
        advancedLabel->setText(QCoreApplication::translate("OutputSelect", "Advanced options: ", nullptr));
        lengthFilterLabel->setText(QCoreApplication::translate("OutputSelect", "Box length filter(px): ", nullptr));
        lengthFilterLineEdit->setText(QCoreApplication::translate("OutputSelect", "0", nullptr));
        leftWindowLabel->setText(QCoreApplication::translate("OutputSelect", "Left sliding window size(px): ", nullptr));
        leftWindowLineEdit->setText(QCoreApplication::translate("OutputSelect", "0", nullptr));
        rightWindowLabel->setText(QCoreApplication::translate("OutputSelect", "Right sliding window size(px): ", nullptr));
        rightWindowLineEdit->setText(QCoreApplication::translate("OutputSelect", "9", nullptr));
        wordConfidenceLabel->setText(QCoreApplication::translate("OutputSelect", "Word confidence threshold (0xx):", nullptr));
        wordConfidenceLineEdit->setText(QCoreApplication::translate("OutputSelect", "70", nullptr));
        lineConfidenceLabel->setText(QCoreApplication::translate("OutputSelect", "Line confidence threshold (0xx): ", nullptr));
        lineConfidenceLineEdit->setText(QCoreApplication::translate("OutputSelect", "70", nullptr));
        compareThresholdLabel->setText(QCoreApplication::translate("OutputSelect", "Output comparison threshold (0.xx): ", nullptr));
        compareThresholdLineEdit->setText(QCoreApplication::translate("OutputSelect", "0.75", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputSelect: public Ui_OutputSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTSELECT_H
