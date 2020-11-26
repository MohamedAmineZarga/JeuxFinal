#include "gestiondeclient.h"
#include "ui_gestiondeclient.h"

gestiondeclient::gestiondeclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondeclient)
{
    ui->setupUi(this);
}

gestiondeclient::~gestiondeclient()
{
    delete ui;
}
