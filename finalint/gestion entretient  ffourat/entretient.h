#ifndef ENTRETIENT_H
#define ENTRETIENT_H


#include <QString>
#include <QSqlQueryModel>
#include <QTableView>


class entretient
{
public:
    entretient();
    entretient(int,QString,QString,QString,int,int,QString,QString);
    QString getNOM();
    QString getPRENOM();
    QString getSEXE();
    QString getADRESS();
    QString getEXPERIENCE();
    int getCIN();
    int getAGE();
    int getDATE_NAISSANCE();
    QSqlQueryModel*afficherCIN();


    void setNOM(QString);
    void setPRENOM(QString);
    void setSEXE(QString);
    void setADRESS(QString);
    void setEXPERIENCE(QString);
    void setCIN(int);
    void setAGE(int);
    void setDATE_NAISSANCE(int);

    bool update();
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel*  chercher(QString );
    bool supprimer(int);
    QSqlQueryModel* trier_nom();
    QSqlQueryModel* trier_age();
    QSqlQueryModel* trier_prenom();
    void notification(QString);
    QString read(QString File);
    void write(QString time, QString txt, QString File);
    QString time();
    void clearTable(QTableView * table);
    void rechercher(QTableView *table, QString x);



private:
    int CIN,AGE,DATE_NAISSANCE;
    QString  NOM,PRENOM,SEXE,ADRESS,EXPERIENCE;
};


#endif // ENTRETIENT_H
