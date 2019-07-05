/********************************************************************************
** Form generated from reading UI file 'BuildProfile.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDPROFILE_H
#define UI_BUILDPROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "MyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_BuildProfile
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *fileSelect;
    QPushButton *previewButton;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *widthBeginLabel;
    QLineEdit *widthBegin;
    QSpacerItem *horizontalSpacer_3;
    QLabel *heightBeginLabel;
    QLineEdit *heightBegin;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *widthEndLabel;
    QLineEdit *widthEnd;
    QSpacerItem *horizontalSpacer_4;
    QLabel *heightEndLabel;
    QLineEdit *heightEnd;
    QSpacerItem *horizontalSpacer_2;
    MyGraphicsView *framePreview;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *instructionLabel2;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *frameBack;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *continueButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *frameForward;
    QHBoxLayout *horizontalLayout_5;
    QLabel *continueWarning;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *BuildProfile)
    {
        if (BuildProfile->objectName().isEmpty())
            BuildProfile->setObjectName(QString::fromUtf8("BuildProfile"));
        BuildProfile->resize(888, 870);
        gridLayout = new QGridLayout(BuildProfile);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        label = new QLabel(BuildProfile);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputLabel = new QLabel(BuildProfile);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        horizontalLayout_2->addWidget(inputLabel);

        inputLineEdit = new QLineEdit(BuildProfile);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        horizontalLayout_2->addWidget(inputLineEdit);

        fileSelect = new QPushButton(BuildProfile);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setMaximumSize(QSize(25, 23));

        horizontalLayout_2->addWidget(fileSelect);

        previewButton = new QPushButton(BuildProfile);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widthBeginLabel = new QLabel(BuildProfile);
        widthBeginLabel->setObjectName(QString::fromUtf8("widthBeginLabel"));

        horizontalLayout_3->addWidget(widthBeginLabel);

        widthBegin = new QLineEdit(BuildProfile);
        widthBegin->setObjectName(QString::fromUtf8("widthBegin"));
        widthBegin->setMaximumSize(QSize(25, 20));
        widthBegin->setReadOnly(false);

        horizontalLayout_3->addWidget(widthBegin);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        heightBeginLabel = new QLabel(BuildProfile);
        heightBeginLabel->setObjectName(QString::fromUtf8("heightBeginLabel"));

        horizontalLayout_3->addWidget(heightBeginLabel);

        heightBegin = new QLineEdit(BuildProfile);
        heightBegin->setObjectName(QString::fromUtf8("heightBegin"));
        heightBegin->setMaximumSize(QSize(25, 20));
        heightBegin->setReadOnly(false);

        horizontalLayout_3->addWidget(heightBegin);

        horizontalSpacer_5 = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widthEndLabel = new QLabel(BuildProfile);
        widthEndLabel->setObjectName(QString::fromUtf8("widthEndLabel"));

        horizontalLayout_4->addWidget(widthEndLabel);

        widthEnd = new QLineEdit(BuildProfile);
        widthEnd->setObjectName(QString::fromUtf8("widthEnd"));
        widthEnd->setMaximumSize(QSize(25, 20));
        widthEnd->setReadOnly(false);

        horizontalLayout_4->addWidget(widthEnd);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        heightEndLabel = new QLabel(BuildProfile);
        heightEndLabel->setObjectName(QString::fromUtf8("heightEndLabel"));

        horizontalLayout_4->addWidget(heightEndLabel);

        heightEnd = new QLineEdit(BuildProfile);
        heightEnd->setObjectName(QString::fromUtf8("heightEnd"));
        heightEnd->setMaximumSize(QSize(25, 20));
        heightEnd->setReadOnly(false);

        horizontalLayout_4->addWidget(heightEnd);

        horizontalSpacer_2 = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        framePreview = new MyGraphicsView(BuildProfile);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        gridLayout->addWidget(framePreview, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        instructionLabel2 = new QLabel(BuildProfile);
        instructionLabel2->setObjectName(QString::fromUtf8("instructionLabel2"));

        horizontalLayout_7->addWidget(instructionLabel2);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        gridLayout->addLayout(horizontalLayout_7, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(11, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        frameBack = new QPushButton(BuildProfile);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        horizontalLayout->addWidget(frameBack);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        continueButton = new QPushButton(BuildProfile);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        horizontalLayout->addWidget(continueButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        frameForward = new QPushButton(BuildProfile);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        horizontalLayout->addWidget(frameForward);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        continueWarning = new QLabel(BuildProfile);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        horizontalLayout_5->addWidget(continueWarning);

        backButton = new QPushButton(BuildProfile);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_5->addWidget(backButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_5, 7, 0, 1, 1);


        retranslateUi(BuildProfile);

        QMetaObject::connectSlotsByName(BuildProfile);
    } // setupUi

    void retranslateUi(QWidget *BuildProfile)
    {
        BuildProfile->setWindowTitle(QCoreApplication::translate("BuildProfile", "BuildProfile", nullptr));
        label->setText(QCoreApplication::translate("BuildProfile", " Select a video to scan for subtitles and click 'preview' to begin cropping.", nullptr));
        inputLabel->setText(QCoreApplication::translate("BuildProfile", "Video file to scan:", nullptr));
        fileSelect->setText(QCoreApplication::translate("BuildProfile", "...", nullptr));
        previewButton->setText(QCoreApplication::translate("BuildProfile", "Preview", nullptr));
        widthBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Width start:", nullptr));
        heightBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Height start:", nullptr));
        widthEndLabel->setText(QCoreApplication::translate("BuildProfile", "Width end:  ", nullptr));
        heightEndLabel->setText(QCoreApplication::translate("BuildProfile", "Height end:  ", nullptr));
        instructionLabel2->setText(QCoreApplication::translate("BuildProfile", " Click and drag to crop the area where the subtitles appear on the video. Use << and >> to check different frames and click continue once you have identified the subtitle region.", nullptr));
        frameBack->setText(QCoreApplication::translate("BuildProfile", "<<", nullptr));
        continueButton->setText(QCoreApplication::translate("BuildProfile", "Continue", nullptr));
        frameForward->setText(QCoreApplication::translate("BuildProfile", ">>", nullptr));
        continueWarning->setText(QString());
        backButton->setText(QCoreApplication::translate("BuildProfile", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuildProfile: public Ui_BuildProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDPROFILE_H
