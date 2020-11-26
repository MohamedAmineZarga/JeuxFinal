#include "statistiques.h"
#include "ui_statistiques.h"

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
}

statistiques::~statistiques()
{
    delete ui;
}

void statistiques::on_pushButton_clicked()
{
    sgr=new statistiquegr(this);
    sgr->show();
}

void statistiques::on_pushButton_2_clicked()
{
    sgr=new statistiquegr(this);
    sgr->show();
}

void statistiques::on_pushButton_3_clicked()
{
    sgr=new statistiquegr(this);
    sgr->show();
}
