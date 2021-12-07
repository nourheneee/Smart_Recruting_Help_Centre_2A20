#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include"connection.h"
#include"login.h"
#include"login_bd.h"
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    login_bd l;
     l.fermerConnexion1();

         Connection c;
         c.createconnect();


         bool test;
         test=c.ouvrirConnexion();



    ui->setupUi(this);
     ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
     ui->le_id_r->setValidator( new QIntValidator(0, 99999999, this));
     ui->le_age->setValidator(new QIntValidator(0, 99, this));
      ui->le_absences->setValidator(new QIntValidator(0, 99, this));
       ui->le_heures_de_travail->setValidator(new QIntValidator(0, 9999, this));
      // ui->box_sexe->addItem("");
        ui->box_sexe->addItem("Femme");
         ui->box_sexe->addItem("Homme");


     ui->table_id->setModel(E.afficher_id());
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
  // QString sexe=ui->box_sexe->text();
   QString sexe=ui->box_sexe->currentText();
   int age=ui->le_age->text().toInt();

   Employe E(id,poste,salaire,heures_de_travail,absences,nom,prenom,sexe,age);
bool test=E.ajouter();
QMessageBox msgBox;

if(ui->le_id->text().isEmpty()||ui->le_poste->text().isEmpty()||ui->le_salaire->text().isNull()||ui->le_heures_de_travail->text().isNull()||ui->le_absences->text().isEmpty()||ui->le_nom->text().isEmpty()||ui->le_prenom->text().isNull()||ui-> box_sexe->currentText().isNull()||ui->le_age->text().isNull())
        {
            QMessageBox::information(nullptr, QObject::tr("ERROR"),
            QObject::tr("Please Fill All Data"), QMessageBox::Ok);
        }
//else
//bool test=E.ajouter();
//QMessageBox msgBox;
if(test)
{

    msgBox.setText("Ajout avec suces.");
    ui->table_id->setModel(E.afficher_id());
    ui->tab_employe->setModel(E.afficher());
}
    else


        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}



void MainWindow::on_pb_supprimer_clicked()
{
  Employe E1;
 // E1.setid(ui->le_id_supp->text().toInt());
  E1.setid(ui->le_id->text().toInt());
  E1.setid(ui->table_id->currentText().toInt());
bool test=E1.supprimer(E1.getid());
QMessageBox msgBox;
if(test)
{ msgBox.setText("Suppression avec succes.");
    //QMessageBox::msgBox(nullptr, QObject::tr("OK")),
            //QObject::tr("suppression effectué.\n"
                        //"Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_employe->setModel(E.afficher());
    ui->table_id->setModel(E.afficher_id());
}

else
{
   // QMessageBox::critical(nullptr,QObject::tr("Not ok"),
            //QObject::tr("Suppression non effectué.\n"
                     // "Click Cancel to exit."  ), QMessageBox::Cancel);
     msgBox.setText("Echec de suppression");
msgBox.exec();
}
}

void MainWindow::on_pb_modifier_clicked()
{
    Employe e;
   // int id=ui->table_id->currentText().toInt();
   int id=ui->le_id->text().toInt();
    QString poste=ui->le_poste->text();
    int salaire=ui->le_salaire->text().toInt();
    int heures_de_travail=ui->le_heures_de_travail->text().toInt();
    int absences =ui->le_absences->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    //QString sexe=ui->box_sexe->text();
     QString sexe=ui->box_sexe->currentText();
    int age=ui->le_age->text().toInt();

    bool test=e.modifier(id,poste,salaire,heures_de_travail,absences,nom,prenom,sexe,age);



           if (test)
                 {

                      ui->tab_employe->setModel(e.afficher());
                      ui->table_id->setModel(E.afficher_id());
                     QMessageBox::information(nullptr,QObject::tr("ok"),
                                              QObject::tr("modification effectué.\n"
                                                          "click Cancel to exit."),QMessageBox::Cancel);
                 }
                 else
                     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("modification non effectué.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
          }








void MainWindow::on_pb_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"),"",tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(filename, QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image = image.scaledToWidth(ui->le_image->width(),Qt::SmoothTransformation);
            ui->le_image->setPixmap(QPixmap::fromImage(image));

        }
        else
        {
            //Error handling
        }
    }
}




void MainWindow::on_pb_trier_sexe_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by sexe ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("poste"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("heures_de_travail"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("absences"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("age"));

ui->tabler->setModel(model);
ui->tabler->show();
msgBox.setText("Tri avec succès.");
msgBox.exec();


}

void MainWindow::on_pb_trier_salaire_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by salaire ASC");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("poste"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("heures_de_travail"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("absences"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("age"));

ui->tabler->setModel(model);
ui->tabler->show();
msgBox.setText("Tri avec succès.");
msgBox.exec();

}

