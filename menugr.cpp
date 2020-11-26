#include "menugr.h"
#include "ui_menugr.h"

menugr::menugr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menugr)
{
    ui->setupUi(this);
}

menugr::~menugr()
{
    delete ui;
}

void menugr::on_pushButton_clicked()
{
    gr = new gestiondereservation(this);
    gr->show();
}

void menugr::on_pushButton_2_clicked()
{
    gr = new gestiondereservation(this);
    gr->show();
}

void menugr::on_pushButton_3_clicked()
{
    stat = new statistiques(this);
    stat->show();
}
