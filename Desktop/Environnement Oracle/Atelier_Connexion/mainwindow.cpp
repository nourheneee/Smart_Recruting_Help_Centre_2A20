 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entretient.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
   QString NOM=ui->le_NOM->text();
   QString PRENOM=ui->le_PRENOM->text();
   int AGE=ui->le_AGE->text().toInt();
   QString SEXE=ui->le_SEXE->text();
   int DATE_NAISSANCE=ui->le_DATE_NAISSANCE->text().toInt();
   QString ADRESS=ui->le_ADRESS->text();
   QString EXPERIENCE=ui->le_EXPERINCE->text();
   int CIN=ui->le_CIN->text().toInt();

entretient E(CIN,NOM,PRENOM,SEXE,DATE_NAISSANCE,AGE,ADRESS,EXPERIENCE);
bool test=E.ajouter();
QMessageBox msgbox;
if(test==true)
      {QMessageBox::information(this,"Login","ss");}
      else
      QMessageBox::warning(this,"Login","failed");
ui->tab_entretient->setModel(E.afficher());



}



void MainWindow::on_pb_sup_clicked()
{
 entretient E1;
 E1.setCIN(ui->le_cin_sup->text().toInt());
 bool test=E1.supprimer(E1.getCIN());
 QMessageBox msgBox;

 if(test)
     msgBox.setText("sup avec SUCCES");
 else
     msgBox.setText("Echec de sup");
     msgBox.exec();
}
