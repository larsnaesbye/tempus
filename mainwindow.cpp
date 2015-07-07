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

#include <QTimer>
#include <QProcess>

#include "aaplus/AASidereal.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// Set up a loop to update the time display
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(PrintFormattedTime()));
    timer->start(1000);

    PrintFormattedTime();

PrintFormattedTime(); // should be run in loop instead
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

void MainWindow::PrintFormattedTime()
{// This we will call repeatedly every 0.4 seconds or so
    time_t now = time(0);
    struct tm tstruct = *localtime(&now);
    char textlabel[80];
    strftime(textlabel, sizeof(textlabel), "%Y-%m-%d %T", &tstruct);

    ui->timeLabel->setText(textlabel);

}
