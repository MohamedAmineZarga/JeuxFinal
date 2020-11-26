#ifndef STATISTIQUEGC_H
#define STATISTIQUEGC_H

#include <QDialog>

namespace Ui {
class statistiquegc;
}

class statistiquegc : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquegc(QWidget *parent = nullptr);
    ~statistiquegc();

private:
    Ui::statistiquegc *ui;
};

#endif // STATISTIQUEGC_H
