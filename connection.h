//#ifndef CONNECTION_H
//#define CONNECTION_H


//class connection
//{
//public:
  //  connection();
//};

//#endif // CONNECTION_H


#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection();

    bool createconnect();
    bool ouvrirConnexion();
    void fermerConnection();
};

#endif // CONNECTION_H
