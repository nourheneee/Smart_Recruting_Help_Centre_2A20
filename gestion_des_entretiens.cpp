#include "gestion_des_entretiens.h"
#include "ui_gestion_des_entretiens.h"

gestion_des_entretiens::gestion_des_entretiens(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_entretiens)
{
    ui->setupUi(this);
}

gestion_des_entretiens::~gestion_des_entretiens()
{
    delete ui;
}
