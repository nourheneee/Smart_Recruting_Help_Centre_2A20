#ifndef RECLAMATION_H
#define RECLAMATION_H
#include <QString>
#include <QSqlQueryModel>


class reclamation
{
public:
    reclamation();
    reclamation(int,QString,QString,QString);
    int getnum_reclamation();
    QString getdate();
    QString getposte();
    QString getsujet();
    //seters
    void setnum_reclamation(int);
    void setdate(QString);
    void setposte(QString);
    void setsujet(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int num_reclamation,QString date,QString poste,QString sujet);
private:
    int num_reclamation;
    QString date;
    QString poste;
    QString sujet;
};

#endif // RECLAMATION_H
