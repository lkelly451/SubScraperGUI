/********************************************************************************
** Form generated from reading UI file 'HeightSelect.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEIGHTSELECT_H
#define UI_HEIGHTSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeightSelect
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *singleLabel;
    QLineEdit *singleLineEdit;
    QPushButton *singleGetHeight;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *doubleLabel;
    QLineEdit *doubleLineEdit;
    QPushButton *doubleGetHeight;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *frameBack;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *frameForward;
    QGraphicsView *framePreview;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *backButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *autoLabel;
    QCheckBox *autoCheckBox;
    QSpacerItem *horizontalSpacer_6;
    QLabel *continueWarning;
    QPushButton *continueButton;
    QLabel *explainLabel;

    void setupUi(QWidget *HeightSelect)
    {
        if (HeightSelect->objectName().isEmpty())
            HeightSelect->setObjectName(QString::fromUtf8("HeightSelect"));
        HeightSelect->resize(565, 730);
        gridLayout_2 = new QGridLayout(HeightSelect);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        singleLabel = new QLabel(HeightSelect);
        singleLabel->setObjectName(QString::fromUtf8("singleLabel"));

        horizontalLayout->addWidget(singleLabel);

        singleLineEdit = new QLineEdit(HeightSelect);
        singleLineEdit->setObjectName(QString::fromUtf8("singleLineEdit"));
        singleLineEdit->setMaximumSize(QSize(25, 20));

        horizontalLayout->addWidget(singleLineEdit);

        singleGetHeight = new QPushButton(HeightSelect);
        singleGetHeight->setObjectName(QString::fromUtf8("singleGetHeight"));

        horizontalLayout->addWidget(singleGetHeight);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        doubleLabel = new QLabel(HeightSelect);
        doubleLabel->setObjectName(QString::fromUtf8("doubleLabel"));

        horizontalLayout_2->addWidget(doubleLabel);

        doubleLineEdit = new QLineEdit(HeightSelect);
        doubleLineEdit->setObjectName(QString::fromUtf8("doubleLineEdit"));
        doubleLineEdit->setMaximumSize(QSize(25, 20));

        horizontalLayout_2->addWidget(doubleLineEdit);

        doubleGetHeight = new QPushButton(HeightSelect);
        doubleGetHeight->setObjectName(QString::fromUtf8("doubleGetHeight"));

        horizontalLayout_2->addWidget(doubleGetHeight);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frameBack = new QPushButton(HeightSelect);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));
        frameBack->setMinimumSize(QSize(200, 23));

        horizontalLayout_4->addWidget(frameBack);

        horizontalSpacer_2 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        frameForward = new QPushButton(HeightSelect);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));
        frameForward->setMinimumSize(QSize(200, 23));

        horizontalLayout_4->addWidget(frameForward);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 2);

        framePreview = new QGraphicsView(HeightSelect);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        gridLayout->addWidget(framePreview, 0, 0, 1, 2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        backButton = new QPushButton(HeightSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        horizontalLayout_5->addWidget(backButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        autoLabel = new QLabel(HeightSelect);
        autoLabel->setObjectName(QString::fromUtf8("autoLabel"));

        horizontalLayout_3->addWidget(autoLabel);

        autoCheckBox = new QCheckBox(HeightSelect);
        autoCheckBox->setObjectName(QString::fromUtf8("autoCheckBox"));

        horizontalLayout_3->addWidget(autoCheckBox);

        horizontalSpacer_6 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        continueWarning = new QLabel(HeightSelect);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        horizontalLayout_3->addWidget(continueWarning);

        continueButton = new QPushButton(HeightSelect);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        horizontalLayout_3->addWidget(continueButton);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 2, 2);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        explainLabel = new QLabel(HeightSelect);
        explainLabel->setObjectName(QString::fromUtf8("explainLabel"));
        explainLabel->setMinimumSize(QSize(0, 70));

        gridLayout_2->addWidget(explainLabel, 0, 0, 1, 1);


        retranslateUi(HeightSelect);

        QMetaObject::connectSlotsByName(HeightSelect);
    } // setupUi

    void retranslateUi(QWidget *HeightSelect)
    {
        HeightSelect->setWindowTitle(QCoreApplication::translate("HeightSelect", "Height Select", nullptr));
        singleLabel->setText(QCoreApplication::translate("HeightSelect", "Single box height (px)  ", nullptr));
        singleLineEdit->setText(QCoreApplication::translate("HeightSelect", "0", nullptr));
        singleGetHeight->setText(QCoreApplication::translate("HeightSelect", "Get height", nullptr));
        doubleLabel->setText(QCoreApplication::translate("HeightSelect", "Double box height (px)", nullptr));
        doubleLineEdit->setText(QCoreApplication::translate("HeightSelect", "0", nullptr));
        doubleGetHeight->setText(QCoreApplication::translate("HeightSelect", "Get height", nullptr));
        frameBack->setText(QCoreApplication::translate("HeightSelect", "<<", nullptr));
        frameForward->setText(QCoreApplication::translate("HeightSelect", ">>", nullptr));
        backButton->setText(QCoreApplication::translate("HeightSelect", "Back", nullptr));
        autoLabel->setText(QCoreApplication::translate("HeightSelect", "auto detect box heights", nullptr));
        autoCheckBox->setText(QString());
        continueWarning->setText(QString());
        continueButton->setText(QCoreApplication::translate("HeightSelect", "Continue", nullptr));
        explainLabel->setText(QCoreApplication::translate("HeightSelect", "1. Navigate through the video using '<<' and '>>' and find single and double-line subtitle boxes. \n"
"2. Click 'Get height' to get their heights.\n"
"3. Ensure the lines on the image align with the box boundaries. \n"
" \n"
"Alternatively, check 'auto detect box heights' to automatically identify box heights. ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeightSelect: public Ui_HeightSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIGHTSELECT_H
