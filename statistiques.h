#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include "statistiquegc.h"
#include "statistiquegr.h"
namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    ~statistiques();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::statistiques *ui;
    statistiquegc *sgc;
    statistiquegr *sgr;
};

#endif // STATISTIQUES_H
