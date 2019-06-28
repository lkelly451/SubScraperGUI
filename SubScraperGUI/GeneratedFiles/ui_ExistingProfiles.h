/********************************************************************************
** Form generated from reading UI file 'ExistingProfiles.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTINGPROFILES_H
#define UI_EXISTINGPROFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExistingProfiles
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *fileSelect;
    QPushButton *transcriptFileSelect;
    QPushButton *outputFileSelect;
    QLineEdit *transcriptLineEdit;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QLabel *existingLabel;
    QLabel *outputLabel;
    QLabel *transcriptLabel;
    QListWidget *profileList;
    QLineEdit *outputLineEdit;
    QPushButton *goButton;
    QPushButton *backButton;
    QLabel *goWarningLabel;

    void setupUi(QWidget *ExistingProfiles)
    {
        if (ExistingProfiles->objectName().isEmpty())
            ExistingProfiles->setObjectName(QString::fromUtf8("ExistingProfiles"));
        ExistingProfiles->resize(646, 400);
        layoutWidget = new QWidget(ExistingProfiles);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 621, 371));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        fileSelect = new QPushButton(layoutWidget);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        gridLayout->addWidget(fileSelect, 2, 3, 1, 1);

        transcriptFileSelect = new QPushButton(layoutWidget);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        gridLayout->addWidget(transcriptFileSelect, 6, 3, 1, 1);

        outputFileSelect = new QPushButton(layoutWidget);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayout->addWidget(outputFileSelect, 4, 3, 1, 1);

        transcriptLineEdit = new QLineEdit(layoutWidget);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        gridLayout->addWidget(transcriptLineEdit, 6, 1, 1, 2);

        inputLabel = new QLabel(layoutWidget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        gridLayout->addWidget(inputLabel, 1, 1, 1, 1);

        inputLineEdit = new QLineEdit(layoutWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 2, 1, 1, 2);

        existingLabel = new QLabel(layoutWidget);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        gridLayout->addWidget(existingLabel, 0, 0, 1, 1);

        outputLabel = new QLabel(layoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 3, 1, 1, 1);

        transcriptLabel = new QLabel(layoutWidget);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        gridLayout->addWidget(transcriptLabel, 5, 1, 1, 1);

        profileList = new QListWidget(layoutWidget);
        profileList->setObjectName(QString::fromUtf8("profileList"));

        gridLayout->addWidget(profileList, 1, 0, 8, 1);

        outputLineEdit = new QLineEdit(layoutWidget);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 4, 1, 1, 2);

        goButton = new QPushButton(layoutWidget);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 8, 1, 1, 1);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 8, 3, 1, 1);

        goWarningLabel = new QLabel(layoutWidget);
        goWarningLabel->setObjectName(QString::fromUtf8("goWarningLabel"));

        gridLayout->addWidget(goWarningLabel, 7, 1, 1, 1);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "ExistingProfiles", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Input file:", nullptr));
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file:", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("ExistingProfiles", "Transcript file: ", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
        goWarningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
