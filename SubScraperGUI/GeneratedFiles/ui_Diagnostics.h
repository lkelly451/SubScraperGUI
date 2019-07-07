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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *progressBarLabel;
    QProgressBar *progressBar;
    QPushButton *cancelButton;
    QLabel *outputLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *mainButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitButton;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Diagnostics)
    {
        if (Diagnostics->objectName().isEmpty())
            Diagnostics->setObjectName(QString::fromUtf8("Diagnostics"));
        Diagnostics->resize(400, 300);
        gridLayout = new QGridLayout(Diagnostics);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        outputLabel = new QLabel(Diagnostics);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(outputLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

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


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(Diagnostics);

        QMetaObject::connectSlotsByName(Diagnostics);
    } // setupUi

    void retranslateUi(QWidget *Diagnostics)
    {
        Diagnostics->setWindowTitle(QCoreApplication::translate("Diagnostics", "Diagnostics", nullptr));
        progressBarLabel->setText(QCoreApplication::translate("Diagnostics", "Analysing:", nullptr));
        cancelButton->setText(QCoreApplication::translate("Diagnostics", "Cancel", nullptr));
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
