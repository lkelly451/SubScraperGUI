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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildProfile
{
public:
    QGridLayout *gridLayout;
    QPushButton *fileSelect;
    QLineEdit *inputLineEdit;
    QPushButton *continueButton;
    QPushButton *backButton;
    QLabel *inputLabel;
    QPushButton *frameForward;
    QPushButton *frameBack;
    QGraphicsView *framePreview;
    QPushButton *previewButton;

    void setupUi(QWidget *BuildProfile)
    {
        if (BuildProfile->objectName().isEmpty())
            BuildProfile->setObjectName(QString::fromUtf8("BuildProfile"));
        BuildProfile->resize(573, 705);
        gridLayout = new QGridLayout(BuildProfile);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fileSelect = new QPushButton(BuildProfile);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        gridLayout->addWidget(fileSelect, 1, 3, 1, 1);

        inputLineEdit = new QLineEdit(BuildProfile);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 1, 0, 1, 3);

        continueButton = new QPushButton(BuildProfile);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        gridLayout->addWidget(continueButton, 3, 2, 1, 1);

        backButton = new QPushButton(BuildProfile);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 4, 5, 1, 1);

        inputLabel = new QLabel(BuildProfile);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        gridLayout->addWidget(inputLabel, 0, 0, 1, 1);

        frameForward = new QPushButton(BuildProfile);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        gridLayout->addWidget(frameForward, 3, 5, 1, 1);

        frameBack = new QPushButton(BuildProfile);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        gridLayout->addWidget(frameBack, 3, 1, 1, 1);

        framePreview = new QGraphicsView(BuildProfile);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        gridLayout->addWidget(framePreview, 2, 1, 1, 5);

        previewButton = new QPushButton(BuildProfile);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));

        gridLayout->addWidget(previewButton, 1, 4, 1, 1);


        retranslateUi(BuildProfile);

        QMetaObject::connectSlotsByName(BuildProfile);
    } // setupUi

    void retranslateUi(QWidget *BuildProfile)
    {
        BuildProfile->setWindowTitle(QCoreApplication::translate("BuildProfile", "BuildProfile", nullptr));
        fileSelect->setText(QCoreApplication::translate("BuildProfile", "...", nullptr));
        continueButton->setText(QCoreApplication::translate("BuildProfile", "Continue", nullptr));
        backButton->setText(QCoreApplication::translate("BuildProfile", "Back", nullptr));
        inputLabel->setText(QCoreApplication::translate("BuildProfile", "Input file:", nullptr));
        frameForward->setText(QCoreApplication::translate("BuildProfile", "5>>", nullptr));
        frameBack->setText(QCoreApplication::translate("BuildProfile", "<<5", nullptr));
        previewButton->setText(QCoreApplication::translate("BuildProfile", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuildProfile: public Ui_BuildProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDPROFILE_H
