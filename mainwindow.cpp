/*
    Copyright 2015 - Lars Næsbye Christensen

    This is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    The software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "setlocation.h"
#include "ui_setlocation.h"

#include <iostream>
#include <stdio.h>

#include <QDateTime>
#include <QFont>
#include <QSound>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Signals and slots for non-ui receivers

    connect(ui->actionUniversal_Time, SIGNAL(triggered()), this, SLOT(setutc()));
    connect(ui->actionLocal_Mean_Time_24_hr_format, SIGNAL(triggered()), this, SLOT(setlocal()));
    connect(ui->actionJulian_Day, SIGNAL(triggered()), this, SLOT(setjd()));
    connect(ui->actionJulian_Day_Modified, SIGNAL(triggered()), this, SLOT(setjdm()));

    // Action Group for our menus

    QActionGroup* timegroup = new QActionGroup( this );

    ui->actionUniversal_Time->setActionGroup(timegroup);
    ui->actionLocal_Mean_Time_24_hr_format->setActionGroup(timegroup);
    ui->actionLocal_Sidereal_Time->setActionGroup(timegroup);
    ui->actionGreenwich_Sidereal_Time->setActionGroup(timegroup);
    ui->actionGreenwich_Apparent_Sidereal_Time->setActionGroup(timegroup);
    ui->actionJulian_Day->setActionGroup(timegroup);
    ui->actionJulian_Day_Modified->setActionGroup(timegroup);

    // Call PrintFormattedTime every 1000 ms = 1 sec

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(PrintFormattedTime()));
    timer->start(1000);

    PrintFormattedTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
{
    AboutDialog* aboutdialog = new AboutDialog(this);
    aboutdialog->show();
}

void MainWindow::setlocation()
{
    SetLocation* setlocationdialog = new SetLocation(this);
    setlocationdialog->show();
}

void MainWindow::setlocal()
{
    tempussettings.timesystem = 0;
}

void MainWindow::setutc()
{
    tempussettings.timesystem = 1;
}

void MainWindow::setgmst()
{
    tempussettings.timesystem = 2;
}

void MainWindow::setlst()
{
    tempussettings.timesystem = 3;
}

void MainWindow::setjd()
{
    tempussettings.timesystem = 4;
}

void MainWindow::setjdm()
{
    tempussettings.timesystem = 5;
}

QString MainWindow::GetTimeString()
{
    switch (tempussettings.timesystem) {
    case 0:     return QDateTime::currentDateTime().toString();
    case 1:     return QDateTime::currentDateTimeUtc().toString();
    case 2:     return MainWindow::GMST().toString();
    case 3:     return MainWindow::LST().toString();
    case 4:     return QString::number(MainWindow::JulianDay(), 'f',1);
    case 5:     return QString::number(MainWindow::JulianDayModified(), 'f',1);
    default:    return QDateTime::currentDateTime().toString(); //so we at least return something
    }
}

QDateTime MainWindow::GMST() {

    QDateTime GMST = QDateTime::currentDateTime(); // replace
    return GMST;
}


QDateTime MainWindow::LST() {

    QDateTime LST = QDateTime::currentDateTime(); // replace
    return LST;

}

double MainWindow::JulianDay() {

    QDate JD = QDate::currentDate();
    return JD.day()-32075+1461*(JD.year()+4800+(JD.month()-14)/12)/4+367*(JD.month()-2-(JD.month()-14)/12*12)/12-3*((JD.year()+4900+(JD.month()-14)/12)/100)/4;
}

double MainWindow::JulianDayModified() {

    return JulianDay()-2400000.5;

}

void MainWindow::UpdateTimeSystemLabel() {

    QString labels[6]= {
        "Local Mean Time",
        "Universal Time, Coordinated",
        "Greenwich Mean Sidereal Time",
        "Local Sidereal Time",
        "Julian Day",
        "Julian Day, Modified"
    };

    ui->systemlabel->setText(labels[tempussettings.timesystem]);

}

void MainWindow::PrintFormattedTime()
{
    ui->timeLabel->setText(GetTimeString());

    UpdateTimeSystemLabel();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if(this)
    {
        QFont font = ui->timeLabel->font();
        int size = ((ui->centralWidget->geometry().width()+ui->centralWidget->geometry().height()))/25;
        font.setPointSize(size);
        ui->timeLabel->setFont(font);
    }
}
