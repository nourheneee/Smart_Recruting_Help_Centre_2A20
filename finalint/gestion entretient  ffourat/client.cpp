#include "client.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>
#include <QLocale>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

client::client()
{
   id=0;
   nom=" ";
   prenom=" ";
   age=0;
   region=" ";

}

client::client(int id,QString nom,QString prenom,int age,QString region)
{
   this->id=id;
   this->nom=nom.toUpper();
   this->prenom=prenom.toUpper();
   this->age=age;
   this->region=region.toUpper();

}
int client::get_id(){return id;}
void client::Set_id(int val){ id=val;}
void client::Set_nom(QString val) { nom = val; }
QString client::get_nom(){return nom;}
void client::Set_prenom(QString val) { nom = val; }
QString client:: get_prenom(){return prenom;}
void client::Set_region(QString val) { nom = val; }
QString client::get_region(){return region;}
void client::Set_age(int val) { nom = val; }
int client::get_age(){return age;}
bool client::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO client (id,nom,prenom,age,region)"
                          "VALUES (:id, :nom, :prenom, :age, :region)");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":region",region);
    return query.exec();
}
QSqlQueryModel *client::afficher()
{
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select *from client");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("PRENOM"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("age"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("region"));
 return model;
}
bool client::supprimer(int id)
{
    QSqlQuery qry;
    qry.prepare("Delete from reclamation where num_reclamation=:num_reclamation");
    qry.bindValue(0,id);
    return qry.exec();
}
bool client :: modifier_client(int id ,QString nom,QString prenom,int age,QString region)
{

    QSqlQuery qry;
        qry.prepare("UPDATE client set NOM=(?),PRENOM=(?),age=(?),region=(?) where ID=(?) ");


        qry.addBindValue(nom);
        qry.addBindValue(prenom);
        qry.addBindValue(age);
        qry.addBindValue(region);
        qry.addBindValue(id);
        return  qry.exec();
}
QSqlQueryModel *client::tri_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client order by ID" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));

 return model;

}

QSqlQueryModel *client::tri_prenom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client order by PRENOM" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));
    return model;

}

QSqlQueryModel *client::tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from client order by NOM" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("REGION"));

 return model;

}

QSqlQueryModel *client::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM client WHERE ID  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or prenom  LIKE'%"+rech+"%' or age  LIKE'%"+rech+"%' or region LIKE'%"+rech+"%' ");
    return model;
}
