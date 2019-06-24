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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExistingProfiles
{
public:
    QListView *existingList;
    QLabel *existingLabel;
    QLabel *inputLabel;
    QLineEdit *inputLineEdit;
    QPushButton *fileSelect;
    QLabel *outputLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QPushButton *transcriptFileSelect;
    QLineEdit *transcriptLineEdit;
    QLabel *transcriptLabel;
    QPushButton *goButton;
    QPushButton *backButton;

    void setupUi(QWidget *ExistingProfiles)
    {
        if (ExistingProfiles->objectName().isEmpty())
            ExistingProfiles->setObjectName(QString::fromUtf8("ExistingProfiles"));
        ExistingProfiles->resize(646, 400);
        existingList = new QListView(ExistingProfiles);
        existingList->setObjectName(QString::fromUtf8("existingList"));
        existingList->setGeometry(QRect(40, 60, 271, 311));
        existingLabel = new QLabel(ExistingProfiles);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));
        existingLabel->setGeometry(QRect(40, 40, 91, 16));
        inputLabel = new QLabel(ExistingProfiles);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setGeometry(QRect(330, 60, 47, 13));
        inputLineEdit = new QLineEdit(ExistingProfiles);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));
        inputLineEdit->setGeometry(QRect(330, 80, 241, 21));
        fileSelect = new QPushButton(ExistingProfiles);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setGeometry(QRect(580, 80, 31, 23));
        outputLabel = new QLabel(ExistingProfiles);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setGeometry(QRect(330, 120, 71, 16));
        outputLineEdit = new QLineEdit(ExistingProfiles);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));
        outputLineEdit->setGeometry(QRect(330, 140, 241, 21));
        outputFileSelect = new QPushButton(ExistingProfiles);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setGeometry(QRect(580, 140, 31, 23));
        transcriptFileSelect = new QPushButton(ExistingProfiles);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));
        transcriptFileSelect->setGeometry(QRect(580, 200, 31, 23));
        transcriptLineEdit = new QLineEdit(ExistingProfiles);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));
        transcriptLineEdit->setGeometry(QRect(330, 200, 241, 21));
        transcriptLabel = new QLabel(ExistingProfiles);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));
        transcriptLabel->setGeometry(QRect(330, 180, 71, 16));
        goButton = new QPushButton(ExistingProfiles);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setGeometry(QRect(330, 260, 75, 23));
        backButton = new QPushButton(ExistingProfiles);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(560, 350, 75, 23));

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
        transcriptFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        transcriptLabel->setText(QCoreApplication::translate("ExistingProfiles", "Transcript file: ", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
