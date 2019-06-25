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
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExistingProfiles
{
public:
    QGridLayout *gridLayout;
    QLabel *existingLabel;
    QListView *existingList;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *fileSelect;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QLabel *transcriptLabel;
    QLineEdit *transcriptLineEdit;
    QPushButton *transcriptFileSelect;
    QPushButton *goButton;
    QPushButton *backButton;

    void setupUi(QWidget *ExistingProfiles)
    {
        if (ExistingProfiles->objectName().isEmpty())
            ExistingProfiles->setObjectName(QString::fromUtf8("ExistingProfiles"));
        ExistingProfiles->resize(646, 400);
        gridLayout = new QGridLayout(ExistingProfiles);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        existingLabel = new QLabel(ExistingProfiles);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        gridLayout->addWidget(existingLabel, 0, 0, 1, 1);

        existingList = new QListView(ExistingProfiles);
        existingList->setObjectName(QString::fromUtf8("existingList"));

        gridLayout->addWidget(existingList, 1, 0, 8, 1);

        inputLabel = new QLabel(ExistingProfiles);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        gridLayout->addWidget(inputLabel, 1, 1, 1, 1);

        inputLineEdit = new QLineEdit(ExistingProfiles);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        gridLayout->addWidget(inputLineEdit, 2, 1, 1, 2);

        fileSelect = new QPushButton(ExistingProfiles);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));

        gridLayout->addWidget(fileSelect, 2, 3, 1, 1);

        outputLabel = new QLabel(ExistingProfiles);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 3, 1, 1, 1);

        outputLineEdit = new QLineEdit(ExistingProfiles);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 4, 1, 1, 2);

        outputFileSelect = new QPushButton(ExistingProfiles);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayout->addWidget(outputFileSelect, 4, 3, 1, 1);

        transcriptLabel = new QLabel(ExistingProfiles);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        gridLayout->addWidget(transcriptLabel, 5, 1, 1, 1);

        transcriptLineEdit = new QLineEdit(ExistingProfiles);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        gridLayout->addWidget(transcriptLineEdit, 6, 1, 1, 2);

        transcriptFileSelect = new QPushButton(ExistingProfiles);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        gridLayout->addWidget(transcriptFileSelect, 6, 3, 1, 1);

        goButton = new QPushButton(ExistingProfiles);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 7, 1, 1, 1);

        backButton = new QPushButton(ExistingProfiles);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 8, 2, 1, 2);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "ExistingProfiles", nullptr));
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Input file:", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file:", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("ExistingProfiles", "Transcript file: ", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
