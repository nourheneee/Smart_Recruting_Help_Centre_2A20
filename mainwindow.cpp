#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reclamation.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->num_reclamation->setValidator(new QIntValidator(10000, 99999, this));
    ui->tab_reclamation->setModel(r.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pb_ajouter_clicked()
{
    int num_reclamation=ui->num_reclamation->text().toInt();
    QString date=ui->date->text();
    QString poste=ui->poste->text();
    QString sujet=ui->sujet->toPlainText();



     reclamation r(num_reclamation,date,poste,sujet);
   bool test=r.ajouter();
   if(test)
   {

       QMessageBox::information(nullptr,QObject::tr("OK"),
       QObject::tr("Ajout effectué\n"
       "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_reclamation->setModel(r.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
       QObject::tr("Ajout not effectué.\n"
       "Click Cancel to exit"), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_clicked()
{
    int num_reclamation=ui->num_reclamation->text().toInt();
    QString date=ui->date->text();
    QString poste=ui->poste->text();
    QString sujet=ui->sujet->toPlainText();


    reclamation r;
           bool test;
           test=r.modifier(num_reclamation,date,poste,sujet);
           if(test)
           {
              ui->tab_reclamation->setModel(r.afficher());

              QMessageBox::information(nullptr,QObject::tr("modifier "),
                QObject::tr("  modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("modifier "),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_pb_supprimer_clicked()
{
    reclamation r;
    r.setnum_reclamation(ui->num_reclamation->text().toInt());
    bool test=r.supprimer(r.getnum_reclamation());

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("Suppression avec succes.\n"
        "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_reclamation->setModel(r.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
        QObject::tr("Echec de suppression.\n"
        "Click Cancel to exit"), QMessageBox::Cancel);
}
