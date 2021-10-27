#include "employe.h"
//Test Tutorial git
Employe::Employe()
{
id=0; age=0; date_debut_travail=0; date_fin_travail=0;
nom=""; prenom=""; sexe=""; poste="";

}
Employe::Employe(int id ,int age ,int salaire,int date_debut_travail,int date_fin_travail, QString nom, QString prenom , QString sexe, QString poste)
{this->id=id; this->age=age; this->date_debut_travail=date_debut_travail; this->date_fin_travail=date_fin_travail; this->nom=nom ;this->prenom=prenom; this->sexe=sexe; this->poste=poste; }
int Employe::getid (){return id  ;}
int Employe::getage (){return age ;}
int Employe::getsalaire (){return salaire ;}
int Employe::getdate_debut_travail (){return date_debut_travail ;}
int Employe::getdate_fin_travail (){return date_fin_travail ;}
QString Employe::getnom (){return nom ;}
QString Employe::getprenom (){return prenom ;}
QString Employe::getsexe (){return sexe ;}
QString Employe::getposte (){return poste ;}
void Employe::setid (int id){this->id=id;}
void Employe::setage (int age){this->age=age;}
void Employe::setsalaire (int salaire){this->salaire=salaire;}
void Employe::setdate_debut_travail (int date_debut_travail){this->date_debut_travail=date_debut_travail;}
void Employe::setdate_fin_travail (int date_fin_travail ){this->date_fin_travail=date_fin_travail;}
void Employe::setnom (QString nom){this->nom=nom;}
void Employe::setprenom (QString prenom){this->prenom=prenom;}
void Employe::setsexe (QString sexe){this->sexe=sexe;}
void Employe::setposte (QString poste){this->poste=poste;}
{bool test=false;


return test;
}
