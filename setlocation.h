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

#ifndef SETLOCATION_H
#define SETLOCATION_H

#include <QDialog>

namespace Ui {
class SetLocation;
}

class SetLocation : public QDialog
{
    Q_OBJECT

public:
    explicit SetLocation(QWidget *parent = nullptr);
     ~SetLocation() override;

private:
    Ui::SetLocation *ui;
};

#endif // SETLOCATION_H
