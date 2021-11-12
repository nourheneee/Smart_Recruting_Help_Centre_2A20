#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "societe.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
   ui->tab_societe->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
       int Datee=ui->le_Date->text().toInt();
    QString Domaine=ui->le_Domaine->text();
     QString Adresse=ui->le_Adresse->text();
      QString Postes=ui->le_Postes->text();
       QString Type=ui->le_Type->text();
    int NombreP=ui->le_NombreP->text().toInt();
    Societe C(id,nom,Datee,Domaine,Adresse,Postes,Type,NombreP);

    QMessageBox msgBox;
bool test=C.ajouter();
    if(test)
    {
        msgBox.setText(("Ajout avec success."));
        ui->tab_societe->setModel(C.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Societe C1;C1.setid(ui->le_id_supp->text().toInt());
bool test=C1.supprimer(C1.getid());

QMessageBox msgBox;

if(test)
{

    msgBox.setText(("Supression avec success."));
    ui->tab_societe->setModel(C.afficher());
}
else

    msgBox.setText("Echec de suppression");
msgBox.exec();

}




void MainWindow::on_pb_modifier_clicked()
{
    Societe s;
       int id=ui->le_id_m->text().toInt();
     QString nom=ui->le_nom_m->text();
     int Datee=ui->le_date_m->text().toInt();
      QString Domaine=ui->le_domaine_m->text();
     QString Adresse=ui->le_adresse_m->text();
     QString Postes=ui->le_postes_m->text();
     QString Type=ui->le_type_m->text();
     int NombreP=ui->le_nbp_m->text().toInt();
      bool test=s.modifier(id,nom,Datee,Domaine,Adresse,Postes,Type,NombreP);

       if (test)
       {
           // Refresh (Actualiser)
            ui->tab_societe->setModel(s.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("modification effectué.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                      QObject::tr("modification non effectué.\n"
                                  "Click Cancel to exit."),QMessageBox::Cancel);
}
