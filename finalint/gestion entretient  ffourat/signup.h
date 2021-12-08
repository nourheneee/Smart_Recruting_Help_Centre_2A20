#ifndef SIGNUP_H
#define SIGNUP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class signup
{

    QString username, password,name,poste;

public:

    signup();
    signup(QString,QString,QString);

    QString GetUsername();
    QString GetPassword();
    QString GetName();
    QString GetPoste();

    void SetUsername(QString U){username=U;}
    void SetPassword(QString P){password=P;}
    void SetName(QString N){name=N;}
    void SetPoste(QString P){poste=P;}

        bool ajouter();

};
#endif // SIGNUP_H
