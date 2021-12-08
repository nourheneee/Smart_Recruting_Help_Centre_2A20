 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entretient.h"
#include <QMessageBox>
#include <QtMultimedia/QSound>
#include <QDesktopServices>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QSqlQuery>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QDebug>
#include <QCamera>
#include<QCameraViewfinderSettings>
#include<QCameraViewfinderSettingsControl>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QString>
#include<QtCharts>
#include <QDesktopServices>
#include <QPrinter>
#include<QLineSeries>
#include <QPieSeries>
#include "employe.h"
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QMessageBox>
#include <QIntValidator>
#include"connection.h"
#include<QFileDialog>
#include"reclamation.h"
#include"excel.h"
#include"societe.h"
#include "notif.h"
#include "smtp.h"
#include <QTextEdit>
#include"signup.h"
#include"client.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{






    ui->setupUi(this);
    ui->frame->hide();
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptionsMenu = new QMenu("options", this);
    mAllumerAction = new QAction("allumer", this);
    mEteindreAction = new QAction("eteindre", this);
    mCapturerAction = new QAction("capturer", this);

    mOptionsMenu->addActions({ mAllumerAction, mEteindreAction, mCapturerAction});
    ui->pb_options->setMenu(mOptionsMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mAllumerAction, &QAction::triggered, [&]() {
        mCamera->start();
    });

    connect(mEteindreAction, &QAction::triggered, [&]() {
        mCamera->stop();
    });

    connect(mCapturerAction, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "capture", "/", "image (*.jpg;*.jpeg)");
        if (filename.isEmpty())
        {
            return;
        }

        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });

  /*  QLineSeries *series = new QLineSeries();

        series->append(0,6);
        series->append(2,4);
        series->append(3,8);
        series->append(7,4);
        series->append(10,5);
        *series << QPointF(11, 1) << QPointF(13,3) << QPointF(17, 6) << QPointF(18, 3) <<QPointF(20, 2);
        QChart *chart = new QChart();
        //chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("reclamation line chart");


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    reclamation r;
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setParent(ui->horizontalFrame);
            //ui->spinBox->setValue(5);
            ui->num_reclamation->setValidator(new QIntValidator(10000, 99999, this));
            ui->tab_reclamation->setModel(r.afficher());
    ui->le_id->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_id_r->setValidator( new QIntValidator(0, 99999999, this));
    ui->le_age->setValidator(new QIntValidator(0, 99, this));
     ui->le_absences->setValidator(new QIntValidator(0, 99, this));
      ui->le_heures_de_travail->setValidator(new QIntValidator(0, 9999, this));
     // ui->box_sexe->addItem("");
       ui->box_sexe->addItem("Femme");
        ui->box_sexe->addItem("Homme");*/

Employe a;
    ui->table_id->setModel(a.afficher_id());
ui->tab_employe->setModel(E.afficher());
     son = new QSound("qrc:/sounds/mixkit-positive-interface-beep-221.wav");
      son->play();
      ui->comboBox_cin_suppr->setModel(E.afficherCIN());
      E.write(E.time(),"App started",File);
      ui->textBrowser->setText("application started");
      ui->textBrowser->setText("gestion des entretien");

  //  QSound::play(":/mixkit-positive-interface-beep-221.wav");
   // QDesktopServices::openUrl("file:///C:/Users/foura/Desktop/Environnement_Oracle/Atelier_Connexion/mixkit-positive-interface-beep-221.wav");

      int ret=A.connect_arduino(); // lancer la connexion à arduino
      switch(ret){
      case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";
      }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_temperature())); // permet de lancer
       //le slot update_label suite à la reception du signal readyRead (reception des données).
}
//QSound newMessage("sound/newChat.wave");
//newMessage.play();

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
      {QMessageBox::information(this,"Login","ss");
    E.notification("entretient ajouté");
    E.write(E.time(),"entretient ajouté",File);
    ui->textBrowser->setText("entretien ajoute");
}
      else

      QMessageBox::warning(this,"Login","failed");

