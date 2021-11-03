#ifndef BUREAU_H
#define BUREAU_H
#include<string>

using namespace  std;

#endif // BUREAU_H
//
class  bureau{
    string code_de_bureau;
    int numero_responsable;
    string ville;
    int cordonnes_map;
    int capaciter_bureau;
    int nombre_actuelle;
    int nombre_doffre;
    int nombre_demplois;
    int jour;
    int mois;
    int annee;

public:
    void ajouter_bureau();
    void consulter_bureau();
    void modifier_bureau();
    void supprimer_bureau();
};

