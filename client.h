#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>

#include <QDebug>


class client
{
public:
public:
    client();
    client(int,QString,QString,int,QString);
    int get_id();
    void Set_nom(QString val) ;
    QString get_nom();
    void Set_prenom(QString val) ;
    QString get_prenom();
    void Set_region(QString val) ;
    QString get_region();
    void Set_age(int val) ;
    int get_age();
    QSqlQuery rechercher_id(int id);
    bool ajouter();
    bool  modifier_client(int,QString,QString,int,QString);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
private:
    int id;
    QString nom;
    QString prenom;
    QString region;
    int age;
};

#endif // CLIENT_H
