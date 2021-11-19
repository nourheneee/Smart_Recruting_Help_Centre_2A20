#include "login_bd.h"

login_bd::login_bd()
{

}


bool login_bd::createconnect1()
{bool test=false;
 QSqlDatabase db1 = QSqlDatabase::addDatabase("QODBC");
db1.setDatabaseName("login_bd");//inserer le nom de la source de données ODBC
db1.setUserName("login");//inserer nom de l'utilisateur
db1.setPassword("login");//inserer mot de passe de cet utilisateur

if (db1.open())

 test=true;

return test;

}
bool login_bd::ouvrirConnexion1(){
    if (db1.open())
        return true ;
    else
        return false;
}

void login_bd::fermerConnexion1(){db1.close();}
