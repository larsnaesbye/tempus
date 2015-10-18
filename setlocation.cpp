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

#include "setlocation.h"
#include "ui_setlocation.h"
#include "settings.h"
#include "mainwindow.h"

SetLocation::SetLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetLocation)
{
    ui->setupUi(this);
}

SetLocation::~SetLocation()
{
    MainWindow::setlongitude(ui->longbox->text().toDouble());
    MainWindow::setlatitude(ui->latbox->text().toDouble());

    delete ui;
}
