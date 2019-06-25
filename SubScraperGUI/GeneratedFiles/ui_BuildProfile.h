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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildProfile
{
public:
    QLineEdit *inputLineEdit;
    QLabel *inputLabel;
    QPushButton *fileSelect;
    QGraphicsView *framePreview;
    QPushButton *frameForward;
    QPushButton *frameBack;
    QPushButton *continueButton;
    QPushButton *backButton;
    QPushButton *previewButton;

    void setupUi(QWidget *BuildProfile)
    {
        if (BuildProfile->objectName().isEmpty())
            BuildProfile->setObjectName(QString::fromUtf8("BuildProfile"));
        BuildProfile->resize(573, 705);
        inputLineEdit = new QLineEdit(BuildProfile);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));
        inputLineEdit->setGeometry(QRect(20, 30, 241, 21));
        inputLabel = new QLabel(BuildProfile);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setGeometry(QRect(20, 10, 47, 13));
        fileSelect = new QPushButton(BuildProfile);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setGeometry(QRect(270, 30, 31, 23));
        framePreview = new QGraphicsView(BuildProfile);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));
        framePreview->setGeometry(QRect(100, 70, 371, 431));
        frameForward = new QPushButton(BuildProfile);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));
        frameForward->setGeometry(QRect(400, 530, 75, 23));
        frameBack = new QPushButton(BuildProfile);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));
        frameBack->setGeometry(QRect(100, 530, 75, 23));
        continueButton = new QPushButton(BuildProfile);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(250, 530, 75, 23));
        backButton = new QPushButton(BuildProfile);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(400, 650, 75, 23));
        previewButton = new QPushButton(BuildProfile);
        previewButton->setObjectName(QString::fromUtf8("previewButton"));
        previewButton->setGeometry(QRect(320, 30, 75, 23));

        retranslateUi(BuildProfile);

        QMetaObject::connectSlotsByName(BuildProfile);
    } // setupUi

    void retranslateUi(QWidget *BuildProfile)
    {
        BuildProfile->setWindowTitle(QCoreApplication::translate("BuildProfile", "BuildProfile", nullptr));
        inputLabel->setText(QCoreApplication::translate("BuildProfile", "Input file:", nullptr));
        fileSelect->setText(QCoreApplication::translate("BuildProfile", "...", nullptr));
        frameForward->setText(QCoreApplication::translate("BuildProfile", "5>>", nullptr));
        frameBack->setText(QCoreApplication::translate("BuildProfile", "<<5", nullptr));
        continueButton->setText(QCoreApplication::translate("BuildProfile", "Continue", nullptr));
        backButton->setText(QCoreApplication::translate("BuildProfile", "Back", nullptr));
        previewButton->setText(QCoreApplication::translate("BuildProfile", "Preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuildProfile: public Ui_BuildProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDPROFILE_H
