#include "statistiquegc.h"
#include "ui_statistiquegc.h"

statistiquegc::statistiquegc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiquegc)
{
    ui->setupUi(this);
}

statistiquegc::~statistiquegc()
{
    delete ui;
}
