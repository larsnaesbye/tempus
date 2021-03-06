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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QDateTime>

#include "settings.h"

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    Settings tempussettings;

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    Ui::MainWindow *ui;

public slots:
    void about();
    void setlocation();
    void UpdateTimeSystemLabel();
    QString GetTimeString();
    QDateTime GMST();
    QDateTime LST();
    double JulianDay();
    double JulianDayModified();
    void PrintFormattedTime();
    void setutc();
    void setlocal();
    void setgmst();
    void setlst();
    void setjd();
    void setjdm();
    void setlatitude(double inputlat);
    void setlongitude(double inputlong);

};

#endif // MAINWINDOW_H
