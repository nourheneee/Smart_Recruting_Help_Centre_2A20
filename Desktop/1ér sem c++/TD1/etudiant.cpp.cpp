#include"etudiant.h"

void Etudiant::saisir()
{
    cout<<"donner le nom de l'etudiant"<< endl;
    cin>>nom;
    cout<<"donner le prenom de l'etudiant "<<endl;
    cin >>prenom;
    for(int i=0; i<10; i++)
    {
        cout<<"donner les notes"<<endl;
        cin>>tab_notes[i];

    }
}

void Etudiant::afficher()
{
    cout<<" le nom de l'etudiant est "<<nom<<endl;
    cout<<"le prenom de l'etudiant est "<<prenom<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<"le tableau des notes est"<<tab_notes[i]<<endl;
    }

}

float Etudiant::moyenne()
{
    float moy;
    for(int i=0; i<10; i++)
    {

        moy=moy+tab_notes[i];
    }
    moy=moy/10;
    return moy;
}

bool Etudiant::admis()
{
    float moy;
    bool res;
    if(moy<10)
        res=false;
    else
        res=true;

    return res;
}

int Etudiant::ecae_quo(Etudiant E)
{
float moy;
if(moy<E.moy)
}
