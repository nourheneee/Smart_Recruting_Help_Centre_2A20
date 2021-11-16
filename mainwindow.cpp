#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include <QObject>
#include <QComboBox>
#include<QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

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


void MainWindow::on_ajouter_client_clicked()
{
    {
        client tmpclient;
        int id= ui->lineEdit_ajout_id->text().toInt();
        QString nom=ui->lineEdit_ajout_nom->text();
        QString prenom=ui->lineEdit_ajout_prenom->text();
        int phone=ui->lineEdit_ajout_phone->text().toInt();
        QString mail= ui->lineEdit_ajout_mail->text();

        client cl(id,nom,prenom,phone,mail);

    bool test=cl.ajouter();
        if( test)
        {
            ui->tableView_client->setModel(tmpclient.afficher());//refresh
           ui->lineEdit_ajout_id->clear();
           ui->lineEdit_ajout_nom->clear();
           ui->lineEdit_ajout_prenom->clear();
           ui->lineEdit_ajout_phone->clear();
            ui->lineEdit_ajout_mail->clear();
            QMessageBox ::information(nullptr,QObject::tr("ajouter un client"),
                                              QObject::tr("client ajouté.\n"
                                                  "click ok to exit"),QMessageBox::Ok);
        }

        else
        {
            QMessageBox ::critical(nullptr,QObject::tr("ajouter un client"),
                                              QObject::tr("Erreur.\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);
        }


    }
}



void MainWindow::on_supp_client_clicked()
{
    client tmpclient;
    int id =ui->lineEdit_supp_client->text().toInt();
    QMessageBox msgbox;
    msgbox.setWindowTitle("supprimer");
    msgbox.setText("voulez_vous supprimer ce client?");
    msgbox.setStandardButtons(QMessageBox ::Yes);
    msgbox.addButton(QMessageBox::No);
    if(msgbox.exec()==QMessageBox::Yes)

    {
        bool test=tmpclient.supprimer(id);

    if(test)
    {
        ui->tableView_client->setModel(tmpclient.afficher());
        ui->lineEdit_supp_client->clear();
        QMessageBox ::information(nullptr,QObject::tr("supprimer un client"),
                                          QObject::tr("client supprimé.\n"
                                              "click ok to exit"),QMessageBox::Ok);

    }
    else
    {
        QMessageBox ::critical(nullptr,QObject::tr("supprimer un client"),
                                          QObject::tr("Erreur.\n"
                                              "click cancel to exit"),QMessageBox::Cancel);
    }
    }
    else
        ui->tableView_client->setModel(tmpclient.afficher());
}

void MainWindow::on_modifier_client_clicked()
{
    client tmpclient;
    QString nom = ui->lineEdit_modif_nom->text();
         QString prenom = ui->lineEdit_modif_prenom->text();
         int phone =ui->lineEdit_modif_phone->text().toInt();
         QString mail=ui->lineEdit_modif_mail->text();
         int id =ui->lineEdit_modif_id->text().toInt();

         bool test=tmpclient.modifier_client(id,nom,prenom,phone,mail);
         if(test)
         { ui->tableView_client->setModel(tmpclient.afficher());
                 ui->lineEdit_modif_id->clear();
                 ui->lineEdit_modif_nom->clear();
                 ui->lineEdit_modif_prenom->clear();
                 ui->lineEdit_modif_phone->clear();
                 ui->lineEdit_modif_mail->clear();
             QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                               QObject::tr("client modifié.\n"
                                                   "click ok to exit"),QMessageBox::Ok);

         }
         else
         {
             QMessageBox ::critical(nullptr,QObject::tr("supprimer un client"),
                                               QObject::tr("Erreur.\n"
                                                   "click cancel to exit"),QMessageBox::Cancel);
         }
}

void MainWindow::on_transferer_clicked()
{
    int row=ui->tableView_client->selectionModel()->currentIndex().row();
       QString id=ui->tableView_client->model()->index(row,0).data().toString();
       QString nom=ui->tableView_client->model()->index(row,1).data().toString();
       QString prenom=ui->tableView_client->model()->index(row,2).data().toString();
       QString phone=ui->tableView_client->model()->index(row,4).data().toString();
       QString mail=ui->tableView_client->model()->index(row,3).data().toString();
       if(row==-1)
       {
           QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                             QObject::tr("aucune selection.\n"
                                                 "click ok to exit"),QMessageBox::Ok);
       }
       else
       {
           ui->lineEdit_modif_id->setText(id);
           ui->lineEdit_modif_nom->setText(nom);
           ui->lineEdit_modif_prenom->setText(prenom);
           ui->lineEdit_modif_phone->setText(phone);
           ui->lineEdit_modif_mail->setText(mail);
       }
}