void MainWindow::on_pb_trirer_poste_clicked()
{
    QMessageBox msgBox ;
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE order by poste ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("poste"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("heures_de_travail"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("absences"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("sexe"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("age"));

ui->tabler->setModel(model);
ui->tabler->show();
msgBox.setText("Tri avec succès.");
msgBox.exec();

}


 QT_CHARTS_USE_NAMESPACE
void MainWindow::on_pb_age_stat_clicked()
{


            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from EMPLOYE where AGE < 20 ");
            float tranche_age1=model->rowCount();
            model->setQuery("select * from EMPLOYE where AGE  between 20 and 35 ");
            float tranche_age2=model->rowCount();
            model->setQuery("select * from EMPLOYE where AGE >35 ");
            float tranche_age3=model->rowCount();
            float total=tranche_age1+tranche_age2+tranche_age3;
            QString a=QString("moins de 20 ans . "+QString::number((tranche_age1*100)/total,'f',2)+"%" );
            QString b=QString("entre 20 et 35 ans .  "+QString::number((tranche_age2*100)/total,'f',2)+"%" );
            QString c=QString("plus de 35 ans ."+QString::number((tranche_age3*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,tranche_age1);
            series->append(b,tranche_age2);
            series->append(c,tranche_age3);
            if (tranche_age1!=0)
            {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( tranche_age2!=0)
            {

                QPieSlice *slice1 = series->slices().at(1);

                slice1->setLabelVisible();
            }
            if(tranche_age3!=0)
            {

                QPieSlice *slice2 = series->slices().at(2);

                slice2->setLabelVisible();
            }

            QChart *chart = new QChart();

            chart->addSeries(series);
            chart->setTitle("Age Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
            chart->legend()->hide();

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();
    }



void MainWindow::on_pb_absences_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE where ABSENCES < 1 ");
    float tranche_absences1=model->rowCount();
    model->setQuery("select * from EMPLOYE where ABSENCES  between 1 and 10 ");
    float tranche_absences2=model->rowCount();
    model->setQuery("select * from EMPLOYE where Absences >10 ");
    float tranche_absences3=model->rowCount();
    float total=tranche_absences1+tranche_absences2+tranche_absences3;
    QString a=QString("aucune absence . "+QString::number((tranche_absences1*100)/total,'f',2)+"%" );
    QString b=QString("entre 1 et 10 absences .  "+QString::number((tranche_absences2*100)/total,'f',2)+"%" );
    QString c=QString("plus de 10 absences ."+QString::number((tranche_absences3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_absences1);
    series->append(b,tranche_absences2);
    series->append(c,tranche_absences3);
    if (tranche_absences1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_absences2!=0)
    {

        QPieSlice *slice1 = series->slices().at(1);

        slice1->setLabelVisible();
    }
    if(tranche_absences3!=0)
    {

        QPieSlice *slice2 = series->slices().at(2);

        slice2->setLabelVisible();
    }

    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->setTitle("Absences Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}



void MainWindow::on_pb_heures_de_travail_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE where HEURES_DE_TRAVAIL < 20 ");
    float tranche_heure1=model->rowCount();
    model->setQuery("select * from EMPLOYE where HEURES_DE_TRAVAIL  between 20 and 40 ");
    float tranche_heure2=model->rowCount();
    model->setQuery("select * from EMPLOYE where HEURES_DE_TRAVAIL >40 ");
    float tranche_heure3=model->rowCount();
    float total=tranche_heure1+tranche_heure2+tranche_heure3;
    QString a=QString("moins de 20 heures de travail. "+QString::number((tranche_heure1*100)/total,'f',2)+"%" );
    QString b=QString("entre 20 et 40 heures de travail .  "+QString::number((tranche_heure2*100)/total,'f',2)+"%" );
    QString c=QString("plus de 40 heures de travail ."+QString::number((tranche_heure3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_heure1);
    series->append(b,tranche_heure2);
    series->append(c,tranche_heure3);
    if (tranche_heure1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_heure2!=0)
    {

        QPieSlice *slice1 = series->slices().at(1);

        slice1->setLabelVisible();
    }
    if(tranche_heure3!=0)
    {

        QPieSlice *slice2 = series->slices().at(2);

        slice2->setLabelVisible();
    }

    QChart *chart = new QChart();

    chart->addSeries(series);
    chart->setTitle("Heures_de_taravail Par Pourcentage des Employes :Nombre Des Employes "+ QString::number(total));
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}





void MainWindow::on_le_id_r_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tabler->setModel(E.afficher());
                     }
                     else {
                       ui->tabler->setModel(E.recherche_id(ch)) ;
}
}

void MainWindow::on_le_nom_r_textChanged(const QString &arg2)
{
    QString ch = arg2;

                     if (ch=="")
                     {
                         ui->tabler->setModel(E.afficher());
                     }
                     else {
                       ui->tabler->setModel(E.recherche_nom(ch)) ;
}
}

void MainWindow::on_le_poste_r_textChanged(const QString &arg3)
{
    QString ch = arg3;

                     if (ch=="")
                     {
                         ui->tabler->setModel(E.afficher());
                     }
                     else {
                       ui->tabler->setModel(E.recherche_poste(ch)) ;
}
}
