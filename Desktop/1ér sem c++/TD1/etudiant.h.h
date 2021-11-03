#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <iostream>
#include<string>
using namespace std;
class Etudiant{
    public:
char nom[20];
char prenom[20];
int tab_notes[10]={0};

void saisir();
void afficher ();
float moyenne();
bool admis();
int ecae_quo(Etudiant E);};
#endif // ETUDIANT_H_INCLUDED
