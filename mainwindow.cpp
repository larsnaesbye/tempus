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
#include <string>
#include <stdio.h>
#include <time.h>

#include <QDateTime>
#include <QFont>
#include <QSound>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add more signals and slots
    connect(ui->actionUniversal_Time, SIGNAL(triggered()), this, SLOT(setutc()));
    connect(ui->actionLocal_Mean_Time_24_hr_format, SIGNAL(triggered()), this, SLOT(setlocal()));

    // Action Groups for our menus

QActionGroup* timegroup = new QActionGroup( this );

    ui->actionUniversal_Time->setActionGroup(timegroup);
    ui->actionLocal_Mean_Time_24_hr_format->setActionGroup(timegroup);
    ui->actionLocal_Sidereal_Time->setActionGroup(timegroup);
    ui->actionGreenwich_Sidereal_Time->setActionGroup(timegroup);

QActionGroup* chimegroup = new QActionGroup( this );

    ui->actionNone->setActionGroup(chimegroup);
    ui->actionSingle->setActionGroup(chimegroup);
    ui->actionMultiple->setActionGroup(chimegroup);


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

void MainWindow::setutc()
{
tempussettings.timesystem = 1;
}
void MainWindow::setlocal()
{
tempussettings.timesystem = 0;
}
QDateTime MainWindow::GetTime()
{
    switch (tempussettings.timesystem) {
    case 0:     return QDateTime::currentDateTime();
    default:    return QDateTime::currentDateTimeUtc();
    }
}

void MainWindow::UpdateTimeSystemLabel() {

    QString labels[2]= {"Local Time","Universal Time, Coordinated"};
    ui->systemlabel->setText(labels[tempussettings.timesystem]);

}

void MainWindow::PrintFormattedTime()
{
    QDateTime ourDateTime = GetTime();
    QTime ourTime = ourDateTime.time();

    if (tempussettings.chime > 1 && ourTime.hour() == 0 && ourTime.second()==0)
        {
        ChimeOnce();
        }


    ui->timeLabel->setText(ourTime.toString());

    UpdateTimeSystemLabel();
}

void MainWindow::ChimeOnce()
{
    QSound::play("resources/chime.wav");
}

void MainWindow::resizeEvent(QResizeEvent *event)
{ // Overriding resize to scale label font size accordingly
    QMainWindow::resizeEvent(event);
    if(this)
    {
    QFont font = ui->timeLabel->font();
    int size = ((ui->centralWidget->geometry().width()+ui->centralWidget->geometry().height()))/20;
    font.setPointSize(size);
    ui->timeLabel->setFont(font);
    }
}
