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
    QPushButton *frameBack;
    QPushButton *continueButton;
    QPushButton *frameForward;
    QLabel *singleLabel;
    QLineEdit *doubleLineEdit;
    QLabel *doubleLabel;
    QLineEdit *singleLineEdit;
    QLabel *autoLabel;
    QCheckBox *autoCheckBox;
    QPushButton *backButton;

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

        frameBack = new QPushButton(HeightSelect);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));

        gridLayout->addWidget(frameBack, 1, 0, 1, 1);

        continueButton = new QPushButton(HeightSelect);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        gridLayout->addWidget(continueButton, 1, 2, 1, 1);

        frameForward = new QPushButton(HeightSelect);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));

        gridLayout->addWidget(frameForward, 1, 3, 1, 1);

        singleLabel = new QLabel(HeightSelect);
        singleLabel->setObjectName(QString::fromUtf8("singleLabel"));

        gridLayout->addWidget(singleLabel, 2, 0, 1, 1);

        doubleLineEdit = new QLineEdit(HeightSelect);
        doubleLineEdit->setObjectName(QString::fromUtf8("doubleLineEdit"));

        gridLayout->addWidget(doubleLineEdit, 2, 1, 1, 2);

        doubleLabel = new QLabel(HeightSelect);
        doubleLabel->setObjectName(QString::fromUtf8("doubleLabel"));

        gridLayout->addWidget(doubleLabel, 3, 0, 1, 1);

        singleLineEdit = new QLineEdit(HeightSelect);
        singleLineEdit->setObjectName(QString::fromUtf8("singleLineEdit"));

        gridLayout->addWidget(singleLineEdit, 3, 1, 1, 2);

        autoLabel = new QLabel(HeightSelect);
        autoLabel->setObjectName(QString::fromUtf8("autoLabel"));

        gridLayout->addWidget(autoLabel, 4, 0, 1, 1);

        autoCheckBox = new QCheckBox(HeightSelect);
        autoCheckBox->setObjectName(QString::fromUtf8("autoCheckBox"));

        gridLayout->addWidget(autoCheckBox, 4, 1, 1, 1);

        backButton = new QPushButton(HeightSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 4, 3, 1, 1);


        retranslateUi(HeightSelect);

        QMetaObject::connectSlotsByName(HeightSelect);
    } // setupUi

    void retranslateUi(QWidget *HeightSelect)
    {
        HeightSelect->setWindowTitle(QCoreApplication::translate("HeightSelect", "HeightSelect", nullptr));
        frameBack->setText(QCoreApplication::translate("HeightSelect", "<<5", nullptr));
        continueButton->setText(QCoreApplication::translate("HeightSelect", "Continue", nullptr));
        frameForward->setText(QCoreApplication::translate("HeightSelect", "5>>", nullptr));
        singleLabel->setText(QCoreApplication::translate("HeightSelect", "Single box height (px)", nullptr));
        doubleLabel->setText(QCoreApplication::translate("HeightSelect", "Double box height (px)", nullptr));
        autoLabel->setText(QCoreApplication::translate("HeightSelect", "auto detect box heights", nullptr));
        autoCheckBox->setText(QString());
        backButton->setText(QCoreApplication::translate("HeightSelect", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeightSelect: public Ui_HeightSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIGHTSELECT_H
