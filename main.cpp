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

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QApplication::setApplicationName("Tempus");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationDomain("https://larsnaesbye.github.io/tempus");
    QApplication::setOrganizationName("Lars Næsbye Christensen");
    QApplication::setDesktopSettingsAware(true);
    MainWindow w;
    w.show();

    return QApplication::exec();
}
