#ifndef GESTION_DES_ENTRETIENS_H
#define GESTION_DES_ENTRETIENS_H

#include <QDialog>

namespace Ui {
class gestion_des_entretiens;
}

class gestion_des_entretiens : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_entretiens(QWidget *parent = nullptr);
    ~gestion_des_entretiens();

private:
    Ui::gestion_des_entretiens *ui;
};

#endif // GESTION_DES_ENTRETIENS_H
