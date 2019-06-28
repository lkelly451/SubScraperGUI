/********************************************************************************
** Form generated from reading UI file 'OutputSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTSELECT_H
#define UI_OUTPUTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OutputSelect
{
public:
    QGridLayout *gridLayout;
    QLabel *outputLabel;
    QLineEdit *profileName;
    QPushButton *goButton;
    QPushButton *transcriptFileSelect;
    QPushButton *saveProfileButton;
    QPushButton *backButton;
    QLabel *profileNameWarning;
    QLineEdit *transcriptLineEdit;
    QLabel *profileLabel;
    QLabel *continueWarning;
    QLabel *transcriptLabel;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *OutputSelect)
    {
        if (OutputSelect->objectName().isEmpty())
            OutputSelect->setObjectName(QString::fromUtf8("OutputSelect"));
        OutputSelect->resize(564, 198);
        gridLayout = new QGridLayout(OutputSelect);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        outputLabel = new QLabel(OutputSelect);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        gridLayout->addWidget(outputLabel, 2, 0, 1, 1);

        profileName = new QLineEdit(OutputSelect);
        profileName->setObjectName(QString::fromUtf8("profileName"));

        gridLayout->addWidget(profileName, 1, 3, 1, 1);

        goButton = new QPushButton(OutputSelect);
        goButton->setObjectName(QString::fromUtf8("goButton"));

        gridLayout->addWidget(goButton, 7, 2, 1, 2);

        transcriptFileSelect = new QPushButton(OutputSelect);
        transcriptFileSelect->setObjectName(QString::fromUtf8("transcriptFileSelect"));

        gridLayout->addWidget(transcriptFileSelect, 5, 3, 1, 1);

        saveProfileButton = new QPushButton(OutputSelect);
        saveProfileButton->setObjectName(QString::fromUtf8("saveProfileButton"));

        gridLayout->addWidget(saveProfileButton, 1, 4, 1, 1);

        backButton = new QPushButton(OutputSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 7, 0, 1, 1);

        profileNameWarning = new QLabel(OutputSelect);
        profileNameWarning->setObjectName(QString::fromUtf8("profileNameWarning"));

        gridLayout->addWidget(profileNameWarning, 1, 0, 1, 1);

        transcriptLineEdit = new QLineEdit(OutputSelect);
        transcriptLineEdit->setObjectName(QString::fromUtf8("transcriptLineEdit"));

        gridLayout->addWidget(transcriptLineEdit, 5, 0, 1, 3);

        profileLabel = new QLabel(OutputSelect);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));

        gridLayout->addWidget(profileLabel, 1, 2, 1, 1);

        continueWarning = new QLabel(OutputSelect);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        gridLayout->addWidget(continueWarning, 6, 0, 1, 1);

        transcriptLabel = new QLabel(OutputSelect);
        transcriptLabel->setObjectName(QString::fromUtf8("transcriptLabel"));

        gridLayout->addWidget(transcriptLabel, 4, 0, 1, 1);

        outputLineEdit = new QLineEdit(OutputSelect);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        gridLayout->addWidget(outputLineEdit, 3, 0, 1, 3);

        outputFileSelect = new QPushButton(OutputSelect);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));

        gridLayout->addWidget(outputFileSelect, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(OutputSelect);

        QMetaObject::connectSlotsByName(OutputSelect);
    } // setupUi

    void retranslateUi(QWidget *OutputSelect)
    {
        OutputSelect->setWindowTitle(QCoreApplication::translate("OutputSelect", "OutputSelect", nullptr));
        outputLabel->setText(QCoreApplication::translate("OutputSelect", "Output file:", nullptr));
        goButton->setText(QCoreApplication::translate("OutputSelect", "Go", nullptr));
        transcriptFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
        saveProfileButton->setText(QCoreApplication::translate("OutputSelect", "Save Profile", nullptr));
        backButton->setText(QCoreApplication::translate("OutputSelect", "Back", nullptr));
        profileNameWarning->setText(QString());
        profileLabel->setText(QCoreApplication::translate("OutputSelect", "Profile name:", nullptr));
        continueWarning->setText(QString());
        transcriptLabel->setText(QCoreApplication::translate("OutputSelect", "Transcript file:", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("OutputSelect", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OutputSelect: public Ui_OutputSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTSELECT_H
