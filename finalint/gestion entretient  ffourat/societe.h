#ifndef SOCIETE_H
#define SOCIETE_H

#include <QString>
#include <QSqlQueryModel>
class Societe
{
public:
    Societe();
    Societe(int,QString,int,QString,QString,QString,QString,int);
    int getid();
    QString getnom();
    int getDatee();
    QString getDomaine();
    QString getAdresse();
    QString getPostes();
    QString getType();
    int getNombreP();

    void setid(int);
    void setnom(QString);
    void setDatee(int);
    void setDomaine(QString);
    void setAdresse(QString);
    void setPostes(QString);
    void setType(QString);
    void setNombreP(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int id, QString nom ,int Datee, QString Domaine, QString Adresse, QString Postes,QString Type,int NombreP);
    QSqlQueryModel *trideccroissant();
       QSqlQueryModel *tricroissant();
       QSqlQueryModel *trinom();
       QSqlQueryModel *tridoamine();
       QSqlQueryModel *chercherid(QString);
       QSqlQueryModel *cherchernom(QString);
         QSqlQueryModel *cherchernombrep(QString);

private:
    int id,Datee,NombreP;
    QString nom, Domaine,Adresse,Type,Postes;

};

#endif // SOCIETE_H
