#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_etudiant->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    Etudiant E(id,nom,prenom);

    QMessageBox msgBox;
bool test=E.ajouter();
    if(test)
    {
        msgBox.setText(("Ajout avec success."));
        ui->tab_etudiant->setModel(E.afficher());
    }
    else
        msgBox.setText("Echec d'ajout");
    msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    Etudiant E1;E1.setid(ui->le_id_supp->text().toInt());
bool test=E1.supprimer(E1.getid());

QMessageBox msgBox;

if(test)
{
    msgBox.setText(("Supression avec success."));
ui->tab_etudiant->setModel(E.afficher());
}
else
    msgBox.setText("Echec de suppression");
msgBox.exec();
}
