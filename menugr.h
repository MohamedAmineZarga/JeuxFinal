#ifndef MENUGR_H
#define MENUGR_H

#include <QDialog>
#include "gestiondeclient.h"
#include "gestiondereservation.h"
#include "statistiques.h"
namespace Ui {
class menugr;
}

class menugr : public QDialog
{
    Q_OBJECT

public:
    explicit menugr(QWidget *parent = nullptr);
    ~menugr();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menugr *ui;
    //gestiondeclient *gc;
    gestiondereservation *gr;
    statistiques *stat;

};

#endif // MENUGR_H
