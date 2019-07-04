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
    QLabel *outputLabel;
    QPushButton *goButton;
    QListWidget *profileList;
    QLineEdit *outputLineEdit;
    QPushButton *backButton;
    QLineEdit *inputLineEdit;
    QPushButton *outputFileSelect;
    QPushButton *fileSelect;
    QLabel *goWarningLabel;
    QLabel *inputLabel;
    QLabel *existingLabel;
    QPushButton *deleteProfileButton;

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
        outputLabel = new QLabel(layoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 3, 1, 1, 1);

        goButton = new QPushButton(layoutWidget);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 6, 1, 1, 1);

        profileList = new QListWidget(layoutWidget);
        profileList->setObjectName(QString::fromUtf8("profileList"));

        gridLayout->addWidget(profileList, 1, 0, 6, 1);

        outputLineEdit = new QLineEdit(layoutWidget);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 4, 1, 1, 2);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 6, 3, 1, 1);

        inputLineEdit = new QLineEdit(layoutWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 2, 1, 1, 2);

        outputFileSelect = new QPushButton(layoutWidget);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayout->addWidget(outputFileSelect, 4, 3, 1, 1);

        fileSelect = new QPushButton(layoutWidget);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        gridLayout->addWidget(fileSelect, 2, 3, 1, 1);

        goWarningLabel = new QLabel(layoutWidget);
        goWarningLabel->setObjectName(QString::fromUtf8("goWarningLabel"));

        gridLayout->addWidget(goWarningLabel, 5, 1, 1, 1);

        inputLabel = new QLabel(layoutWidget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        gridLayout->addWidget(inputLabel, 1, 1, 1, 1);

        existingLabel = new QLabel(layoutWidget);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        gridLayout->addWidget(existingLabel, 0, 0, 1, 1);

        deleteProfileButton = new QPushButton(layoutWidget);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));

        gridLayout->addWidget(deleteProfileButton, 0, 3, 1, 1);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "ExistingProfiles", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file:", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        goWarningLabel->setText(QString());
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Input file:", nullptr));
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("ExistingProfiles", "Delete Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
