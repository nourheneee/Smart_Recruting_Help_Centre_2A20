#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include"employe.h"
#include<QMessageBox>


login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
 Employe  E;
  E.USERNAME=ui->username->text();
  E.PASSWORD=ui->password->text();

  E.ajouter1();

  QMessageBox::information(this,"ACCOUNT","creation successful");
  //mainwindow = new MainWindow(this);
    // mainwindow->show();
}




void login::on_pushButton_2_clicked()
{
    Employe E;
    E.USERNAME=ui->username->text();
    E.PASSWORD=ui->password->text();
 if(E.USERNAME == "chiraz" && E.PASSWORD =="chiraz" )

{
QMessageBox::information(this,"username","username et password correct");
mainwindow = new MainWindow(this);
   mainwindow->show();
}
else

{
     QMessageBox::warning(this,"username","username ou password incorrect");
}
}




/*QSqlQuery qry;

if(qry.exec("select * from LOGIN where username='"+USERNAME +"' and password='"+PASSWORD+"'"))
{
int count=0;
while(qry.next())
{
count++;
}
if(count==1)
ui->label->setText("username and password is correct");
if(count>1)
ui->label->setText("Duplicate username and password ");
if(count<1)
ui->label->setText("username and password is not correct");
}*/



    //mainwindow = new MainWindow(this);
   // mainwindow->show();

   /* if(E.USERNAME == "test" && E.PASSWORD =="test" )

    {

        QMessageBox::information(this,"username","username et password correct");
        mainwindow = new MainWindow(this);
           mainwindow->show();
    }
        else

        {
             QMessageBox::warning(this,"username","username ou password incorrect");
        }*/



/*void login::on_pushButton_2_clicked()
{
    Employe E;
    E.USERNAME=ui->username->text();
    E.PASSWORD=ui->password->text();

    QSqlQuery qry;

    if(qry.exec("select * from LOGIN where username='"+E.USERNAME +"' and password='"+E.PASSWORD+"'"))
    {
    int count=0;
    while(qry.next())
    {
    count++;
    }
    if(count==1)
    ui->label->setText("username and password is correct");
    mainwindow = new MainWindow(this);
       mainwindow->show();



    if(count>1)
    ui->label->setText("Duplicate username and password ");
    if(count<1)
    ui->label->setText("username and password is not correct");
    }
}*/