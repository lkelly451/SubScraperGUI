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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "MyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_BuildProfile
{
public:
    QGridLayout *gridLayout;
    QLineEdit *widthEnd;
    QLabel *widthBeginLabel;
    QPushButton *continueButton;
    QPushButton *frameBack;
    MyGraphicsView *framePreview;
    QLineEdit *widthBegin;
    QPushButton *fileSelect;
    QPushButton *frameForward;
    QLabel *heightBeginLabel;
    QPushButton *backButton;
    QPushButton *previewButton;
    QLineEdit *inputLineEdit;
    QLineEdit *heightBegin;
    QLabel *inputLabel;
    QLabel *heightEndLabel;
    QLabel *widthEndLabel;
    QLineEdit *heightEnd;

    void setupUi(QWidget *BuildProfile)
    {
        if (BuildProfile->objectName().isEmpty())
            BuildProfile->setObjectName(QString::fromUtf8("BuildProfile"));
        BuildProfile->resize(573, 705);
        gridLayout = new QGridLayout(BuildProfile);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widthEnd = new QLineEdit(BuildProfile);
        widthEnd->setObjectName(QString::fromUtf8("widthEnd"));

        gridLayout->addWidget(widthEnd, 3, 1, 1, 1);

        widthBeginLabel = new QLabel(BuildProfile);
        widthBeginLabel->setObjectName(QString::fromUtf8("widthBeginLabel"));

        gridLayout->addWidget(widthBeginLabel, 2, 0, 1, 1);

        continueButton = new QPushButton(BuildProfile);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        gridLayout->addWidget(continueButton, 6, 2, 1, 1);

        frameBack = new QPushButton(BuildProfile);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        gridLayout->addWidget(frameBack, 6, 1, 1, 1);

        framePreview = new MyGraphicsView(BuildProfile);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        gridLayout->addWidget(framePreview, 5, 1, 1, 5);

        widthBegin = new QLineEdit(BuildProfile);
        widthBegin->setObjectName(QString::fromUtf8("widthBegin"));

        gridLayout->addWidget(widthBegin, 2, 1, 1, 1);

        fileSelect = new QPushButton(BuildProfile);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        gridLayout->addWidget(fileSelect, 1, 3, 1, 1);

        frameForward = new QPushButton(BuildProfile);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        gridLayout->addWidget(frameForward, 6, 5, 1, 1);

        heightBeginLabel = new QLabel(BuildProfile);
        heightBeginLabel->setObjectName(QString::fromUtf8("heightBeginLabel"));

        gridLayout->addWidget(heightBeginLabel, 2, 2, 1, 1);

        backButton = new QPushButton(BuildProfile);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 7, 5, 1, 1);

        previewButton = new QPushButton(BuildProfile);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        gridLayout->addWidget(previewButton, 1, 4, 1, 1);

        inputLineEdit = new QLineEdit(BuildProfile);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 1, 0, 1, 3);

        heightBegin = new QLineEdit(BuildProfile);
        heightBegin->setObjectName(QString::fromUtf8("heightBegin"));

        gridLayout->addWidget(heightBegin, 2, 3, 1, 1);

        inputLabel = new QLabel(BuildProfile);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        gridLayout->addWidget(inputLabel, 0, 0, 1, 1);

        heightEndLabel = new QLabel(BuildProfile);
        heightEndLabel->setObjectName(QString::fromUtf8("heightEndLabel"));

        gridLayout->addWidget(heightEndLabel, 3, 2, 1, 1);

        widthEndLabel = new QLabel(BuildProfile);
        widthEndLabel->setObjectName(QString::fromUtf8("widthEndLabel"));

        gridLayout->addWidget(widthEndLabel, 3, 0, 1, 1);

        heightEnd = new QLineEdit(BuildProfile);
        heightEnd->setObjectName(QString::fromUtf8("heightEnd"));

        gridLayout->addWidget(heightEnd, 3, 3, 1, 1);


        retranslateUi(BuildProfile);

        QMetaObject::connectSlotsByName(BuildProfile);
    } // setupUi

    void retranslateUi(QWidget *BuildProfile)
    {
        BuildProfile->setWindowTitle(QCoreApplication::translate("BuildProfile", "BuildProfile", nullptr));
        widthBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Width start:", nullptr));
        continueButton->setText(QCoreApplication::translate("BuildProfile", "Continue", nullptr));
        frameBack->setText(QCoreApplication::translate("BuildProfile", "<<5", nullptr));
        fileSelect->setText(QCoreApplication::translate("BuildProfile", "...", nullptr));
        frameForward->setText(QCoreApplication::translate("BuildProfile", "5>>", nullptr));
        heightBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Height start:", nullptr));
        backButton->setText(QCoreApplication::translate("BuildProfile", "Back", nullptr));
        previewButton->setText(QCoreApplication::translate("BuildProfile", "Preview", nullptr));
        inputLabel->setText(QCoreApplication::translate("BuildProfile", "Input file:", nullptr));
        heightEndLabel->setText(QCoreApplication::translate("BuildProfile", "Height end:", nullptr));
        widthEndLabel->setText(QCoreApplication::translate("BuildProfile", "Width end:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuildProfile: public Ui_BuildProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDPROFILE_H
