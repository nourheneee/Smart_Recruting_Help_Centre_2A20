#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QString>
#include"connection.h"
#include<QMessageBox>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QtCharts/QChartView>

//Test Tutorial git
Employe::Employe()
{
id=0;
poste="";
salaire=0; heures_de_travail=0;absences =0;
nom=""; prenom=""; sexe="";
age=0;
}
Employe::Employe(int id , QString poste,int salaire,int heures_de_travail,int absences, QString nom, QString prenom , QString sexe,int age  )
{this->id=id; this->age=age;this->salaire=salaire; this->heures_de_travail=heures_de_travail; this->absences =absences ;  this->nom=nom ;this->prenom=prenom; this->sexe=sexe; this->poste=poste; }
int Employe::getid (){return id  ;}
QString Employe::getposte (){return poste ;}
int Employe::getsalaire (){return salaire ;}
int Employe::getheures_de_travail (){return heures_de_travail ;}
int Employe::getabsences (){return  absences ;}
QString Employe::getnom (){return nom ;}
QString Employe::getprenom (){return prenom ;}
QString Employe::getsexe (){return sexe ;}
int Employe::getage (){return age ;}
void Employe::setid (int id){this->id=id;}
void Employe::setposte (QString poste){this->poste=poste;}
void Employe::setsalaire (int salaire){this->salaire=salaire;}
void Employe::setheures_de_travail  (int heures_de_travail ){this->heures_de_travail=heures_de_travail;}
void Employe::setabsences (int absences ){this->absences=absences;}
void Employe::setnom (QString nom){this->nom=nom;}
void Employe::setprenom (QString prenom){this->prenom=prenom;}
void Employe::setsexe (QString sexe){this->sexe=sexe;}
void Employe::setage (int age){this->age=age;}


bool Employe::ajouter()
{
 QSqlQuery query;
 QString id_string=QString::number(id);
 QString salaire_string=QString::number(salaire);
 QString heures_de_travail_string=QString::number(heures_de_travail);
 QString absences_string=QString::number(absences);
 QString age_string=QString::number(age);
      query.prepare("INSERT INTO EMPLOYE(ID,POSTE,SALAIRE,HEURES_DE_TRAVAIL,ABSENCES,NOM,PRENOM,SEXE,AGE) "
                    "VALUES (:id, :poste, :salaire, :heures_de_travail, :absences, :nom, :prenom, :sexe, :age)");
      query.bindValue(":id", id_string);
      query.bindValue(":poste",poste );
      query.bindValue(":salaire", salaire_string);
      query.bindValue(":heures_de_travail",heures_de_travail_string );
      query.bindValue(":absences",absences_string );
      query.bindValue(":nom", nom);
      query.bindValue(":prenom", prenom);
      query.bindValue(":sexe", sexe);
      query.bindValue(":age", age_string);

return  query.exec();


}
bool Employe::supprimer(int id)
{
    QSqlQuery query;
        query.prepare("DELETE FROM EMPLOYE where id=:id");
        query.bindValue(0,id);

    QString id_string=QString::number(id);


    return query.exec();




}
QSqlQueryModel* Employe::afficher()
{
QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM EMPLOYE");


 return model;
}



QSqlQueryModel* Employe::afficher_id1(int id)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from EMPLOYE where ID=:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    return model;
}


QSqlQueryModel* Employe::afficher_nom(QString nom)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from EMPLOYE where NOM=:nom");
    query.bindValue(":nom",nom);
    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel* Employe::afficher_poste(QString poste)
{
    QSqlQuery query;
    QSqlQueryModel* model=new QSqlQueryModel();
    query.prepare("select * from EMPLOYE where POSTE=:poste");
    query.bindValue(":poste",poste);
    query.exec();
    model->setQuery(query);
    return model;
}







bool Employe::modifier(int id , QString poste,int salaire,int heures_de_travail,int absences, QString nom, QString prenom , QString sexe,int age)
{
    QSqlQuery query;
    QString idr=QString::number(id);
    QString salairer=QString::number(salaire);
    QString heures_de_travailr=QString::number(heures_de_travail);
    QString absencesr=QString::number(absences);
    QString ager=QString::number(age);

           query.prepare("UPDATE EMPLOYE set ID=:id,POSTE=:poste ,SALAIRE=:salaire ,HEURES_DE_TRAVAIL=:heures_de_travail,ABSENCES=:absences,NOM=:nom,PRENOM=:prenom,SEXE=:sexe,AGE=:age WHERE id=:id") ;

           query.bindValue(":id", idr);
           query.bindValue(":poste",poste );
           query.bindValue(":salaire", salairer);
           query.bindValue(":heures_de_travail",heures_de_travailr );
           query.bindValue(":absences",absencesr );
           query.bindValue(":nom", nom);
           query.bindValue(":prenom", prenom);
           query.bindValue(":sexe", sexe);
           query.bindValue(":age", ager);

     return query.exec();
}

QSqlQueryModel *Employe::recherche_id( QString q)
{
    QString res= QString::number(id);
        QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE  WHERE id like '%"+q+"%'" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("heures_de_travail"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("absences"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("age"));
     return model;
}


QSqlQueryModel *Employe::recherche_nom( QString q)
{

    QString res=nom;
    QSqlQueryModel *model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM EMPLOYE  WHERE nom like '%"+q+"%'" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("heures_de_travail"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("absences"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("age"));
     return model;
}

QSqlQueryModel *Employe::recherche_poste( QString q)
{

    QString res=poste;
    QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE  WHERE poste like '%"+q+"%'" );
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("poste"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("salaire"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("heures_de_travail"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("absences"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(6, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(7, Qt::Horizontal, QObject::tr("sexe"));
            model->setHeaderData(8, Qt::Horizontal, QObject::tr("age"));
     return model;
}




QSqlQueryModel * Employe::afficher_id()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select ID from EMPLOYE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
                         return model;
}

bool Employe::ajouter1()
{


    QSqlQuery query;


         query.prepare("INSERT INTO LOGIN(USERNAME,PASSWORD)" "VALUES (:USERNAME,:PASSWORD)");
         query.bindValue(":USERNAME", USERNAME);
         query.bindValue(":PASSWORD", PASSWORD);

         return query.exec();


}





