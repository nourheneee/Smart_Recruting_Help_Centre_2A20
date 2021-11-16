#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class Connection
{
public:
public:
    Connection();
    bool createConnection();
    void fermerConnection();
private:
    QSqlDatabase db;

};

#endif // CONNECTION_H
