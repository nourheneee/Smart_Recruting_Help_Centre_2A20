#ifndef ENTRETIENT_H
#define ENTRETIENT_H


#include <QString>
#include <QSqlQueryModel>
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


    void setNOM(QString);
    void setPRENOM(QString);
    void setSEXE(QString);
    void setADRESS(QString);
    void setEXPERIENCE(QString);
    void setCIN(int);
    void setAGE(int);
    void setDATE_NAISSANCE(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    int CIN,AGE,DATE_NAISSANCE;
    QString  NOM,PRENOM,SEXE,ADRESS,EXPERIENCE;
};

#endif // ENTRETIENT_H
