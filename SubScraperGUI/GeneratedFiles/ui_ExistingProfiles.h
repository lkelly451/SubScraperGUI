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
    QPushButton *deleteProfileButton;
    QPushButton *fileSelect;
    QLabel *outputLabel;
    QLabel *existingLabel;
    QPushButton *backButton;
    QLabel *goWarningLabel;
    QPushButton *goButton;
    QListWidget *profileList;
    QLineEdit *outputLineEdit;
    QLabel *inputLabel;
    QPushButton *outputFileSelect;
    QLineEdit *inputLineEdit;
    QLabel *label;

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
        deleteProfileButton = new QPushButton(ExistingProfiles);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));

        gridLayout->addWidget(deleteProfileButton, 0, 3, 1, 1);

        fileSelect = new QPushButton(ExistingProfiles);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setMaximumSize(QSize(25, 23));

        gridLayout->addWidget(fileSelect, 4, 3, 1, 1);

        outputLabel = new QLabel(ExistingProfiles);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(143, 20));

        gridLayout->addWidget(outputLabel, 5, 2, 1, 1);

        existingLabel = new QLabel(ExistingProfiles);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        gridLayout->addWidget(existingLabel, 0, 0, 1, 1);

        backButton = new QPushButton(ExistingProfiles);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(75, 23));
        backButton->setMaximumSize(QSize(75, 23));

        gridLayout->addWidget(backButton, 9, 2, 1, 1);

        goWarningLabel = new QLabel(ExistingProfiles);
        goWarningLabel->setObjectName(QString::fromUtf8("goWarningLabel"));

        gridLayout->addWidget(goWarningLabel, 6, 1, 1, 1);

        goButton = new QPushButton(ExistingProfiles);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setMinimumSize(QSize(75, 23));

        gridLayout->addWidget(goButton, 9, 3, 1, 1);

        profileList = new QListWidget(ExistingProfiles);
        profileList->setObjectName(QString::fromUtf8("profileList"));

        gridLayout->addWidget(profileList, 1, 0, 9, 1);

        outputLineEdit = new QLineEdit(ExistingProfiles);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 6, 2, 1, 1);

        inputLabel = new QLabel(ExistingProfiles);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setMaximumSize(QSize(88, 20));

        gridLayout->addWidget(inputLabel, 3, 2, 1, 1);

        outputFileSelect = new QPushButton(ExistingProfiles);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setMaximumSize(QSize(25, 23));

        gridLayout->addWidget(outputFileSelect, 6, 3, 1, 1);

        inputLineEdit = new QLineEdit(ExistingProfiles);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 4, 2, 1, 1);

        label = new QLabel(ExistingProfiles);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "Existing Profiles", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("ExistingProfiles", "Delete Profile", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file for subtitles (.txt):", nullptr));
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
        goWarningLabel->setText(QString());
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Video file to scan:", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        label->setText(QCoreApplication::translate("ExistingProfiles", "1. Select a profile from the list on the left;\n"
"2. Select a video file to scan; \n"
"3. Select a file to output subtitles to.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
