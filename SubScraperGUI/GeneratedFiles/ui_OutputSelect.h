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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputSelect
{
public:
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
    QVBoxLayout *verticalLayout_5;
    QLabel *advancedLabel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lengthFilterLabel;
    QLineEdit *lengthFilterLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *leftWindowLabel;
    QLineEdit *leftWindowLineEdit;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *rightWindowLabel;
    QLineEdit *rightWindowLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *wordConfidenceLabel;
    QLineEdit *wordConfidenceLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lineConfidenceLabel;
    QLineEdit *lineConfidenceLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dupeThresholdLabel;
    QLineEdit *dupeThresholdLineEdit;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *compareThresholdLabel;
    QLineEdit *compareThresholdLineEdit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *goButton;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(580, 345);
        gridLayout = new QGridLayout(OutputSelect);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        outputLabel = new QLabel(OutputSelect);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(outputLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        outputLineEdit = new QLineEdit(OutputSelect);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        horizontalLayout_2->addWidget(outputLineEdit);

        outputFileSelect = new QPushButton(OutputSelect);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setMaximumSize(QSize(25, 23));

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
        profileLabel = new QLabel(OutputSelect);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));

        horizontalLayout->addWidget(profileLabel);

        profileName = new QLineEdit(OutputSelect);
        profileName->setObjectName(QString::fromUtf8("profileName"));

        horizontalLayout->addWidget(profileName);

        saveProfileButton = new QPushButton(OutputSelect);
        saveProfileButton->setObjectName(QString::fromUtf8("saveProfileButton"));

        horizontalLayout->addWidget(saveProfileButton);


        verticalLayout->addLayout(horizontalLayout);

        continueWarning = new QLabel(OutputSelect);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        verticalLayout->addWidget(continueWarning);


        verticalLayout_4->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        advancedLabel = new QLabel(OutputSelect);
        advancedLabel->setObjectName(QString::fromUtf8("advancedLabel"));

        verticalLayout_5->addWidget(advancedLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lengthFilterLabel = new QLabel(OutputSelect);
        lengthFilterLabel->setObjectName(QString::fromUtf8("lengthFilterLabel"));

        horizontalLayout_5->addWidget(lengthFilterLabel);

        lengthFilterLineEdit = new QLineEdit(OutputSelect);
        lengthFilterLineEdit->setObjectName(QString::fromUtf8("lengthFilterLineEdit"));
        lengthFilterLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_5->addWidget(lengthFilterLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        leftWindowLabel = new QLabel(OutputSelect);
        leftWindowLabel->setObjectName(QString::fromUtf8("leftWindowLabel"));

        horizontalLayout_6->addWidget(leftWindowLabel);

        leftWindowLineEdit = new QLineEdit(OutputSelect);
        leftWindowLineEdit->setObjectName(QString::fromUtf8("leftWindowLineEdit"));
        leftWindowLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_6->addWidget(leftWindowLineEdit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        rightWindowLabel = new QLabel(OutputSelect);
        rightWindowLabel->setObjectName(QString::fromUtf8("rightWindowLabel"));

        horizontalLayout_7->addWidget(rightWindowLabel);

        rightWindowLineEdit = new QLineEdit(OutputSelect);
        rightWindowLineEdit->setObjectName(QString::fromUtf8("rightWindowLineEdit"));
        rightWindowLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_7->addWidget(rightWindowLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        wordConfidenceLabel = new QLabel(OutputSelect);
        wordConfidenceLabel->setObjectName(QString::fromUtf8("wordConfidenceLabel"));

        horizontalLayout_8->addWidget(wordConfidenceLabel);

        wordConfidenceLineEdit = new QLineEdit(OutputSelect);
        wordConfidenceLineEdit->setObjectName(QString::fromUtf8("wordConfidenceLineEdit"));
        wordConfidenceLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_8->addWidget(wordConfidenceLineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lineConfidenceLabel = new QLabel(OutputSelect);
        lineConfidenceLabel->setObjectName(QString::fromUtf8("lineConfidenceLabel"));

        horizontalLayout_9->addWidget(lineConfidenceLabel);

        lineConfidenceLineEdit = new QLineEdit(OutputSelect);
        lineConfidenceLineEdit->setObjectName(QString::fromUtf8("lineConfidenceLineEdit"));
        lineConfidenceLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_9->addWidget(lineConfidenceLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_5->addLayout(horizontalLayout_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        dupeThresholdLabel = new QLabel(OutputSelect);
        dupeThresholdLabel->setObjectName(QString::fromUtf8("dupeThresholdLabel"));

        horizontalLayout_3->addWidget(dupeThresholdLabel);

        dupeThresholdLineEdit = new QLineEdit(OutputSelect);
        dupeThresholdLineEdit->setObjectName(QString::fromUtf8("dupeThresholdLineEdit"));
        dupeThresholdLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_3->addWidget(dupeThresholdLineEdit);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        compareThresholdLabel = new QLabel(OutputSelect);
        compareThresholdLabel->setObjectName(QString::fromUtf8("compareThresholdLabel"));

        horizontalLayout_10->addWidget(compareThresholdLabel);

        compareThresholdLineEdit = new QLineEdit(OutputSelect);
        compareThresholdLineEdit->setObjectName(QString::fromUtf8("compareThresholdLineEdit"));
        compareThresholdLineEdit->setMaximumSize(QSize(30, 20));

        horizontalLayout_10->addWidget(compareThresholdLineEdit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_5->addLayout(horizontalLayout_10);


        gridLayout->addLayout(verticalLayout_5, 1, 0, 1, 2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        backButton = new QPushButton(OutputSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(backButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        horizontalLayout_12->addLayout(horizontalLayout_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        goButton = new QPushButton(OutputSelect);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_11->addWidget(goButton);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        gridLayout->addLayout(horizontalLayout_12, 2, 0, 1, 2);


        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "Output Select", nullptr));
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file for subtitles (.txt):", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        profileLabel->setText(QCoreApplication::translate("OutputSelect", "Profile name:", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("OutputSelect", "Save Profile", nullptr));
        continueWarning->setText(QString());
        advancedLabel->setText(QCoreApplication::translate("OutputSelect", "Advanced options: ", nullptr));
        lengthFilterLabel->setText(QCoreApplication::translate("OutputSelect", "Box length filter(px):                          ", nullptr));
        lengthFilterLineEdit->setText(QCoreApplication::translate("OutputSelect", "0", nullptr));
        leftWindowLabel->setText(QCoreApplication::translate("OutputSelect", "Left sliding window size(px):              ", nullptr));
        leftWindowLineEdit->setText(QCoreApplication::translate("OutputSelect", "0", nullptr));
        rightWindowLabel->setText(QCoreApplication::translate("OutputSelect", "Right sliding window size(px):            ", nullptr));
        rightWindowLineEdit->setText(QCoreApplication::translate("OutputSelect", "9", nullptr));
        wordConfidenceLabel->setText(QCoreApplication::translate("OutputSelect", "Word confidence threshold (0xx):     ", nullptr));
        wordConfidenceLineEdit->setText(QCoreApplication::translate("OutputSelect", "70", nullptr));
        lineConfidenceLabel->setText(QCoreApplication::translate("OutputSelect", "Line confidence threshold (0xx):       ", nullptr));
        lineConfidenceLineEdit->setText(QCoreApplication::translate("OutputSelect", "70", nullptr));
        dupeThresholdLabel->setText(QCoreApplication::translate("OutputSelect", "Mark duplicates (min length):             ", nullptr));
        dupeThresholdLineEdit->setText(QCoreApplication::translate("OutputSelect", "3", nullptr));
        compareThresholdLabel->setText(QCoreApplication::translate("OutputSelect", "Output comparison threshold (0.xx):", nullptr));
        compareThresholdLineEdit->setText(QCoreApplication::translate("OutputSelect", "0.75", nullptr));
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputSelect: public Ui_OutputSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTSELECT_H
