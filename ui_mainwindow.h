/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSet_Location;
    QAction *actionLocal_Mean_Time_24_hr_format;
    QAction *actionUniversal_Time;
    QAction *actionLocal_Sidereal_Time;
    QAction *actionGreenwich_Sidereal_Time;
    QAction *actionAbout_Tempus;
    QAction *actionJulian_Day;
    QAction *actionGreenwich_Apparent_Sidereal_Time;
    QAction *actionLocal_Mean_Sidereal_Time;
    QAction *actionJulian_Day_Modified;
    QAction *actionCycle_forward;
    QAction *actionCycle_back;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *timeLabel;
    QLabel *systemlabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuLocation;
    QMenu *menuTime;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(350, 100);
        MainWindow->setMinimumSize(QSize(350, 100));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("resources/tempus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionSet_Location = new QAction(MainWindow);
        actionSet_Location->setObjectName(QStringLiteral("actionSet_Location"));
        actionLocal_Mean_Time_24_hr_format = new QAction(MainWindow);
        actionLocal_Mean_Time_24_hr_format->setObjectName(QStringLiteral("actionLocal_Mean_Time_24_hr_format"));
        actionLocal_Mean_Time_24_hr_format->setCheckable(true);
        actionUniversal_Time = new QAction(MainWindow);
        actionUniversal_Time->setObjectName(QStringLiteral("actionUniversal_Time"));
        actionUniversal_Time->setCheckable(true);
        actionUniversal_Time->setChecked(true);
        actionLocal_Sidereal_Time = new QAction(MainWindow);
        actionLocal_Sidereal_Time->setObjectName(QStringLiteral("actionLocal_Sidereal_Time"));
        actionLocal_Sidereal_Time->setCheckable(true);
        actionGreenwich_Sidereal_Time = new QAction(MainWindow);
        actionGreenwich_Sidereal_Time->setObjectName(QStringLiteral("actionGreenwich_Sidereal_Time"));
        actionGreenwich_Sidereal_Time->setCheckable(true);
        actionAbout_Tempus = new QAction(MainWindow);
        actionAbout_Tempus->setObjectName(QStringLiteral("actionAbout_Tempus"));
        actionJulian_Day = new QAction(MainWindow);
        actionJulian_Day->setObjectName(QStringLiteral("actionJulian_Day"));
        actionGreenwich_Apparent_Sidereal_Time = new QAction(MainWindow);
        actionGreenwich_Apparent_Sidereal_Time->setObjectName(QStringLiteral("actionGreenwich_Apparent_Sidereal_Time"));
        actionLocal_Mean_Sidereal_Time = new QAction(MainWindow);
        actionLocal_Mean_Sidereal_Time->setObjectName(QStringLiteral("actionLocal_Mean_Sidereal_Time"));
        actionJulian_Day_Modified = new QAction(MainWindow);
        actionJulian_Day_Modified->setObjectName(QStringLiteral("actionJulian_Day_Modified"));
        actionCycle_forward = new QAction(MainWindow);
        actionCycle_forward->setObjectName(QStringLiteral("actionCycle_forward"));
        actionCycle_back = new QAction(MainWindow);
        actionCycle_back->setObjectName(QStringLiteral("actionCycle_back"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setPointSize(17);
        font.setBold(false);
        font.setWeight(50);
        timeLabel->setFont(font);
        timeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeLabel, 1, 0, 1, 1);

        systemlabel = new QLabel(centralWidget);
        systemlabel->setObjectName(QStringLiteral("systemlabel"));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Mono"));
        font1.setPointSize(10);
        systemlabel->setFont(font1);
        systemlabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(systemlabel, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 350, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuLocation = new QMenu(menuBar);
        menuLocation->setObjectName(QStringLiteral("menuLocation"));
        menuTime = new QMenu(menuBar);
        menuTime->setObjectName(QStringLiteral("menuTime"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuLocation->menuAction());
        menuBar->addAction(menuTime->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuLocation->addAction(actionSet_Location);
        menuTime->addAction(actionCycle_forward);
        menuTime->addAction(actionCycle_back);
        menuTime->addSeparator();
        menuTime->addAction(actionUniversal_Time);
        menuTime->addAction(actionLocal_Mean_Time_24_hr_format);
        menuTime->addAction(actionGreenwich_Apparent_Sidereal_Time);
        menuTime->addAction(actionGreenwich_Sidereal_Time);
        menuTime->addAction(actionLocal_Sidereal_Time);
        menuTime->addAction(actionLocal_Mean_Sidereal_Time);
        menuTime->addAction(actionJulian_Day);
        menuTime->addAction(actionJulian_Day_Modified);
        menuHelp->addAction(actionAbout_Tempus);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionAbout_Tempus, SIGNAL(triggered()), MainWindow, SLOT(about()));
        QObject::connect(actionSet_Location, SIGNAL(triggered()), MainWindow, SLOT(setlocation()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tempus", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionSet_Location->setText(QApplication::translate("MainWindow", "Set Location...", 0));
        actionSet_Location->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0));
        actionLocal_Mean_Time_24_hr_format->setText(QApplication::translate("MainWindow", "Local Mean Time", 0));
        actionLocal_Mean_Time_24_hr_format->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0));
        actionUniversal_Time->setText(QApplication::translate("MainWindow", "Universal Time, Coordinated", 0));
        actionUniversal_Time->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0));
        actionLocal_Sidereal_Time->setText(QApplication::translate("MainWindow", "Local Apparent Sidereal Time", 0));
        actionLocal_Sidereal_Time->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionGreenwich_Sidereal_Time->setText(QApplication::translate("MainWindow", "Greenwich Mean Sidereal Time", 0));
        actionGreenwich_Sidereal_Time->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0));
        actionAbout_Tempus->setText(QApplication::translate("MainWindow", "About Tempus...", 0));
        actionAbout_Tempus->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionJulian_Day->setText(QApplication::translate("MainWindow", "Julian Day", 0));
        actionJulian_Day->setShortcut(QApplication::translate("MainWindow", "Ctrl+J", 0));
        actionGreenwich_Apparent_Sidereal_Time->setText(QApplication::translate("MainWindow", "Greenwich Apparent Sidereal Time", 0));
        actionGreenwich_Apparent_Sidereal_Time->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0));
        actionLocal_Mean_Sidereal_Time->setText(QApplication::translate("MainWindow", "Local Mean Sidereal Time", 0));
        actionJulian_Day_Modified->setText(QApplication::translate("MainWindow", "Julian Day, Modified", 0));
        actionCycle_forward->setText(QApplication::translate("MainWindow", "Cycle forward", 0));
        actionCycle_forward->setShortcut(QApplication::translate("MainWindow", "Right", 0));
        actionCycle_back->setText(QApplication::translate("MainWindow", "Cycle back", 0));
        actionCycle_back->setShortcut(QApplication::translate("MainWindow", "Left", 0));
        timeLabel->setText(QApplication::translate("MainWindow", "TimeLabel", 0));
        systemlabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuLocation->setTitle(QApplication::translate("MainWindow", "Location", 0));
        menuTime->setTitle(QApplication::translate("MainWindow", "Time", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
