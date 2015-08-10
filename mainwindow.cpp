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
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

ui->systemlabel->setText("Universal Time, Coordinated");

    ChimeOnce(); // here until we get it fixed, then it goes into the loop.

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

    ChimeOnce(); // our test trigger for the damn sound
}

void MainWindow::PrintFormattedTime()
{

    ui->timeLabel->setText(QDateTime::currentDateTimeUtc().time().toString());

    //ChimeOnce(); // TODO:if seconds = 0 && chime != none, do chime
}

void MainWindow::ChimeOnce()
{
    QSound::play("resources/chime.wav");
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if(this)
    {
    QFont font = ui->timeLabel->font();
    int size = ((ui->centralWidget->geometry().width()+ui->centralWidget->geometry().height()))/20;
    font.setPointSize(size);
    ui->timeLabel->setFont(font);
    }
}