//affichage
ui->tab_entretient->setModel(E.afficher());
ui->comboBox_cin_suppr->setModel(E.afficherCIN());



}



void MainWindow::on_pb_sup_clicked()
{
 entretient E1;
 E1.setCIN(ui->comboBox_cin_suppr->currentText().toInt());
 bool test=E1.supprimer(E1.getCIN());
 QMessageBox msgBox;
 if(test)
{     ui->tab_entretient->setModel(E.afficher());
     E.notification("entretient supprimé");
     msgBox.setText("sup avec SUCCES");}
 else
     msgBox.setText("Echec de sup");
     msgBox.exec();
     ui->tab_entretient->setModel(E.afficher());


}

//QT_CHARTS_USE_NAMESPACE

void MainWindow::on_pb_ajouter_2_clicked()
{

       QString NOM=ui->le_NOM_2->text();
       QString PRENOM=ui->le_PRENOM_2->text();
       int AGE=ui->le_AGE_2->text().toInt();
       QString SEXE=ui->le_SEXE_2->text();
       int DATE_NAISSANCE=ui->le_DATE_NAISSANCE_2->text().toInt();
       QString ADRESS=ui->le_ADRESS_2->text();
       QString EXPERIENCE=ui->le_EXPERINCE_2->text();
       int CIN=ui->le_CIN_2->text().toInt();
       entretient E1 (CIN, NOM, PRENOM,SEXE,DATE_NAISSANCE,AGE,ADRESS,EXPERIENCE);
       E1.update();
}

void MainWindow::on_recherche_clicked()
{

    {
         //int CIN= ui->le_nom_rech->text().toInt();
         //int AGE= ui->age_rech->text().toUInt();
         QString NOM= ui->le_nom_rech->text();
 ui->tablerecheche->setModel(E.chercher(NOM));
          entretient e;

         /*int x;
              x=e.chercher(NOM);
    if (x==1)
              {
                      QMessageBox::critical(nullptr, QObject::tr("database is open"),
                                  QObject::tr("connection successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
              }
                      else
              {
                      QMessageBox::critical(nullptr, QObject::tr("erreur"),
                                  QObject::tr("connection is not  successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

    }*/

}
}

void MainWindow::on_trier_nom_clicked()
{
   ui->table_tri->setModel(E.trier_nom());
}

void MainWindow::on_trier_age_clicked()
{
   ui->table_tri->setModel(E.trier_age());
}


void MainWindow::on_trier_prenom_clicked()
{
     ui->table_tri->setModel(E.trier_prenom());
}



void MainWindow::on_envoi_bur_clicked()
{
    QString message = ui->boit_mes_emp->text();
  ui->test->setText(message);

}

