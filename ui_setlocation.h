/********************************************************************************
** Form generated from reading UI file 'setlocation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_SetLocation
{
public:
    QGridLayout *gridLayout;
    QListView *listView;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetLocation)
    {
        if (SetLocation->objectName().isEmpty())
            SetLocation->setObjectName(QStringLiteral("SetLocation"));
        SetLocation->setWindowModality(Qt::ApplicationModal);
        SetLocation->resize(400, 300);
        gridLayout = new QGridLayout(SetLocation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listView = new QListView(SetLocation);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SetLocation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SetLocation);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetLocation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetLocation, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetLocation);
    } // setupUi

    void retranslateUi(QDialog *SetLocation)
    {
        SetLocation->setWindowTitle(QApplication::translate("SetLocation", "Set Location", 0));
    } // retranslateUi

};

namespace Ui {
    class SetLocation: public Ui_SetLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLOCATION_H
