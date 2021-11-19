#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "societe.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QSqlQuery>
#include<QDebug>
#include<QApplication>
#include<QFileDialog>
#include<QDesktopServices>
#include<QUrl>
#include <QString>
#include<QPixmap>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChartView>
#include "notif.h"

#include <smtp.h>
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
    {
        msgBox.setText("Echec d'ajout");
    msgBox.exec();
    }
    QSqlQuery query;
     query.prepare("select NombreP from societe where NombreP < 20");
     query.exec();
     query.next();
     int q=query.value(0).toInt();
     QString nomm=query.value(0).toString();
     if(q<=20)
     {
        notif n;
        n.notif_system();
     }
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

void MainWindow::on_pushButton_2_clicked()
{
    Smtp* smtp = new Smtp("dhia.zeddini.14@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    //if( !files.isEmpty() )
        //smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    //else
        smtp->sendMail("nourgh27@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->text());
}


void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    //ui->subject->clear();
    //ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void MainWindow::on_pushButton_clicked()
{
   ui->tableView->setModel(C.tricroissant());
   ui->tab_societe->setModel(C.afficher());
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableView->setModel(C.trideccroissant());
    ui->tab_societe->setModel(C.afficher());

}

void MainWindow::on_pb_tri_nom_clicked()
{
    ui->tableView->setModel(C.trinom());
    ui->tab_societe->setModel(C.afficher());

}



void MainWindow::on_pb_tri_domaine_clicked()
{
    ui->tableView->setModel(C.tridoamine());
    ui->tab_societe->setModel(C.afficher());
}
void MainWindow::on_rechPB_clicked()
{

    QMessageBox msgBox;

            QSqlQuery query;
            int id=0,NombreP=0,Datee=0;
            QString nom="",Domaine="",Adresse="",Postes="",Type="";


            int critere=ui->comboRech->currentIndex();
            if(critere==0)
            {

                id=ui->leRech->text().toInt();

                //d=C1.getId();

                //x.chercherClient(critere);
                query.prepare("SELECT * FROM societe WHERE id =:id " );
                query.bindValue(":id",id);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    Datee=query.value(2).toInt();
                    Domaine=query.value(3).toString();
                    Adresse=query.value(4).toString();
                    Postes=query.value(5).toString();
                    Type=query.value(6).toString();
                    NombreP=query.value(7).toInt();

               }
            }
            else if(critere==1)
            {
                nom=ui->leRech->text();

                //d=C1.getId();

                //x.chercherClient(critere);
                query.prepare("SELECT * FROM societe WHERE nom =:nom " );
                query.bindValue(":nom",nom);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    Datee=query.value(2).toInt();
                    Domaine=query.value(3).toString();
                    Adresse=query.value(4).toString();
                    Postes=query.value(5).toString();
                    Type=query.value(6).toString();
                    NombreP=query.value(7).toInt();
}
            }
            else
            {
                NombreP=ui->leRech->text().toUInt();

                //d=C1.getId();

                //x.chercherClient(critere);
                query.prepare("SELECT * FROM societe WHERE NombreP =:NombreP " );
                query.bindValue(":NombreP", NombreP);
                query.exec();




                while(query.next())
               {
                    id=query.value(0).toInt();

                    nom=query.value(1).toString();
                    Datee=query.value(2).toInt();
                    Domaine=query.value(3).toString();
                    Adresse=query.value(4).toString();
                    Postes=query.value(5).toString();
                    Type=query.value(6).toString();
                    NombreP=query.value(7).toInt();

               }
            }
            if(Datee==0)
            {


                  QMessageBox::critical(nullptr, QObject::tr("Societe not found"),
                           QObject::tr("try again"), QMessageBox::Cancel);


            }
            else
            {

                msgBox.setText("FOUND");
                ui->lid->setText(QString::number(id));
                ui->lnom->setText(nom);
                ui->ldate->setText(QString::number(Datee));
               ui->ldomain->setText(Domaine);
                ui->ladresse->setText(Adresse);
                ui->lpostes->setText(Postes);
                ui->lnombrep->setText(QString::number(NombreP));
                msgBox.exec();
            }
 }






void MainWindow::on_statisique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                               model->setQuery("select * from societe where nom = 'Ooredoo' ");
                               float e=model->rowCount();
                               model->setQuery("select * from societe where nom = 'Orange' ");
                               float ee=model->rowCount();
                               model->setQuery("select * from societe where nom = 'Actia' ");
                               float eee=model->rowCount();
                               float total=e+ee+eee;
                               QString a=QString("Ooredoo "+QString::number((e*100)/total,'f',2)+"%" );
                               QString b=QString("Orange"+QString::number((ee*100)/total,'f',2)+"%" );
                               QString c=QString("Actia"+QString::number((eee*100)/total,'f',2)+"%" );
                               QPieSeries *series = new QPieSeries();
                               series->append(a,e);
                               series->append(b,ee);
                               series->append(c,eee);
                       if (e!=0)
                       {QPieSlice *slice = series->slices().at(0);
                        slice->setLabelVisible();
                        slice->setPen(QPen());}
                       if ( ee!=0)
                       {
                                // Add label, explode and define brush for 2nd slice
                                QPieSlice *slice1 = series->slices().at(1);
                                //slice1->setExploded();
                                slice1->setLabelVisible();
                       }
                       if(eee!=0)
                       {
                                // Add labels to rest of slices
                                QPieSlice *slice2 = series->slices().at(2);
                                //slice1->setExploded();
                                slice2->setLabelVisible();
                       }
                               // Create the chart widget
                               QChart *chart = new QChart();
                               // Add data to chart with title and hide legend
                               chart->addSeries(series);
                               chart->setTitle("Pourcentage des societes importants : nombre de societe: "+ QString::number(total));
                               chart->legend()->hide();
                               // Used to display the chart
                               QChartView *chartView = new QChartView(chart);
                               chartView->setRenderHint(QPainter::Antialiasing);
                               chartView->resize(1000,500);
                               chartView->show();
}


void MainWindow::on_regarder_clicked()
{
    QString filename=QFileDialog::getOpenFileName (
                this,
    tr("Open File"),
    "C:/Users/Mega-PC/Downloads/VID",
    "All files (*.*);;Text File (*.txt);;Music file(*.mp3)"
    ) ;
    QDesktopServices::openUrl(QUrl("file:///"+filename));
   // QMessageBox::information (this,tr("File Name"),filename);
}



void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_societe->setModel(C.afficher());
                     }
                     else {
                       ui->tab_societe->setModel(C.cherchernom(ch)) ;
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_societe->setModel(C.afficher());
                     }
                     else {
                       ui->tab_societe->setModel(C.chercherid(ch)) ;
    }
}
