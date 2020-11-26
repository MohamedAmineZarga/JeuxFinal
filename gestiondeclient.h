#ifndef GESTIONDECLIENT_H
#define GESTIONDECLIENT_H

#include <QDialog>

namespace Ui {
class gestiondeclient;
}

class gestiondeclient : public QDialog
{
    Q_OBJECT

public:
    explicit gestiondeclient(QWidget *parent = nullptr);
    ~gestiondeclient();

private:
    Ui::gestiondeclient *ui;
};

#endif // GESTIONDECLIENT_H
