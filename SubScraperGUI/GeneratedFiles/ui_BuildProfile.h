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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyGraphicsView.h"

QT_BEGIN_NAMESPACE

class Ui_BuildProfile
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *inputLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputLineEdit;
    QPushButton *fileSelect;
    QPushButton *previewButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *widthBeginLabel;
    QLineEdit *widthBegin;
    QLabel *heightBeginLabel;
    QLineEdit *heightBegin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *widthEndLabel;
    QLineEdit *widthEnd;
    QLabel *heightEndLabel;
    QLineEdit *heightEnd;
    QVBoxLayout *verticalLayout;
    MyGraphicsView *framePreview;
    QHBoxLayout *horizontalLayout;
    QPushButton *frameBack;
    QPushButton *continueButton;
    QPushButton *frameForward;
    QHBoxLayout *horizontalLayout_5;
    QLabel *continueWarning;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;

    void setupUi(QWidget *BuildProfile)
    {
        if (BuildProfile->objectName().isEmpty())
            BuildProfile->setObjectName(QString::fromUtf8("BuildProfile"));
        BuildProfile->resize(573, 705);
        verticalLayout_6 = new QVBoxLayout(BuildProfile);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        inputLabel = new QLabel(BuildProfile);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        verticalLayout_2->addWidget(inputLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputLineEdit = new QLineEdit(BuildProfile);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        horizontalLayout_2->addWidget(inputLineEdit);

        fileSelect = new QPushButton(BuildProfile);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        horizontalLayout_2->addWidget(fileSelect);

        previewButton = new QPushButton(BuildProfile);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        horizontalLayout_2->addWidget(previewButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widthBeginLabel = new QLabel(BuildProfile);
        widthBeginLabel->setObjectName(QString::fromUtf8("widthBeginLabel"));

        horizontalLayout_3->addWidget(widthBeginLabel);

        widthBegin = new QLineEdit(BuildProfile);
        widthBegin->setObjectName(QString::fromUtf8("widthBegin"));
        widthBegin->setReadOnly(false);

        horizontalLayout_3->addWidget(widthBegin);

        heightBeginLabel = new QLabel(BuildProfile);
        heightBeginLabel->setObjectName(QString::fromUtf8("heightBeginLabel"));

        horizontalLayout_3->addWidget(heightBeginLabel);

        heightBegin = new QLineEdit(BuildProfile);
        heightBegin->setObjectName(QString::fromUtf8("heightBegin"));
        heightBegin->setReadOnly(false);

        horizontalLayout_3->addWidget(heightBegin);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widthEndLabel = new QLabel(BuildProfile);
        widthEndLabel->setObjectName(QString::fromUtf8("widthEndLabel"));

        horizontalLayout_4->addWidget(widthEndLabel);

        widthEnd = new QLineEdit(BuildProfile);
        widthEnd->setObjectName(QString::fromUtf8("widthEnd"));
        widthEnd->setReadOnly(false);

        horizontalLayout_4->addWidget(widthEnd);

        heightEndLabel = new QLabel(BuildProfile);
        heightEndLabel->setObjectName(QString::fromUtf8("heightEndLabel"));

        horizontalLayout_4->addWidget(heightEndLabel);

        heightEnd = new QLineEdit(BuildProfile);
        heightEnd->setObjectName(QString::fromUtf8("heightEnd"));
        heightEnd->setReadOnly(false);

        horizontalLayout_4->addWidget(heightEnd);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        framePreview = new MyGraphicsView(BuildProfile);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        verticalLayout->addWidget(framePreview);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frameBack = new QPushButton(BuildProfile);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        horizontalLayout->addWidget(frameBack);

        continueButton = new QPushButton(BuildProfile);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        horizontalLayout->addWidget(continueButton);

        frameForward = new QPushButton(BuildProfile);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        horizontalLayout->addWidget(frameForward);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        continueWarning = new QLabel(BuildProfile);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        horizontalLayout_5->addWidget(continueWarning);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        backButton = new QPushButton(BuildProfile);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_5->addWidget(backButton);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(BuildProfile);

        QMetaObject::connectSlotsByName(BuildProfile);
    } // setupUi

    void retranslateUi(QWidget *BuildProfile)
    {
        BuildProfile->setWindowTitle(QCoreApplication::translate("BuildProfile", "BuildProfile", nullptr));
        inputLabel->setText(QCoreApplication::translate("BuildProfile", "Input file:", nullptr));
        fileSelect->setText(QCoreApplication::translate("BuildProfile", "...", nullptr));
        previewButton->setText(QCoreApplication::translate("BuildProfile", "Preview", nullptr));
        widthBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Width start:", nullptr));
        heightBeginLabel->setText(QCoreApplication::translate("BuildProfile", "Height start:", nullptr));
        widthEndLabel->setText(QCoreApplication::translate("BuildProfile", "Width end:", nullptr));
        heightEndLabel->setText(QCoreApplication::translate("BuildProfile", "Height end:", nullptr));
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
