#include "entretient.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QObject>
#include <QtCharts/QChartView>
#include <QSystemTrayIcon>
#include <QtMultimedia/QSound>

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
entretient::entretient()

{
CIN=0; NOM=""; PRENOM="";SEXE="";DATE_NAISSANCE=0;AGE=0;ADRESS="";EXPERIENCE="";
}

entretient::entretient(int CIN,QString NOM,QString PRENOM,QString SEXE,int DATE_NAISSANCE ,int AGE,QString ADRESS,QString EXPERIENCE)
{this->CIN=CIN; this->NOM=NOM; this->PRENOM=PRENOM; this->SEXE=SEXE; this->DATE_NAISSANCE=DATE_NAISSANCE; this->AGE=AGE; this->ADRESS=ADRESS; this->EXPERIENCE=EXPERIENCE;}
int entretient::getCIN(){return CIN;}
QString entretient::getNOM(){return NOM;}
QString entretient::getPRENOM(){return PRENOM;}
QString entretient::getSEXE(){return SEXE;}
int entretient::getDATE_NAISSANCE(){return DATE_NAISSANCE;}
int entretient::getAGE(){return AGE;}
QString entretient::getADRESS(){return ADRESS;}
QString entretient::getEXPERIENCE(){return EXPERIENCE;}
void entretient::setNOM(QString NOM){this->NOM=NOM;}
void entretient::setPRENOM(QString PRENOM){this->PRENOM=PRENOM;}
void entretient::setSEXE(QString SEXE){this->SEXE=SEXE;}
void entretient::setDATE_NAISSANCE(int DATE_NAISSANCE){this->DATE_NAISSANCE=DATE_NAISSANCE;}
void entretient::setAGE(int AGE){this->AGE=AGE;}
void entretient::setADRESS(QString ADRESS){this->ADRESS=ADRESS;}
void entretient::setCIN(int CIN){this->CIN=CIN;}
void entretient::setEXPERIENCE(QString EXPERIENCE){this->EXPERIENCE=EXPERIENCE;}

bool entretient::ajouter()
{
    QSqlQuery query;
    QString CIN_string=QString::number(CIN);
    QString AGE_string=QString::number(AGE);
    QString DATE_NAISSANCE_string=QString::number(DATE_NAISSANCE);
          query.prepare("INSERT INTO ENTRETIENT(NOM,PRENOM,AGE,SEXE,DATE_NAISSANCE,ADRESS,EXPERIENCE,CIN)"
                        "VALUES (:NOM,:PRENOM,:AGE,:SEXE,:DATE_NAISSANCE,:ADRESS,:EXPERIENCE,:CIN)");
          query.bindValue(":CIN", CIN);
          query.bindValue(":NOM", NOM);
          query.bindValue(":PRENOM", PRENOM);
           query.bindValue(":SEXE", SEXE);
            query.bindValue(":DATE_NAISSANCE", DATE_NAISSANCE);
             query.bindValue(":AGE", AGE);
              query.bindValue(":ADRESS", ADRESS);
               query.bindValue(":EXPERIENCE", EXPERIENCE);


    return query.exec();
}
bool entretient::supprimer(int CIN)
{
    QSqlQuery query;

          query.prepare(" Delete from ENTretient where CIN=:CIN");
          query.bindValue(":CIN", CIN);




          return query.exec();
      }

QSqlQueryModel* entretient::afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ENTRETIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXPERIENCE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

bool entretient::update()
{
    QSqlQuery  query;
query.prepare("UPDATE ENTRETIENT SET NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE,SEXE=:SEXE,DATE_NAISSANCE=:DATE_NAISSANCE,ADRESS=:ADRESS,EXPERIENCE=:EXPERIENCE WHERE CIN=:CIN");
query.bindValue(":NOM",NOM);
query.bindValue(":PRENOM",PRENOM);
query.bindValue(":AGE",AGE);
query.bindValue(":SEXE",SEXE);
query.bindValue(":DATE_NAISSANCE",DATE_NAISSANCE);
query.bindValue(":ADRESS",ADRESS);
query.bindValue(":EXPERIENCE",EXPERIENCE);
query.bindValue(":CIN",CIN);
return query.exec();
}

QSqlQueryModel* entretient::chercher(QString NOM)
 {
     QSqlQuery query ;
     QSqlQueryModel* model=new QSqlQueryModel();
    //query->prepare("select * from SERVICE where CIN LIKE '"+n+"%' or NOM LIKE '"+n+"%' or AGE LIKE '"+n+"%'");
    //model->setQuery("select * from SERVICE where CIN LIKE '"+n+"%' or NOM LIKE '"+n+"%' or AGE LIKE '"+n+"%'");
    query.prepare("select * from ENTRETIENT where NOM=:NOM");
    query.bindValue(":NOM",NOM);
    query.exec();
    model->setQuery(query);

    return model;
    //}

 }
QSqlQueryModel* entretient::trier_nom()
{

  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ENTRETIENT order by NOM ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("SEXE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESS"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXPERIENCE"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}
QSqlQueryModel* entretient::trier_age()
{

  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ENTRETIENT order by AGE ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("SEXE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESS"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXPERIENCE"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

QSqlQueryModel* entretient::trier_prenom()
{

  QSqlQueryModel* model=new QSqlQueryModel();

       model->setQuery("SELECT* FROM ENTRETIENT order by AGE ");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOM"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("SEXE"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESS"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("EXPERIENCE"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

void entretient::notification(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("operation effectué",cls,QSystemTrayIcon::Information,15000);
  //QSound newMessage(":/mixkit-positive-interface-beep-221.wav");
   //newMessage.play();
}

QSqlQueryModel * entretient::afficherCIN()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select cin from entretient");
    query.exec();


    model->setQuery(query);

    return model;
}

QString entretient::read(QString File)
{
    QFile file(File);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());

    QTextStream in(&file);

    return  in.readAll();

}

void entretient::write(QString time, QString txt, QString File)
{
    QFile file(File);
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream<<time<<" "<<txt<<endl;
        file.close();
    }
}

QString entretient::time()
{
    QDateTime time=time.currentDateTime();
    return  time.toString();

}

void entretient::clearTable(QTableView *table)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->clear();
    table->setModel(model);
}

void entretient::rechercher(QTableView *table, QString x)
{
   QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *query =new QSqlQuery;
   query->prepare("select * from entretient WHERE regexp_like(NOM, :NOM)");
   query->bindValue(":NOM",x);

   if(x=="")
   {
       query->prepare("select * from entretient;");
   }
   query->exec();
   model->setQuery(*query);
   table->setModel(model);
   table->show();
}
