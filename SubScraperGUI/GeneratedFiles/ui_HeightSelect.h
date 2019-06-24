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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HeightSelect
{
public:
    QGraphicsView *framePreview;
    QPushButton *frameBack;
    QPushButton *frameForward;
    QPushButton *continueButton;
    QLineEdit *singleLineEdit;
    QLineEdit *doubleLineEdit;
    QLabel *singleLabel;
    QLabel *doubleLabel;
    QCheckBox *autoCheckBox;
    QLabel *autoLabel;
    QPushButton *backButton;

    void setupUi(QWidget *HeightSelect)
    {
        if (HeightSelect->objectName().isEmpty())
            HeightSelect->setObjectName(QString::fromUtf8("HeightSelect"));
        HeightSelect->resize(565, 706);
        framePreview = new QGraphicsView(HeightSelect);
        framePreview->setObjectName(QString::fromUtf8("framePreview"));
        framePreview->setGeometry(QRect(90, 140, 371, 111));
        frameBack = new QPushButton(HeightSelect);
        frameBack->setObjectName(QString::fromUtf8("frameBack"));
        frameBack->setGeometry(QRect(90, 270, 75, 23));
        frameForward = new QPushButton(HeightSelect);
        frameForward->setObjectName(QString::fromUtf8("frameForward"));
        frameForward->setGeometry(QRect(390, 270, 75, 23));
        continueButton = new QPushButton(HeightSelect);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));
        continueButton->setGeometry(QRect(250, 270, 75, 23));
        singleLineEdit = new QLineEdit(HeightSelect);
        singleLineEdit->setObjectName(QString::fromUtf8("singleLineEdit"));
        singleLineEdit->setGeometry(QRect(210, 360, 51, 20));
        doubleLineEdit = new QLineEdit(HeightSelect);
        doubleLineEdit->setObjectName(QString::fromUtf8("doubleLineEdit"));
        doubleLineEdit->setGeometry(QRect(210, 330, 51, 20));
        singleLabel = new QLabel(HeightSelect);
        singleLabel->setObjectName(QString::fromUtf8("singleLabel"));
        singleLabel->setGeometry(QRect(90, 330, 111, 16));
        doubleLabel = new QLabel(HeightSelect);
        doubleLabel->setObjectName(QString::fromUtf8("doubleLabel"));
        doubleLabel->setGeometry(QRect(90, 360, 111, 16));
        autoCheckBox = new QCheckBox(HeightSelect);
        autoCheckBox->setObjectName(QString::fromUtf8("autoCheckBox"));
        autoCheckBox->setGeometry(QRect(210, 510, 21, 17));
        autoLabel = new QLabel(HeightSelect);
        autoLabel->setObjectName(QString::fromUtf8("autoLabel"));
        autoLabel->setGeometry(QRect(90, 510, 121, 16));
        backButton = new QPushButton(HeightSelect);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(390, 510, 75, 23));

        retranslateUi(HeightSelect);

        QMetaObject::connectSlotsByName(HeightSelect);
    } // setupUi

    void retranslateUi(QWidget *HeightSelect)
    {
        HeightSelect->setWindowTitle(QCoreApplication::translate("HeightSelect", "HeightSelect", nullptr));
        frameBack->setText(QCoreApplication::translate("HeightSelect", "<<5", nullptr));
        frameForward->setText(QCoreApplication::translate("HeightSelect", "5>>", nullptr));
        continueButton->setText(QCoreApplication::translate("HeightSelect", "Continue", nullptr));
        singleLabel->setText(QCoreApplication::translate("HeightSelect", "Single box height (px)", nullptr));
        doubleLabel->setText(QCoreApplication::translate("HeightSelect", "Double box height (px)", nullptr));
        autoCheckBox->setText(QString());
        autoLabel->setText(QCoreApplication::translate("HeightSelect", "auto detect box heights", nullptr));
        backButton->setText(QCoreApplication::translate("HeightSelect", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HeightSelect: public Ui_HeightSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEIGHTSELECT_H
