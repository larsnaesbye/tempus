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
    explicit SetLocation(QWidget *parent = 0);
    ~SetLocation();

private:
    Ui::SetLocation *ui;
};

#endif // SETLOCATION_H
