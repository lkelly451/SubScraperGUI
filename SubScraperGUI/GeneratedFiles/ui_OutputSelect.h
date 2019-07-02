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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputSelect
{
public:
    QLabel *profileNameWarning;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *outputLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *profileLabel;
    QLineEdit *profileName;
    QPushButton *saveProfileButton;
    QLabel *continueWarning;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backButton;
    QPushButton *goButton;
    QVBoxLayout *verticalLayout_3;
    QLabel *transcriptLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *transcriptLineEdit;
    QPushButton *transcriptFileSelect;
    QVBoxLayout *verticalLayout_5;
    QLabel *advancedLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lengthFilterLabel;
    QLineEdit *lengthFilterLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *leftWindowLabel;
    QLineEdit *leftWindowLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *rightWindowLabel;
    QLineEdit *rightWindowLineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *wordConfidenceLabel;
    QLineEdit *wordConfidenceLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lineConfidenceLabel;
    QLineEdit *lineConfidenceLineEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *compareThresholdLabel;
    QLineEdit *compareThresholdLineEdit;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(580, 345);
        profileNameWarning = new QLabel(OutputSelect);
        profileNameWarning->setObjectName(QString::fromUtf8("profileNameWarning"));
        profileNameWarning->setGeometry(QRect(22, 71, 16, 16));
        widget = new QWidget(OutputSelect);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 515, 289));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        outputLabel = new QLabel(widget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        verticalLayout_2->addWidget(outputLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        outputLineEdit = new QLineEdit(widget);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        horizontalLayout_2->addWidget(outputLineEdit);

        outputFileSelect = new QPushButton(widget);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        horizontalLayout_2->addWidget(outputFileSelect);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        profileLabel = new QLabel(widget);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));

        horizontalLayout->addWidget(profileLabel);

        profileName = new QLineEdit(widget);
        profileName->setObjectName(QString::fromUtf8("profileName"));

        horizontalLayout->addWidget(profileName);

        saveProfileButton = new QPushButton(widget);
        saveProfileButton->setObjectName(QString::fromUtf8("saveProfileButton"));

        horizontalLayout->addWidget(saveProfileButton);


        verticalLayout->addLayout(horizontalLayout);

        continueWarning = new QLabel(widget);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        verticalLayout->addWidget(continueWarning);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        backButton = new QPushButton(widget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_4->addWidget(backButton);

        goButton = new QPushButton(widget);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        horizontalLayout_4->addWidget(goButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        transcriptLabel = new QLabel(widget);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        verticalLayout_3->addWidget(transcriptLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        transcriptLineEdit = new QLineEdit(widget);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        horizontalLayout_3->addWidget(transcriptLineEdit);

        transcriptFileSelect = new QPushButton(widget);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        horizontalLayout_3->addWidget(transcriptFileSelect);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        advancedLabel = new QLabel(widget);
        advancedLabel->setObjectName(QString::fromUtf8("advancedLabel"));

        verticalLayout_5->addWidget(advancedLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lengthFilterLabel = new QLabel(widget);
        lengthFilterLabel->setObjectName(QString::fromUtf8("lengthFilterLabel"));

        horizontalLayout_5->addWidget(lengthFilterLabel);

        lengthFilterLineEdit = new QLineEdit(widget);
        lengthFilterLineEdit->setObjectName(QString::fromUtf8("lengthFilterLineEdit"));

        horizontalLayout_5->addWidget(lengthFilterLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        leftWindowLabel = new QLabel(widget);
        leftWindowLabel->setObjectName(QString::fromUtf8("leftWindowLabel"));

        horizontalLayout_6->addWidget(leftWindowLabel);

        leftWindowLineEdit = new QLineEdit(widget);
        leftWindowLineEdit->setObjectName(QString::fromUtf8("leftWindowLineEdit"));

        horizontalLayout_6->addWidget(leftWindowLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rightWindowLabel = new QLabel(widget);
        rightWindowLabel->setObjectName(QString::fromUtf8("rightWindowLabel"));

        horizontalLayout_7->addWidget(rightWindowLabel);

        rightWindowLineEdit = new QLineEdit(widget);
        rightWindowLineEdit->setObjectName(QString::fromUtf8("rightWindowLineEdit"));

        horizontalLayout_7->addWidget(rightWindowLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        wordConfidenceLabel = new QLabel(widget);
        wordConfidenceLabel->setObjectName(QString::fromUtf8("wordConfidenceLabel"));

        horizontalLayout_8->addWidget(wordConfidenceLabel);

        wordConfidenceLineEdit = new QLineEdit(widget);
        wordConfidenceLineEdit->setObjectName(QString::fromUtf8("wordConfidenceLineEdit"));

        horizontalLayout_8->addWidget(wordConfidenceLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineConfidenceLabel = new QLabel(widget);
        lineConfidenceLabel->setObjectName(QString::fromUtf8("lineConfidenceLabel"));

        horizontalLayout_9->addWidget(lineConfidenceLabel);

        lineConfidenceLineEdit = new QLineEdit(widget);
        lineConfidenceLineEdit->setObjectName(QString::fromUtf8("lineConfidenceLineEdit"));

        horizontalLayout_9->addWidget(lineConfidenceLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        compareThresholdLabel = new QLabel(widget);
        compareThresholdLabel->setObjectName(QString::fromUtf8("compareThresholdLabel"));

        horizontalLayout_10->addWidget(compareThresholdLabel);

        compareThresholdLineEdit = new QLineEdit(widget);
        compareThresholdLineEdit->setObjectName(QString::fromUtf8("compareThresholdLineEdit"));

        horizontalLayout_10->addWidget(compareThresholdLineEdit);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout->addLayout(verticalLayout_5, 2, 0, 1, 2);


        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "OutputSelect", nullptr));
        profileNameWarning->setText(QString());
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file:", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        profileLabel->setText(QCoreApplication::translate("OutputSelect", "Profile name:", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("OutputSelect", "Save Profile", nullptr));
        continueWarning->setText(QString());
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("OutputSelect", "Transcript file:", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
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
