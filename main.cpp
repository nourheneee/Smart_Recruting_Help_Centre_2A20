#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <connexion.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
     bool test=c.ouvrirConnexion();
    MainWindow w;

    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}