void MainWindow::on_mess_bur_clicked()
{
    QString message = ui->boite_mes_bur->text();
  ui->test->setText(message);

}
QT_CHARTS_USE_NAMESPACE
void MainWindow::on_pushButton_clicked()
{
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from ENTRETIENT where AGE < 20 ");
        float tranche_age1=model->rowCount();
        model->setQuery("select * from ENTRETIENT where AGE  between 20 and 35 ");
        float tranche_age2=model->rowCount();
        model->setQuery("select * from ENTRETIENT where AGE >35 ");
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
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            //slice1->setExploded();
            slice1->setLabelVisible();
        }
        if(tranche_age3!=0)
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
        chart->setTitle("Age Par Pourcentage des Entretients :Nombre Des Entretients "+ QString::number(total));
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString h="homme";
    QString f="femme";
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ENTRETIENT where SEXE like '%"+h+"%'");
    float tranche_age1=model->rowCount();
    model->setQuery("select * from ENTRETIENT where SEXE like '%"+f+"%' ");
    float tranche_age2=model->rowCount();
    //model->setQuery("select * from ENTRETIENT where AGE >35 ");
    //float tranche_age3=model->rowCount();
    float total=tranche_age1+tranche_age2;
    QString a=QString("hommes . "+QString::number((tranche_age1*100)/total,'f',2)+"%" );
    QString b=QString("femmes .  "+QString::number((tranche_age2*100)/total,'f',2)+"%" );
   // QString c=QString("plus de 35 ans ."+QString::number((tranche_age3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_age1);
    series->append(b,tranche_age2);
  //  series->append(c,tranche_age3);
    if (tranche_age1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_age2!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
  /*  if(tranche_age3!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }*/
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("Age Par Pourcentage des Entretients :Nombre Des Entretients "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString h="yes";
    QString f="no";
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ENTRETIENT where EXPERIENCE like '%"+h+"%'");
    float tranche_age1=model->rowCount();
    model->setQuery("select * from ENTRETIENT where EXPERIENCE like '%"+f+"%' ");
    float tranche_age2=model->rowCount();
    //model->setQuery("select * from ENTRETIENT where AGE >35 ");
    //float tranche_age3=model->rowCount();
    float total=tranche_age1+tranche_age2;
    QString a=QString("avec experience . "+QString::number((tranche_age1*100)/total,'f',2)+"%" );
    QString b=QString("sans experience .  "+QString::number((tranche_age2*100)/total,'f',2)+"%" );
   // QString c=QString("plus de 35 ans ."+QString::number((tranche_age3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_age1);
    series->append(b,tranche_age2);
  //  series->append(c,tranche_age3);
    if (tranche_age1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_age2!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
  /*  if(tranche_age3!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }*/
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("experience des Entretients :Nombre Des Entretients "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString

            link="https://www.manatal.com/resources/smartrecruiters/?utm_source=adwords&utm_medium=ppc&utm_term=smartrecruiters%20recruitment&utm_campaign=Search+Campaign+-+3+(ads+restructured)&hsa_ver=3&hsa_ad=552148707327&hsa_cam=8698778045&hsa_tgt=kwd-336246671213&hsa_net=adwords&hsa_grp=131718817121&hsa_mt=e&hsa_src=g&hsa_kw=smartrecruiters%20recruitment&hsa_acc=9327528136&gclid=CjwKCAiAs92MBhAXEiwAXTi254J14dXiSqeWXSCuzaVaYcwELuiYTN5OYyiainqG-9bjMohC45b-nhoCf9oQAvD_BwE";
      QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_le_nom_rech_textChanged(const QString &arg1)
{
    E.clearTable(ui->tablerecheche);
    QString nom=ui->le_nom_rech->text();
    E.rechercher(ui->tablerecheche,nom);
}


void MainWindow::update_temperature()
{
    QString temp = A.read_from_arduino();
    ui->valuer_temperature->setText(temp);
    qDebug()<<A.read_from_arduino();
}

void MainWindow::on_pushButton_5_clicked()
{
    A.write_arduino("1");
}

void MainWindow::on_pb_ajouter_3_clicked()
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
      ui->table_id->setModel(E1.afficher_id());
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
                      ui->table_id->setModel(e.afficher_id());
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

void MainWindow::on_le_id_r_textChanged(const QString &arg1)
{
    Employe E;

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
    Employe E;
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
    Employe E;

    QString ch = arg3;

                     if (ch=="")
                     {
                         ui->tabler->setModel(E.afficher());
                     }
                     else {
                       ui->tabler->setModel(E.recherche_poste(ch)) ;
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

void MainWindow::on_entr_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pb_ajouter_4_clicked()
{
    int num_reclamation=ui->num_reclamation->text().toInt();
    QDate date=ui->date->date();
    QString poste=ui->poste->text();
    QString sujet=ui->sujet->toPlainText();
  QString type=ui->type->currentText();

 reclamation r(num_reclamation,date,poste,sujet,type);
   //  reclamation r(num_reclamation,date,poste,sujet,type);
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

void MainWindow::on_pb_modifier_2_clicked()
{
    QSqlQuery query;
    QString num_reclamation=ui->num_reclamation->text() ;
    query.prepare("Select * from reclamation where num_reclamation=:num_reclamation");
    query.bindValue(":num_reclamation", num_reclamation) ;
    query.exec() ;
    query.next() ;
     ui->poste->setText(query.value(2).toString());
 //ui->type->setText(query.value(4).toString());
    //ui->date->setDate(query.value().toDate());


     ui->sujet->setText(query.value(3).toString());
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    reclamation r;
                r.setnum_reclamation(ui->num_reclamation->text().toInt());
                QSqlQuery query ;
                query.prepare("Select * from reclamation WHERE num_reclamation=:num_reclamation ");
                query.bindValue(":num_reclamation",r.getnum_reclamation()) ;
                query.exec();
                bool test = false;
                    test = query.next();
                    if(test)
                    {
                bool test=r.supprimer(r.getnum_reclamation());
                QMessageBox msgbox;
                if(test)
                    {msgbox.setText("Suppression avec succes.");
                        ui->tab_reclamation->setModel(r.afficher());
                        ui->num_reclamation->setText("");
                    }
                    else
                        msgbox.setText("Echec de suppression");
                    msgbox.exec();
                    }
                  else
                                 {
                                     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                     QObject::tr("num_reclamation INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                                 }
}

void MainWindow::on_pb_entrer_clicked()
{
    int num_reclamation=ui->num_reclamation->text().toInt();
    QDate date=ui->date->date();
    QString date_p=date.toString("yyyy,dd,MM");
    QString poste=ui->poste->text();
    QString sujet=ui->sujet->toPlainText();
   QString type=ui->type->currentText();

        reclamation r(num_reclamation,date,poste,sujet,type);
        QSqlQuery query ;
                query.prepare("Select * from reclamation WHERE num_reclamation=:num_reclamation ");
                query.bindValue(":num_reclamation",num_reclamation) ;
                query.exec();
                bool alreadyExist = false;
                    alreadyExist = query.next();
                    if(alreadyExist)
                    {
                bool test=r.modifier(r.getnum_reclamation());
                QMessageBox msgbox;
                if(test)
                    {
                    msgbox.setText("Modification avec succes.");
                        ui->tab_reclamation->setModel(r.afficher());
                        ui->sujet->setText("");
                        ui->date->setDate(date);
                        ui->poste->setText("");
                        ui->type->setCurrentText("");
                    }
                    else
                        msgbox.setText("Echec de modification");
                        msgbox.exec();
                    }
                  else
                                 {
                                     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                     QObject::tr("ID INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                                 }
}

void MainWindow::on_pb_tri_clicked()
{
    reclamation r;
                QString crit=ui->comboBox_Tri->currentText();
                if(crit=="num_reclamation")
                {
                    ui->tab_reclamation->setModel(r.Tri_num_reclamation());
                }
                else if(crit=="poste")
                {

                   ui->tab_reclamation->setModel(r.Tri_poste());
                }
                else
                {
                     ui->tab_reclamation->setModel(r.tri_sujet_reclamation());

                }
}

void MainWindow::on_chercher_textChanged(const QString &arg1)
{
    reclamation r;
    if(ui->chercher->text()!="")
                  {
                      QString poste=ui->chercher->text();
                      ui->tab_reclamation->setModel(r.recherche(poste));
                  }
                   else
                      ui->tab_reclamation->setModel(r.afficher());
}

void MainWindow::on_pb_excel_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                EXCEL obj(fileName, "test-bd", ui->tab_reclamation);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "num_reclamation", "char(20)");
                obj.addField(1, "poste", "char(20)");
                obj.addField(2, "date_reclamation", "char(20)");
                obj.addField(3, "sujet_reclamation", "char(20)");




                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
     }
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_pushButton_12_clicked()
{
    int id=ui->le_iddd->text().toInt();
    QString nom=ui->le_nommm->text();
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

void MainWindow::on_pb_supprimer_3_clicked()
{
    Societe C;
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

void MainWindow::on_pb_modifier_3_clicked()
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

void MainWindow::on_pushButton_9_clicked()
{
    Societe C;
    ui->tableView->setModel(C.trideccroissant());
    ui->tab_societe->setModel(C.afficher());
}

void MainWindow::on_pushButton_10_clicked()
{     Societe C;

    ui->tableView->setModel(C.tricroissant());
    ui->tab_societe->setModel(C.afficher());
}

void MainWindow::on_pb_tri_nom_clicked()
{
    Societe C;
    ui->tableView->setModel(C.trinom());
    ui->tab_societe->setModel(C.afficher());
}

void MainWindow::on_pb_tri_domaine_clicked()
{

    Societe C;

    ui->tableView->setModel(C.tridoamine());
    ui->tab_societe->setModel(C.afficher());
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
                query.bindValue("NombreP", NombreP);
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

void MainWindow::on_pushButton_11_clicked()
{
    Smtp* smtp = new Smtp("nourhen.ghodhbani@gmail.com",ui->mail_pass->text(), "Smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
//(const QString &from, const QString &to, const QString &subject, const QString &body)
    //if( !files.isEmpty() )
        //smtp->sendMail("dhia.zeddini.14@gmail.com", ui->rcpt->text() ,ui->sujet->text(), ui->msg->toPlainText(), files );
    //else
        //smtp->sendMail("nourgh27@gmail.com", ui->rcpt->text() ,ui->sujet->text(),ui->msg->text());
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

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Societe C;
    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_societe->setModel(C.afficher());
                     }
                     else {
                       ui->tab_societe->setModel(C.chercherid(ch)) ;
    }
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    Societe C;

    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_societe->setModel(C.afficher());
                     }
                     else {
                       ui->tab_societe->setModel(C.cherchernom(ch)) ;
    }
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    Societe C;

    QString ch = arg1;

                     if (ch=="")
                     {
                         ui->tab_societe->setModel(C.afficher());
                     }
                     else {
                       ui->tab_societe->setModel(C.cherchernombrep(ch)) ;
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->frame->show();
}

void MainWindow::on_logiin_clicked()
{
    QString username,password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();

    QSqlQuery qry;
    if(qry.exec("select * from SIGNUP where name= '"+username +"' and PASSWORD= '"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if (count==1)
        {   QMessageBox::information(nullptr, QObject::tr("Connected"),
                                 QObject::tr("Connexion réussite\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
            ui->stackedWidget->setCurrentIndex(1);


        }
        if (count>1)
            QMessageBox::warning(nullptr, QObject::tr("Duplicated"),
                         QObject::tr("Duplication\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
        if (count<1)
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Nom d'utilisateur ou mot de passe incorrecte\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString name=ui->lineEdit_password_2->text();
    QString username=ui->lineEdit_Username->text();
    QString password=ui->lineEdit_username_2->text();
    signup A(username,password, name);
    bool test=A.ajouter();
                if(name.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom et prénom"),
                                                                 QObject::tr("Veuillez indiquer votre nom et prénom\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
               /* else if(username.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom d'utilisateur"),
                                                                 QObject::tr("Veuillez indiquer votre nom d'utilisateur\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}*/
                else if(password.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Mot de passe"),
                                                                 QObject::tr("Veuillez indiquer votre mot de passe\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
                else if (test){
                                QMessageBox::information(nullptr, QObject::tr("OK"),
                                                         QObject::tr("Compte creer\n""Click Cancel to exit")
                                                         ,QMessageBox::Cancel);
                                ui->stackedWidget->setCurrentIndex(0);


                }
                else{
                                QMessageBox::warning(nullptr, QObject::tr("OK"),
                                             QObject::tr("Nom d'utilisateur existe déjà\n""Click Cancel to exit")
                                             ,QMessageBox::Cancel);}
}

void MainWindow::on_ajouter_client_2_clicked()
{
    client tmpclient;
    int id= ui->lineEdit_ajout_id_2->text().toInt();
    QString nom=ui->lineEdit_ajout_nom_2->text();
    QString prenom=ui->lineEdit_ajout_prenom_2->text();
    int phone=ui->lineEdit_ajout_phone_2->text().toInt();
    QString mail= ui->lineEdit_ajout_mail_2->text();

    client cl(id,nom,prenom,phone,mail);

bool test=cl.ajouter();
    if( test)
    {
        ui->tableView_client_2->setModel(tmpclient.afficher());//refresh
       ui->lineEdit_ajout_id_2->clear();
       ui->lineEdit_ajout_nom_2->clear();
       ui->lineEdit_ajout_prenom_2->clear();
       ui->lineEdit_ajout_phone_2->clear();
        ui->lineEdit_ajout_mail_2->clear();
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


void MainWindow::on_supp_client_2_clicked()
{
    client tmpclient;
    int id =ui->lineEdit_supp_client_2->text().toInt();
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
        ui->tableView_client_2->setModel(tmpclient.afficher());
        ui->lineEdit_supp_client_2->clear();
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
    {
        QMessageBox ::critical(nullptr,QObject::tr("ERROR"),
                                          QObject::tr("ID INTROUVABLE.\n"
                                              "click cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_radioButton_clicked()
{
    QString link="https://www.facebook.com/";
    QDesktopServices::openUrl(link);
}

void MainWindow::on_pb_PDF_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_client_2->model()->rowCount();
    const int columnCount = ui->tableView_client_2->model()->columnCount();
    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste RH </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)

        if (!ui->tableView_client_2->isColumnHidden(column))

            out << QString("<th>%1</th>").arg(ui->tableView_client_2->model()->headerData(column, Qt::Horizontal).toString());

    out << "</tr></thead>\n";
    // data table

    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_client_2->isColumnHidden(column))
            {
                QString data = ui->tableView_client_2->model()->data(ui->tableView_client_2->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"

        "</body>\n"

        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())

    {

        fileName.append(".pdf");

    }

     QPrinter printer (QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);
     QTextDocument doc;
     doc.setHtml(strStream);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);
}

void MainWindow::on_pb_trier_clicked()
{
    client cl;
    QString crit=ui->comboBoxTri->currentText();
    if(crit=="id")
    {
        ui->tableView_client_2->setModel(cl.tri_id());
    }
    else if(crit=="prenom")
    {
        ui->tableView_client_2->setModel(cl.tri_prenom());
    }
    else
    {
        ui->tableView_client_2->setModel(cl.tri_nom());
    }
}

void MainWindow::on_modifier_client_2_clicked()
{
    client tmpclient;
    QString nom = ui->lineEdit_modif_nom_2->text();
         QString prenom = ui->lineEdit_modif_prenom_2->text();
         int phone =ui->lineEdit_modif_phone_2->text().toInt();
         QString mail=ui->lineEdit_modif_mail_2->text();
         int id =ui->lineEdit_modif_id_2->text().toInt();

         bool test=tmpclient.modifier_client(id,nom,prenom,phone,mail);
         if(test)
         { ui->tableView_client_2->setModel(tmpclient.afficher());
                 ui->lineEdit_modif_id_2->clear();
                 ui->lineEdit_modif_nom_2->clear();
                 ui->lineEdit_modif_prenom_2->clear();
                 ui->lineEdit_modif_phone_2->clear();
                 ui->lineEdit_modif_mail_2->clear();
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

void MainWindow::on_transferer_2_clicked()
{
    int row=ui->tableView_client_2->selectionModel()->currentIndex().row();
       QString id=ui->tableView_client_2->model()->index(row,0).data().toString();
       QString nom=ui->tableView_client_2->model()->index(row,1).data().toString();
       QString prenom=ui->tableView_client_2->model()->index(row,2).data().toString();
       QString phone=ui->tableView_client_2->model()->index(row,4).data().toString();
       QString mail=ui->tableView_client_2->model()->index(row,3).data().toString();
       if(row==-1)
       {
           QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                             QObject::tr("aucune selection.\n"
                                                 "click ok to exit"),QMessageBox::Ok);
       }
       else
       {
           ui->lineEdit_modif_id_2->setText(id);
           ui->lineEdit_modif_nom_2->setText(nom);
           ui->lineEdit_modif_prenom_2->setText(prenom);
           ui->lineEdit_modif_phone_2->setText(phone);
           ui->lineEdit_modif_mail_2->setText(mail);
       }
}

void MainWindow::on_lineEdit_777_textChanged(const QString &arg1)
{
    client cl;
    ui->tableView_client_2->setModel(cl.rechercher(arg1));

}

void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
