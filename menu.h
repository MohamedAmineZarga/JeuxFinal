#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "menugr.h"
#include "gestiondereservation.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QtDebug>
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButtongr_clicked();

private:
    Ui::menu *ui;
    menugr *gr;
    QPropertyAnimation *animation;
};

#endif // MENU_H
