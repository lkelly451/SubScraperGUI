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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeightSelect
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *framePreview;
    QPushButton *singleGetHeight;
    QCheckBox *autoCheckBox;
    QPushButton *backButton;
    QPushButton *doubleGetHeight;
    QPushButton *frameBack;
    QLabel *doubleLabel;
    QLabel *singleLabel;
    QLabel *autoLabel;
    QPushButton *frameForward;
    QPushButton *continueButton;
    QLineEdit *singleLineEdit;
    QLineEdit *doubleLineEdit;
    QLabel *continueWarning;

    void setupUi(QWidget *HeightSelect)
    {
        if (HeightSelect->objectName().isEmpty())
            HeightSelect->setObjectName(QString::fromUtf8("HeightSelect"));
        HeightSelect->resize(565, 706);
        gridLayout = new QGridLayout(HeightSelect);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        framePreview = new QGraphicsView(HeightSelect);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));

        gridLayout->addWidget(framePreview, 0, 0, 1, 4);

        singleGetHeight = new QPushButton(HeightSelect);
        singleGetHeight->setObjectName(QString::fromUtf8("singleGetHeight"));

        gridLayout->addWidget(singleGetHeight, 3, 3, 1, 1);

        autoCheckBox = new QCheckBox(HeightSelect);
        autoCheckBox->setObjectName(QString::fromUtf8("autoCheckBox"));

        gridLayout->addWidget(autoCheckBox, 5, 1, 1, 1);

        backButton = new QPushButton(HeightSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 5, 3, 1, 1);

        doubleGetHeight = new QPushButton(HeightSelect);
        doubleGetHeight->setObjectName(QString::fromUtf8("doubleGetHeight"));

        gridLayout->addWidget(doubleGetHeight, 4, 3, 1, 1);

        frameBack = new QPushButton(HeightSelect);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        gridLayout->addWidget(frameBack, 2, 0, 1, 1);

        doubleLabel = new QLabel(HeightSelect);
        doubleLabel->setObjectName(QString::fromUtf8("doubleLabel"));

        gridLayout->addWidget(doubleLabel, 4, 0, 1, 1);

        singleLabel = new QLabel(HeightSelect);
        singleLabel->setObjectName(QString::fromUtf8("singleLabel"));

        gridLayout->addWidget(singleLabel, 3, 0, 1, 1);

        autoLabel = new QLabel(HeightSelect);
        autoLabel->setObjectName(QString::fromUtf8("autoLabel"));

        gridLayout->addWidget(autoLabel, 5, 0, 1, 1);

        frameForward = new QPushButton(HeightSelect);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        gridLayout->addWidget(frameForward, 2, 3, 1, 1);

        continueButton = new QPushButton(HeightSelect);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        gridLayout->addWidget(continueButton, 2, 2, 1, 1);

        singleLineEdit = new QLineEdit(HeightSelect);
        singleLineEdit->setObjectName(QString::fromUtf8("singleLineEdit"));

        gridLayout->addWidget(singleLineEdit, 3, 2, 1, 1);

        doubleLineEdit = new QLineEdit(HeightSelect);
        doubleLineEdit->setObjectName(QString::fromUtf8("doubleLineEdit"));

        gridLayout->addWidget(doubleLineEdit, 4, 2, 1, 1);

        continueWarning = new QLabel(HeightSelect);
        continueWarning->setObjectName(QString::fromUtf8("continueWarning"));

        gridLayout->addWidget(continueWarning, 5, 2, 1, 1);


        retranslateUi(HeightSelect);

        QMetaObject::connectSlotsByName(HeightSelect);
    } // setupUi

    void retranslateUi(QWidget *HeightSelect)
    {
        HeightSelect->setWindowTitle(QCoreApplication::translate("HeightSelect", "HeightSelect", nullptr));
        singleGetHeight->setText(QCoreApplication::translate("HeightSelect", "Get height", nullptr));
        autoCheckBox->setText(QString());
        backButton->setText(QCoreApplication::translate("HeightSelect", "Back", nullptr));
        doubleGetHeight->setText(QCoreApplication::translate("HeightSelect", "Get height", nullptr));
        frameBack->setText(QCoreApplication::translate("HeightSelect", "<<", nullptr));
        doubleLabel->setText(QCoreApplication::translate("HeightSelect", "Double box height (px)", nullptr));
        singleLabel->setText(QCoreApplication::translate("HeightSelect", "Single box height (px)", nullptr));
        autoLabel->setText(QCoreApplication::translate("HeightSelect", "auto detect box heights", nullptr));
        frameForward->setText(QCoreApplication::translate("HeightSelect", ">>", nullptr));
        continueButton->setText(QCoreApplication::translate("HeightSelect", "Continue", nullptr));
        singleLineEdit->setText(QCoreApplication::translate("HeightSelect", "0", nullptr));
        doubleLineEdit->setText(QCoreApplication::translate("HeightSelect", "0", nullptr));
        continueWarning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HeightSelect: public Ui_HeightSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIGHTSELECT_H
