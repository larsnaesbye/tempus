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

#include "aaplus/AASidereal.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

time_t  now = time(0);
struct tm tstruct;
char textlabel[80];
char widgetlabel[80];

tstruct = *localtime(&now);
strftime(textlabel, sizeof(textlabel), "%Y-%m-%d %T", &tstruct);
strftime(widgetlabel, sizeof(widgetlabel), "UTC %z", &tstruct);

    QLabel* statusLabel = new QLabel(widgetlabel);
    ui->timeLabel->setText(textlabel);
    MainWindow::statusBar()->addPermanentWidget(statusLabel);
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
