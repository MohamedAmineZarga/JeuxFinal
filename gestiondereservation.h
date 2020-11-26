#ifndef GESTIONDERESERVATION_H
#define GESTIONDERESERVATION_H

#include <QDialog>

namespace Ui {
class gestiondereservation;
}

class gestiondereservation : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondereservation(QWidget *parent = nullptr);
    ~gestiondereservation();
void par_defaut();

private slots:
    void on_pushButtonajouter_clicked();


    void on_pushButtonsupprimerclient_clicked();




    void on_tabWidget_4_currentChanged(int index);

    void on_pushButton_2_clicked();



    void on_tableView_2_activated(const QModelIndex &index);



    void on_pushButtonchercher_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::gestiondereservation *ui;

};

#endif // GESTIONDERESERVATION_H
