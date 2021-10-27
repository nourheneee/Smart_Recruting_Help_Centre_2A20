#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   int id=ui->le_id->text().toInt();
   int age=ui->le_age->text().toInt();
   int salaire=ui->le_salaire->text().toInt();
   int date_debut_travail=ui->le_date_debut_travail->text().toInt();
   int date_fin_travail=ui->le_date_fin_travail->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString sexe=ui->le_sexe->text();
   QString poste=ui->le_poste->text();
   Employe E(id,age,salaire,date_debut_travail,date_fin_travail,nom,prenom,sexe,poste);
}
