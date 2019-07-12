/********************************************************************************
** Form generated from reading UI file 'Diagnostics.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGNOSTICS_H
#define UI_DIAGNOSTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Diagnostics
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *progressBarLabel;
    QProgressBar *progressBar;
    QPushButton *cancelButton;
    QLabel *stepLabel;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *outputLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *mainButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *Diagnostics)
    {
        if (Diagnostics->objectName().isEmpty())
            Diagnostics->setObjectName(QString::fromUtf8("Diagnostics"));
        Diagnostics->resize(400, 300);
        gridLayout = new QGridLayout(Diagnostics);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        progressBarLabel = new QLabel(Diagnostics);
        progressBarLabel->setObjectName(QString::fromUtf8("progressBarLabel"));

        horizontalLayout->addWidget(progressBarLabel);

        progressBar = new QProgressBar(Diagnostics);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        cancelButton = new QPushButton(Diagnostics);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        stepLabel = new QLabel(Diagnostics);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));

        verticalLayout->addWidget(stepLabel);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        outputLabel = new QLabel(Diagnostics);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_3->addWidget(outputLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        mainButton = new QPushButton(Diagnostics);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));

        horizontalLayout_2->addWidget(mainButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        exitButton = new QPushButton(Diagnostics);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_7 = new QSpacerItem(38, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(Diagnostics);

        QMetaObject::connectSlotsByName(Diagnostics);
    } // setupUi

    void retranslateUi(QWidget *Diagnostics)
    {
        Diagnostics->setWindowTitle(QCoreApplication::translate("Diagnostics", "Diagnostics", nullptr));
        progressBarLabel->setText(QCoreApplication::translate("Diagnostics", "Analysing:", nullptr));
        cancelButton->setText(QCoreApplication::translate("Diagnostics", "Cancel", nullptr));
        stepLabel->setText(QString());
        outputLabel->setText(QString());
        mainButton->setText(QCoreApplication::translate("Diagnostics", "Main menu", nullptr));
        exitButton->setText(QCoreApplication::translate("Diagnostics", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diagnostics: public Ui_Diagnostics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGNOSTICS_H
