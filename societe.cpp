#include "societe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


Societe::Societe()
{
id=0;
nom="";
Datee=0;
Domaine="";
Adresse="";
Postes="";
Type="";
NombreP=0;

}
Societe::Societe(int id,QString nom,int Datee,QString Domaine,QString Adresse,QString Postes,QString Type,int NombreP )

{
this->id=id;this->nom=nom; this->Datee=Datee;this->Domaine=Domaine;this->Adresse=Adresse;this->Postes=Postes;this->Type=Type;this->NombreP=NombreP;
}
int Societe::getid(){return id;}
QString Societe::getnom(){return nom;}
int Societe::getDatee(){return Datee;}
QString Societe::getDomaine(){return Domaine;}
QString Societe::getAdresse(){return Adresse;}
QString Societe::getPostes(){return Postes;}
QString Societe::getType(){return Type;}
int Societe::getNombreP(){return NombreP;}
void Societe::setid(int id){this->id=id;}
void Societe::setnom(QString nom){this->nom=nom;}
void Societe::setDatee(int Datee){this->Datee=Datee;}
void Societe::setDomaine(QString Domaine){this->Domaine=Domaine;}
void Societe::setAdresse(QString Adresse){this->Adresse=Adresse;}
void Societe::setPostes(QString Postes){this->Postes=Postes;}
void Societe::setType(QString Type){this->Type=Type;}
void Societe::setNombreP(int NombreP){this->NombreP=NombreP;}
bool Societe::ajouter()
{



QString id_string=QString::number(id);
QString Datee_string=QString::number(Datee);
QString NombreP_string=QString::number(NombreP);
QSqlQuery query;
query.prepare("INSERT INTO societe (id, nom, Datee, Domaine, Adresse, Postes, Type, NombreP) "
              "VALUES (:id, :nom, :Datee, :Domaine, :Adresse, :Postes, :Type,: NombreP)");
query.bindValue(0, id_string);
query.bindValue(1, nom);
query.bindValue(2, Datee_string);
query.bindValue(3, Domaine);
query.bindValue(4, Adresse);
query.bindValue(5, Postes);
query.bindValue(6, Type);
query.bindValue(7, NombreP_string);

return query.exec();

}
QSqlQueryModel* Societe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM societe");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Domaine"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Postes"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de contrat"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Nombre de postes"));


    return model;}

bool Societe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from societe where id=:id");
    query.bindValue(":id", id);


    return query.exec();
}


bool Societe::modifier(int id, QString nom ,int Datee, QString Domaine, QString Adresse, QString Postes,QString Type,int NombreP)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(Datee);
    QString res2=QString::number(NombreP);
            query.prepare("update SOCIETE set id =:id,nom= :nom,Datee= :Datee,Domaine= :Domaine,Adresse= :Adresse,Postes= :Postes,Type=:Type,NombreP=:NombreP WHERE id=:id");
            query.bindValue(":id",res);
            query.bindValue(":nom",nom);
            query.bindValue(":Datee",res1);
            query.bindValue(":Domaine",Domaine);
            query.bindValue(":Adresse",Adresse);
            query.bindValue(":Postes",Postes);
            query.bindValue(":Type",Type);
            query.bindValue(":NombreP",res2);


            return  query.exec();
}

