#include "gestiondereservation.h"
#include "ui_gestiondereservation.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPrintDialog>
#include <QPrinter>

gestiondereservation::gestiondereservation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestiondereservation)
{client c1;
    ui->setupUi(this);
    ui->tableView_2->setModel(c1.afficher_client());

}

gestiondereservation::~gestiondereservation()
{
    delete ui;
}

void gestiondereservation::on_pushButtonajouter_clicked()
{
    int id=ui->lineEditcin->text().toInt();
    QString nom=ui->lineEditnom->text();
    QString prenom=ui->lineEditprenom->text();
    QString date=ui->lineEditdate->text();
    QString adresse=ui->lineEditadresse->text();
    int  numero=ui->lineEditnumero->text().toInt();
    QString email=ui->lineEditemail->text();
    QString sexe=ui->lineeditsexe->text();

 client c(id,nom,prenom,date,adresse,email,numero,sexe);
 bool test=c.ajouter_client();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView_2->setModel(c.afficher_client());
 }
 else
     msgBox.setText("Echec d'ajout");
   msgBox.exec();
}


void gestiondereservation::on_pushButtonsupprimerclient_clicked()
{
    client c1;
    if(ui->lineeditcinsup->text()!="")
    {    c1.setcin(ui->lineeditcinsup->text().toInt());
    bool test=c1.supprimer_client(c1.getcin());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tableView_2->setModel(c1.afficher_client());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}
}





/*void gestiondereservation::par_defaut(){

 // ui->tabWidget->setStyleSheet("");
  ui->tabWidget->setStyleSheet
  (
    "QLabel{"
    "font: 10pt Arial;"
    "color:black;"
    "}"
    "QLineEdit {"
    "background:transparent;"
    "border:none;"
    "border-bottom:1px solid #2da5d5;"
    "font: 12pt Arial;"
    "color: #2da5d5;"
    "}"
    "QPushButton{"
    "font: 12pt Arial ;"
    "color:white;"
    "background-color :#2da5d5;"
    "border-bottom-left-radius: 10px 10px;"
    "border-bottom-right-radius: 10px 10px;"
    "}"
    "QPushButton:hover{"
    "background-color:rgba(126,214,216,0.8);}"
    "QComboBox{"
    "font: 12pt Arial;"
    "color:white;"
    "background-color :#2da5d5;"
    "border-top-right-radius: 5px 5px;"
    "border-bottom-right-radius: 5px 5px;"
    "}"

    "QComboBox:drop-down {"

    "  border:none;} "
    "QComboBox QAbstractItemView {"
    " font: 12pt Arial;"
    "color:white;"
    "background-color :#2da5d5;"
    "selection-background-color: rgb(254, 120, 126);}" );
ui->tabWidget_4->setStyleSheet(
                      "QLabel{"
                      "font: 10pt Arial;"
                      "color:black;"
                      "}"
                      "QLineEdit {"
                      "background:transparent;"
                      "border:none;"
                      "border-bottom:1px solid #2da5d5;"
                      "font: 12pt Arial;"
                      "color: #2da5d5;"
                      "}"
                      "QPushButton{"
                      "font: 12pt Arial ;"
                      "color:white;"
                      "background-color :#2da5d5;"
                      "border-bottom-left-radius: 10px 10px;"
                      "border-bottom-right-radius: 10px 10px;"
                      "}"
                      "QPushButton:hover{"
                      "background-color:rgba(126,214,216,0.8);}"
                      "QComboBox{"
                      "font: 12pt Arial;"
                      "color:white;"
                      "background-color :#2da5d5;"
                      "border-top-right-radius: 5px 5px;"
                      "border-bottom-right-radius: 5px 5px;"
                      "}"

                      "QComboBox:drop-down {"

                      "  border:none;} "
                      "QComboBox QAbstractItemView {"
                      " font: 12pt Arial;"
                      "color:white;"
                      "background-color :#2da5d5;"
                      "selection-background-color: rgb(254, 120, 126);}" );

}

*/

void gestiondereservation::on_pushButton_2_clicked()
{bool test; QMessageBox msgBox;

    int cin=ui->lineeditcinsup->text().toInt();
    QString nom=ui->lineEditnom_6->text();
    QString prenom=ui->lineEditprenom_7->text();
    QString date=ui->lineEditdate_7->text();
    int numero=ui->lineEditnumero_7->text().toInt();
    QString sexe=ui->lineeditsexe_7->text();
    QString email=ui->lineEditemail_7->text();
    QString adresse=ui->lineEditadresse_7->text();


    client c(cin,nom,prenom,date,adresse,email,numero,sexe);
     test=c.modifier_client();

     if(test)
       {  msgBox.setText("Modifier avec succes.");
         ui->tableView_2->setModel(c.afficher_client());
     }
     else
         msgBox.setText("Echec de modification");
     msgBox.exec();
}

void gestiondereservation::on_tableView_2_activated(const QModelIndex &index)
{QString val;QSqlQuery query;


    val=ui->tableView_2->model()->data(index).toString();
     query.prepare("select * from client where cin=:val or nom =:val or prenom=:val or datee=:val or adresse=:val or email=:val or numero=:val or sexe=:val ");
     query.bindValue(":val",val);
     if (query.exec())
     {
         while (query.next())
         {
             ui->lineeditcinsup->setText(query.value(0).toString());
             ui->lineEditnom_6->setText(query.value(1).toString());
             ui->lineEditprenom_7->setText(query.value(2).toString());
             ui->lineEditdate_7->setText(query.value(3).toString());
             ui->lineEditadresse_7->setText(query.value(4).toString());
             ui->lineEditemail_7->setText(query.value(5).toString());
             ui->lineEditnumero_7->setText(query.value(6).toString());
             ui->lineeditsexe_7->setText(query.value(7).toString());


         }
     }
     else
     {
         QMessageBox::critical(this ,tr("error::"),query.lastError().text());
     }
}





void gestiondereservation::on_pushButtonchercher_clicked()
{
        client c;
        c.chercher_client(ui->lineeditcinsup->text().toInt(),ui->lineEditnom_6->text(),ui->lineEditprenom_7->text());
        ui->tableView_2->setModel(c.afficher_unclient());

}





void gestiondereservation::on_comboBox_activated(const QString &arg1)
{client c;
    ui->tableView_2->setModel(c.afficher_clienttrier(arg1));
}

void gestiondereservation::on_pushButton_7_clicked()
{
    QPrinter printer;
    printer.setPrinterName("printer name");
    QPrintDialog dialog(&printer,this);
     if(QDialog::Accepted == dialog.exec()){

         if(QPrinter::Landscape != printer.orientation())
                {
                    printer.setOrientation(QPrinter::Landscape);
                }
                QPoint startPoint = QPoint(20,20);
                QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
                ui->tableView_2->render( &printer, startPoint, printRegion, QWidget::DrawChildren );

     }
}
