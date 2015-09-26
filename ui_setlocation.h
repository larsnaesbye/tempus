/********************************************************************************
** Form generated from reading UI file 'setlocation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETLOCATION_H
#define UI_SETLOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SetLocation
{
public:
    QListView *listView;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;

    void setupUi(QDialog *SetLocation)
    {
        if (SetLocation->objectName().isEmpty())
            SetLocation->setObjectName(QStringLiteral("SetLocation"));
        SetLocation->setWindowModality(Qt::ApplicationModal);
        SetLocation->resize(400, 253);
        listView = new QListView(SetLocation);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(10, 90, 381, 111));
        buttonBox = new QDialogButtonBox(SetLocation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(210, 210, 176, 27));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(SetLocation);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(110, 10, 91, 27));
        lineEdit_2 = new QLineEdit(SetLocation);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 50, 91, 27));
        label = new QLabel(SetLocation);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 67, 17));
        label_2 = new QLabel(SetLocation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 81, 17));
        radioButton = new QRadioButton(SetLocation);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(220, 10, 41, 22));
        radioButton_2 = new QRadioButton(SetLocation);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(290, 10, 41, 22));
        radioButton_3 = new QRadioButton(SetLocation);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(290, 50, 41, 22));
        radioButton_4 = new QRadioButton(SetLocation);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(220, 50, 41, 22));

        retranslateUi(SetLocation);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetLocation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetLocation, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetLocation);
    } // setupUi

    void retranslateUi(QDialog *SetLocation)
    {
        SetLocation->setWindowTitle(QApplication::translate("SetLocation", "Set Location", 0));
        label->setText(QApplication::translate("SetLocation", "Latitude :", 0));
        label_2->setText(QApplication::translate("SetLocation", "Longitude :", 0));
        radioButton->setText(QApplication::translate("SetLocation", "N", 0));
        radioButton_2->setText(QApplication::translate("SetLocation", "S", 0));
        radioButton_3->setText(QApplication::translate("SetLocation", "E", 0));
        radioButton_4->setText(QApplication::translate("SetLocation", "W", 0));
    } // retranslateUi

};

namespace Ui {
    class SetLocation: public Ui_SetLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLOCATION_H
