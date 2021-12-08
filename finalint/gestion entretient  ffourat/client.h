#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QDebug>


class client
{

public:
    client();
    client(int,QString,QString,int,QString);
    int get_id();
    void Set_id(int val);
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
    bool supprimer(int id);
    QSqlQueryModel * afficher();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_prenom();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *rechercher(QString);
    void statistique(QVector<double>* ticks,QVector<QString> *labels);

private:
    int id;
    QString nom;
    QString prenom;
    QString region;
    int age;
};

#endif // CLIENT_H
