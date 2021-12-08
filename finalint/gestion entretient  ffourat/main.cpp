#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDesktopServices>
#include<QUrl>
#include<QTranslator>
#include<QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    QTranslator guiTranslator;
    QStringList languages;

    languages<< "English"  << "Arabic" <<"french" ;
    QString lang = QInputDialog::getItem(NULL,"select language","language",languages);
           if(lang == "English")
           {
              t.load(":/english.qm");

             // guiTranslator.load("C:/Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qtbase_en.qm");
           }
           else if(lang == "Arabic")
           {

               t.load(":/Arabic.qm");
         //  guiTranslator.load("C:/Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qtbase_ar.qm");
           }
           if(lang != "french")
           {
               a.installTranslator(&t);
             a.installTranslator(&guiTranslator);

           }

    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
