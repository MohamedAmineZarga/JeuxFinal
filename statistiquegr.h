#ifndef STATISTIQUEGR_H
#define STATISTIQUEGR_H

#include <QDialog>

namespace Ui {
class statistiquegr;
}

class statistiquegr : public QDialog
{
    Q_OBJECT

public:
    explicit statistiquegr(QWidget *parent = nullptr);
    ~statistiquegr();

private:
    Ui::statistiquegr *ui;
};

#endif // STATISTIQUEGR_H
