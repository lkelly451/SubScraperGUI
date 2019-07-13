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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExistingProfiles
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *existingLabel;
    QListWidget *profileList;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *instructionLabel;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *singleHeading;
    QLabel *inputLabel;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *inputLineEdit;
    QPushButton *fileSelect;
    QLabel *outputLabel;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *outputLineEdit;
    QPushButton *outputFileSelect;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *multiHeading;
    QLabel *multiOutputLabel;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *multiOutputLineEdit;
    QPushButton *multiOutputFileSelect;
    QLabel *multiLabel;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *multiLineEdit;
    QPushButton *multiFileSelect;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteProfileButton;
    QSpacerItem *verticalSpacer_5;
    QLabel *goWarningLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *backButton;
    QPushButton *goButton;

    void setupUi(QWidget *ExistingProfiles)
    {
        if (ExistingProfiles->objectName().isEmpty())
            ExistingProfiles->setObjectName(QString::fromUtf8("ExistingProfiles"));
        ExistingProfiles->resize(698, 442);
        gridLayout_2 = new QGridLayout(ExistingProfiles);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        existingLabel = new QLabel(ExistingProfiles);
        existingLabel->setObjectName(QString::fromUtf8("existingLabel"));

        verticalLayout_4->addWidget(existingLabel);

        profileList = new QListWidget(ExistingProfiles);
        profileList->setObjectName(QString::fromUtf8("profileList"));

        verticalLayout_4->addWidget(profileList);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        instructionLabel = new QLabel(ExistingProfiles);
        instructionLabel->setObjectName(QString::fromUtf8("instructionLabel"));

        verticalLayout_3->addWidget(instructionLabel);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        singleHeading = new QLabel(ExistingProfiles);
        singleHeading->setObjectName(QString::fromUtf8("singleHeading"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        singleHeading->setFont(font);

        verticalLayout->addWidget(singleHeading);

        inputLabel = new QLabel(ExistingProfiles);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setMaximumSize(QSize(88, 20));

        verticalLayout->addWidget(inputLabel);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        inputLineEdit = new QLineEdit(ExistingProfiles);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));

        horizontalLayout_5->addWidget(inputLineEdit);

        fileSelect = new QPushButton(ExistingProfiles);
        fileSelect->setObjectName(QString::fromUtf8("fileSelect"));
        fileSelect->setMaximumSize(QSize(25, 23));

        horizontalLayout_5->addWidget(fileSelect);


        verticalLayout->addLayout(horizontalLayout_5);

        outputLabel = new QLabel(ExistingProfiles);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(143, 20));

        verticalLayout->addWidget(outputLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        outputLineEdit = new QLineEdit(ExistingProfiles);
        outputLineEdit->setObjectName(QString::fromUtf8("outputLineEdit"));

        horizontalLayout_4->addWidget(outputLineEdit);

        outputFileSelect = new QPushButton(ExistingProfiles);
        outputFileSelect->setObjectName(QString::fromUtf8("outputFileSelect"));
        outputFileSelect->setMaximumSize(QSize(25, 23));

        horizontalLayout_4->addWidget(outputFileSelect);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        multiHeading = new QLabel(ExistingProfiles);
        multiHeading->setObjectName(QString::fromUtf8("multiHeading"));
        multiHeading->setFont(font);

        verticalLayout_2->addWidget(multiHeading);

        multiOutputLabel = new QLabel(ExistingProfiles);
        multiOutputLabel->setObjectName(QString::fromUtf8("multiOutputLabel"));
        multiOutputLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(multiOutputLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        multiOutputLineEdit = new QLineEdit(ExistingProfiles);
        multiOutputLineEdit->setObjectName(QString::fromUtf8("multiOutputLineEdit"));

        horizontalLayout_2->addWidget(multiOutputLineEdit);

        multiOutputFileSelect = new QPushButton(ExistingProfiles);
        multiOutputFileSelect->setObjectName(QString::fromUtf8("multiOutputFileSelect"));
        multiOutputFileSelect->setMaximumSize(QSize(25, 23));

        horizontalLayout_2->addWidget(multiOutputFileSelect);


        verticalLayout_2->addLayout(horizontalLayout_2);

        multiLabel = new QLabel(ExistingProfiles);
        multiLabel->setObjectName(QString::fromUtf8("multiLabel"));
        multiLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(multiLabel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        multiLineEdit = new QLineEdit(ExistingProfiles);
        multiLineEdit->setObjectName(QString::fromUtf8("multiLineEdit"));

        horizontalLayout_3->addWidget(multiLineEdit);

        multiFileSelect = new QPushButton(ExistingProfiles);
        multiFileSelect->setObjectName(QString::fromUtf8("multiFileSelect"));
        multiFileSelect->setMaximumSize(QSize(25, 23));

        horizontalLayout_3->addWidget(multiFileSelect);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_6->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        deleteProfileButton = new QPushButton(ExistingProfiles);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));

        horizontalLayout_7->addWidget(deleteProfileButton);


        verticalLayout_5->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 358, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        goWarningLabel = new QLabel(ExistingProfiles);
        goWarningLabel->setObjectName(QString::fromUtf8("goWarningLabel"));

        verticalLayout_5->addWidget(goWarningLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QPushButton(ExistingProfiles);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setMinimumSize(QSize(75, 23));
        backButton->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(backButton);

        goButton = new QPushButton(ExistingProfiles);
        goButton->setObjectName(QString::fromUtf8("goButton"));
        goButton->setMinimumSize(QSize(75, 23));
        goButton->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(goButton);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 4, 2);


        retranslateUi(ExistingProfiles);

        QMetaObject::connectSlotsByName(ExistingProfiles);
    } // setupUi

    void retranslateUi(QWidget *ExistingProfiles)
    {
        ExistingProfiles->setWindowTitle(QCoreApplication::translate("ExistingProfiles", "SubScraper", nullptr));
        existingLabel->setText(QCoreApplication::translate("ExistingProfiles", "Existing profiles:", nullptr));
        instructionLabel->setText(QCoreApplication::translate("ExistingProfiles", "1. Select a profile from the list on the left;\n"
"2. Select a video file or directory of videos to scan; \n"
"3. Select a file or folder to output subtitles to.", nullptr));
        singleHeading->setText(QCoreApplication::translate("ExistingProfiles", "Scan single video:", nullptr));
        inputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Video file to scan:", nullptr));
        fileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        outputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Output file for subtitles (.txt):", nullptr));
        outputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        multiHeading->setText(QCoreApplication::translate("ExistingProfiles", "Scan multiple videos:", nullptr));
        multiOutputLabel->setText(QCoreApplication::translate("ExistingProfiles", "Directory to store subtitles: ", nullptr));
        multiOutputFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        multiLabel->setText(QCoreApplication::translate("ExistingProfiles", "Path to directory of multiple videos:", nullptr));
        multiFileSelect->setText(QCoreApplication::translate("ExistingProfiles", "...", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("ExistingProfiles", "Delete Profile", nullptr));
        goWarningLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("ExistingProfiles", "Back", nullptr));
        goButton->setText(QCoreApplication::translate("ExistingProfiles", "Go", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExistingProfiles: public Ui_ExistingProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPROFILES_H
