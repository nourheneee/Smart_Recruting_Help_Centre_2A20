#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQueryModel>
#include<QDate>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>

class reclamation
{
public:
    reclamation();
    reclamation(int,QDate,QString,QString,QString);
    int getnum_reclamation();
    QDate getdate();
    QString getposte();
    QString getsujet();
   QString gettype();
    //seters
    void setnum_reclamation(int);
    void setdate(QDate);
    void setposte(QString);
    void setsujet(QString);
    void settype(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);

    QSqlQueryModel *Tri_num_reclamation();
    QSqlQueryModel *Tri_poste();
    QSqlQueryModel *tri_sujet_reclamation();
    QSqlQueryModel *recherche(QString);
    QChartView *piechart();
    int count(int val, QString att );


private:
    int num_reclamation;
    QDate date;
    QString poste;
    QString sujet;
  QString type;
};

#endif // RECLAMATION_H
