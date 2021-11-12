#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   int id=ui->le_id->text().toInt();
   QString poste=ui->le_poste->text();
   int salaire=ui->le_salaire->text().toInt();
   int heures_de_travail=ui->le_heures_de_travail->text().toInt();
   int absences =ui->le_absences->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString sexe=ui->le_sexe->text();
   int age=ui->le_age->text().toInt();

   Employe E(id,poste,salaire,heures_de_travail,absences,nom,prenom,sexe,age);
bool test=E.ajouter();
QMessageBox msgBox;

if(ui->le_id->text().isEmpty()||ui->le_poste->text().isEmpty()||ui->le_salaire->text().isNull()||ui->le_heures_de_travail->text().isNull()||ui->le_absences->text().isEmpty()||ui->le_nom->text().isEmpty()||ui->le_prenom->text().isNull()||ui->le_sexe->text().isNull()||ui->le_age->text().isNull())
        {
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
            QObject::tr("Please Fill All Data"), QMessageBox::Ok);
        }


if(test)
{

    msgBox.setText("Ajout avec suces.");
    ui->tab_employe->setModel(E.afficher());
}
    else


        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}



void MainWindow::on_pb_supprimer_clicked()
{
  Employe E1; E1.setid(ui->le_id_supp->text().toInt());
bool test=E1.supprimer(E1.getid());
QMessageBox msgBox;
if(test)
{ msgBox.setText("Suppression avec succes.");
    ui->tab_employe->setModel(E.afficher());
}
else
     msgBox.setText("Echec de suppression");
msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    Employe e;
    int id=ui->le_id_modifier->text().toInt();
    QString poste=ui->le_poste_modifier->text();
    int salaire=ui->le_salaire_modifier->text().toInt();
    int heures_de_travail=ui->le_heures_de_travail_modifier->text().toInt();
    int absences =ui->le_absences_modifier->text().toInt();
    QString nom=ui->le_nom_modifier->text();
    QString prenom=ui->le_prenom_modifier->text();
    QString sexe=ui->le_sexe_modifier->text();
    int age=ui->le_age_modifier->text().toInt();

    bool test=e.modifier(id,poste,salaire,heures_de_travail,absences,nom,prenom,sexe,age);



           if (test)
                 {

                      ui->tab_employe->setModel(e.afficher());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("modification effectué.\n"
                                                          "click Cancel to exit."),QMessageBox::Cancel);
                 }
                 else
                     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("modification non effectué.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
          }





