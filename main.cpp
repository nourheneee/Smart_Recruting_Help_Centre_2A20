#include "mainwindow.h"
#include "connection.h"
#include <QDebug>
#include <QMessageBox>
#include <QApplication>
#include"QtSql/QSqlDatabase"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Connection C;
    bool test=C.createConnection();
    MainWindow w;
    if(test){
       /* qDebug()<<"connexion reussite";*/
    QMessageBox ::information(nullptr,QObject::tr("Data is open"),
                                      QObject::tr("connexion succesful\n"
                                          "click ok to exit"),QMessageBox::Ok);
    w.show();
    }

    else  {


       // qDebug()<<"connexion echoué";
        QMessageBox ::critical(nullptr,QObject::tr("Data is not open"),
                                          QObject::tr("error connexion\n"
                                              "click cancel to exit"),QMessageBox::Cancel);
        }

    return a.exec();
}
