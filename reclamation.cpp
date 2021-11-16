#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

reclamation::reclamation()
{
num_reclamation=0; poste=""; sujet="";date="";
}
reclamation::reclamation(int num_reclamation,QString date,QString poste,QString sujet)
{this->num_reclamation=num_reclamation;this->date=date; this->poste=poste; this->sujet=sujet;}
int reclamation::getnum_reclamation(){return num_reclamation;}
QString reclamation::getdate(){return date;}
QString reclamation::getposte(){return poste;}
QString reclamation::getsujet(){return sujet;}
void reclamation::setnum_reclamation(int num_reclamation){this->num_reclamation=num_reclamation;}
void reclamation::setdate(QString date){this->date=date;}
void reclamation::setposte(QString poste){this->poste=poste;}
void reclamation::setsujet(QString sujet){this->sujet=sujet;}
bool reclamation::ajouter()
{
QSqlQuery query;
    QString num_reclamation_string=QString::number(num_reclamation );

query.prepare("INSERT INTO reclamation (num_reclamation,date_reclamation,poste,sujet_reclamation) "
  "VALUES (:num_reclamation,:date, :poste, :sujet)");
     query.bindValue(0,num_reclamation_string);
     query.bindValue(1,date);
     query.bindValue(2,poste);
     query.bindValue(3, sujet);

          return query.exec();
}
bool reclamation::supprimer(int num_reclamation)
{
    QSqlQuery query;
         query.prepare("Delete from reclamation where num_reclamation=:num_reclamation");
         query.bindValue(0,num_reclamation);

         return query.exec();
}
QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("SELECT* FROM reclamation");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_reclamation"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_reclamation"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sujet_reclamation"));


return model;
}
bool reclamation::modifier(int num_reclamation,QString date,QString poste,QString sujet)

{

    QString num_reclamation_string=QString::number(num_reclamation);

    QSqlQuery query;
       query.prepare("update reclamation set date_reclamation=:date,poste=:poste,sujet_reclamation=:sujet where num_reclamation=:num_reclamation");


       query.bindValue(":num_reclamation",num_reclamation_string);
       query.bindValue(":date",date);
       query.bindValue(":poste",poste);
       query.bindValue(":sujet",sujet);

return query.exec();
}
