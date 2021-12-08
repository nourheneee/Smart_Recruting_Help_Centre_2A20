#include "reclamation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include "connection.h"

reclamation::reclamation()
{
num_reclamation=0; poste=""; sujet=""; type="";
}
reclamation::reclamation(int num_reclamation,QDate date,QString poste,QString sujet,QString type)
{this->num_reclamation=num_reclamation;this->date=date; this->poste=poste; this->sujet=sujet; this->type=type;}
int reclamation::getnum_reclamation(){return num_reclamation;}
QDate reclamation::getdate(){return date;}
QString reclamation::getposte(){return poste;}
QString reclamation::getsujet(){return sujet;}
QString reclamation::gettype(){return type;}
void reclamation::setnum_reclamation(int num_reclamation){this->num_reclamation=num_reclamation;}
void reclamation::setdate(QDate date){this->date=date;}
void reclamation::setposte(QString poste){this->poste=poste;}
void reclamation::setsujet(QString sujet){this->sujet=sujet;}
void reclamation::settype(QString type){this->type=type;}
bool reclamation::ajouter()
{
QSqlQuery query;
    QString num_reclamation_string=QString::number(num_reclamation );

query.prepare("INSERT INTO reclamation (num_reclamation,date_reclamation,poste,sujet_reclamation,type)"

  "VALUES (:num_reclamation,:date_reclamation, :poste, :sujet_reclamation, :type)");
     query.bindValue(0,num_reclamation_string);
     query.bindValue(1,date);
     query.bindValue(2,poste);
     query.bindValue(3, sujet);
    query.bindValue(4, type);

          return query.exec();
}
bool reclamation::supprimer(int num_reclamation)
{
    QSqlQuery query;
         query.prepare("Delete from reclamation where num_reclamation=:num_reclamation");
         query.bindValue(0,num_reclamation);

         return query.exec();
}
QSqlQueryModel* reclamation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("SELECT* FROM reclamation");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num_reclamation"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_reclamation"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Sujet_reclamation"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));


return model;
}
bool reclamation::modifier(int num_reclamation)

{
    Connection c;
    c.createconnect();
    QString num_reclamation_string=QString::number(num_reclamation);
    QSqlQuery query;
       query.prepare("update reclamation set date_reclamation=:date,poste=:poste,sujet_reclamation=:sujet,type=:type where num_reclamation=:num_reclamation");
       query.bindValue(":num_reclamation",num_reclamation_string);
       query.bindValue(":date_reclamation",date);
       query.bindValue(":poste",poste);
       query.bindValue(":sujet_reclamation",sujet);
       query.bindValue(":type",type);
return query.exec();
}


QSqlQueryModel * reclamation::recherche(QString poste)
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("SELECT * FROM reclamation WHERE  poste LIKE '%"+poste+"%'" );

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_reclamation"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

 return model ;
}
QSqlQueryModel *reclamation::Tri_num_reclamation()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  reclamation ORDER BY num_reclamation");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_reclamation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
return model;
 }
QSqlQueryModel *reclamation::Tri_poste()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  reclamation ORDER BY poste");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_reclamation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
return model;
 }
QSqlQueryModel *reclamation::tri_sujet_reclamation()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  reclamation ORDER BY sujet_reclamation");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_reclamation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
return model;
 }
/*QSqlQueryModel *reclamation::tri_sujet_reclamation()
{

     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  reclamation ORDER BY sujet");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_reclamation"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Poste"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sujet_reclamation"));
return model;
 }*/

int reclamation::count(int val, QString att )
{
    QSqlQuery query;
     int row_count = 0;
     query.exec("SELECT * FROM EMPLACEMENT");

     while(query.next())
         if (query.value(val)==att)
            row_count++;
    int size = row_count;
    return size;
}

QChartView * reclamation::piechart()
{
    int ap = count(3,"Vide");
    int ap2 = count(3,"Occupe");

    QPieSeries *series = new QPieSeries();
    series->append("Vide",ap);
    series->append("Occupe", ap2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Charte graphique d'etat des emplacements");
    chart->createDefaultAxes();

    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->resize(400,400);
    chartview->scale(1.2,1.2);
    return chartview;

}

