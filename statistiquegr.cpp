#include "statistiquegr.h"
#include "ui_statistiquegr.h"

statistiquegr::statistiquegr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiquegr)
{
    ui->setupUi(this);
}

statistiquegr::~statistiquegr()
{
    delete ui;
}
