#include "connection.h"
#include"QtSql/QSqlDatabase"

Connection::Connection()
{

}
bool Connection :: createConnection()
{
bool test=false;
 QSqlDatabase db = QSqlDatabase :: addDatabase("QODBC");
 db.setDatabaseName("test-bd");
 db.setUserName("belhassen");
 db.setPassword("belhassen");
if(db.open())
{ test=true;}
return test;
}
void Connection::fermerConnection()
{
    db.close();
}
