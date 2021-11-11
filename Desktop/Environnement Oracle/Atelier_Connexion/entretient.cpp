#include "entretient.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QObject>
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
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEXE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESS"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EXPERIENCE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("CIN"));

    return model;
}

