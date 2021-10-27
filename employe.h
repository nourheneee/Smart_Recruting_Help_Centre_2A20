#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
class Employe
{
public:
    Employe();
    Employe(int,int,int,int,int,QString,QString,QString,QString);
    int getid ();
    int getage ();
    int getsalaire();
    int getdate_debut_travail ();
    int getdate_fin_travail ();
    QString getnom ();
    QString getprenom ();
    QString getsexe ();
    QString getposte ();
    void setid (int);
    void setage (int);
    void setsalaire(int);
    void setdate_debut_travail (int);
    void setdate_fin_travail (int);
    void setnom (QString);
    void setprenom (QString);
    void setsexe (QString);
    void setposte (QString);
    bool ajouter();

    private:
        int id, age,salaire, date_debut_travail,date_fin_travail;
    QString nom, prenom, sexe, poste;
};

#endif // EMPLOYE_H
