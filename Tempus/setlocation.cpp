#include "setlocation.h"
#include "ui_setlocation.h"

SetLocation::SetLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetLocation)
{
    ui->setupUi(this);
}

SetLocation::~SetLocation()
{
    delete ui;
}
