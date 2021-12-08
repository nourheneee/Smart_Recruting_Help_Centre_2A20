#include "signup.h"

signup::signup()
{
    username="";
    password="";
    name="";
    poste="";
}

signup::signup(QString username,QString password, QString name)
{
    this->username=username;
    this->password=password;
    this->name=name;

}

QString signup::GetUsername(){return username;}
QString signup::GetPassword(){return password;}
QString signup::GetName(){return name;}
QString signup::GetPoste(){return poste;}

bool signup::ajouter()
{
QSqlQuery query;
 query.prepare("INSERT INTO SIGNUP (nom, PASSWORD, NAME)"
        "VALUES(:username, :password, :name)");
 query.bindValue(":username",username);
 query.bindValue(":password",password);
 query.bindValue(":name",name);
return query.exec();
}
