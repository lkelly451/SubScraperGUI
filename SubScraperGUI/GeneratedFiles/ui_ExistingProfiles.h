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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *backButton;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QPushButton *goButton;
    QLineEdit *inputLineEdit;
    QListWidget *profileList;
    QLabel *inputLabel;
    QPushButton *fileSelect;
    QLabel *goWarningLabel;
    QLabel *existingLabel;
    QPushButton *deleteProfileButton;

    void setupUi(QWidget *ExistingProfiles)
    {
        if (ExistingProfiles->objectName().isEmpty())
            ExistingProfiles->setObjectName(QString::fromUtf8("ExistingProfiles"));
        ExistingProfiles->resize(646, 400);
        gridLayout_2 = new QGridLayout(ExistingProfiles);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backButton = new QPushButton(ExistingProfiles);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 6, 1, 1, 1);

        outputLabel = new QLabel(ExistingProfiles);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(143, 20));

        gridLayout->addWidget(outputLabel, 3, 1, 1, 1);

        outputLineEdit = new QLineEdit(ExistingProfiles);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 4, 1, 1, 2);

        outputFileSelect = new QPushButton(ExistingProfiles);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setMaximumSize(QSize(25, 23));

        gridLayout->addWidget(outputFileSelect, 4, 3, 1, 1);

        goButton = new QPushButton(ExistingProfiles);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 6, 3, 1, 1);

        inputLineEdit = new QLineEdit(ExistingProfiles);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 2, 1, 1, 2);

        profileList = new QListWidget(ExistingProfiles);
        profileList->setObjectName(QString::fromUtf8("profileList"));

        gridLayout->addWidget(profileList, 1, 0, 6, 1);

        inputLabel = new QLabel(ExistingProfiles);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setMaximumSize(QSize(88, 20));

        gridLayout->addWidget(inputLabel, 1, 1, 1, 1);

        fileSelect = new QPushButton(ExistingProfiles);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setMaximumSize(QSize(25, 23));

        gridLayout->addWidget(fileSelect, 2, 3, 1, 1);

        goWarningLabel = new QLabel(ExistingProfiles);
        goWarningLabel->setObjectName(QString::fromUtf8("goWarningLabel"));

        gridLayout->addWidget(goWarningLabel, 5, 1, 1, 1);

        existingLabel = new QLabel(ExistingProfiles);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        gridLayout->addWidget(existingLabel, 0, 0, 1, 1);

        deleteProfileButton = new QPushButton(ExistingProfiles);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));

        gridLayout->addWidget(deleteProfileButton, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "Existing Profiles", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file for subtitles (.txt):", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Video file to scan:", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        goWarningLabel->setText(QString());
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("ExistingProfiles", "Delete Profile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
