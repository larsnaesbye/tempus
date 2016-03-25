/********************************************************************************
** Form generated from reading UI file 'setlocation.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QLineEdit *longbox;
    QLabel *label_2;
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
        longbox = new QLineEdit(SetLocation);
        longbox->setObjectName(QStringLiteral("longbox"));
        longbox->setGeometry(QRect(110, 20, 71, 27));
        label_2 = new QLabel(SetLocation);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 30, 81, 17));
        radioButton_3 = new QRadioButton(SetLocation);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(280, 20, 41, 22));
        radioButton_4 = new QRadioButton(SetLocation);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(210, 20, 41, 22));

        retranslateUi(SetLocation);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetLocation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetLocation, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetLocation);
    } // setupUi

    void retranslateUi(QDialog *SetLocation)
    {
        SetLocation->setWindowTitle(QApplication::translate("SetLocation", "Set Location", 0));
        label_2->setText(QApplication::translate("SetLocation", "Longitude :", 0));
        radioButton_3->setText(QApplication::translate("SetLocation", "E", 0));
        radioButton_4->setText(QApplication::translate("SetLocation", "W", 0));
    } // retranslateUi

};

namespace Ui {
    class SetLocation: public Ui_SetLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLOCATION_H
