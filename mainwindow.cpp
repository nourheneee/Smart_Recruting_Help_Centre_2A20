#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QString>
#include <QObject>
#include <QComboBox>
#include<QMessageBox>
#include <QTextDocument>
#include <QTextStream>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QPrinter>
#include <QSharedPointer>
#include <QDebug>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QString>
#include<QtCharts>
#include<QLineSeries>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mOptionsMenu = new QMenu("options", this);
    mAllumerAction = new QAction("allumer", this);
    mEteindreAction = new QAction("eteindre", this);
    mCapturerAction = new QAction("capturer", this);

    mOptionsMenu->addActions({ mAllumerAction, mEteindreAction, mCapturerAction});
    ui->pb_options->setMenu(mOptionsMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mAllumerAction, &QAction::triggered, [&]() {
        mCamera->start();
    });

    connect(mEteindreAction, &QAction::triggered, [&]() {
        mCamera->stop();
    });

    connect(mCapturerAction, &QAction::triggered, [&]() {
        auto filename = QFileDialog::getSaveFileName(this, "capture", "/", "image (*.jpg;*.jpeg)");
        if (filename.isEmpty())
        {
            return;
        }

        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_client_clicked()
{
    {
        client tmpclient;
        int id= ui->lineEdit_ajout_id->text().toInt();
        QString nom=ui->lineEdit_ajout_nom->text();
        QString prenom=ui->lineEdit_ajout_prenom->text();
        int phone=ui->lineEdit_ajout_phone->text().toInt();
        QString mail= ui->lineEdit_ajout_mail->text();

        client cl(id,nom,prenom,phone,mail);

    bool test=cl.ajouter();
        if( test)
        {
            ui->tableView_client->setModel(tmpclient.afficher());//refresh
           ui->lineEdit_ajout_id->clear();
           ui->lineEdit_ajout_nom->clear();
           ui->lineEdit_ajout_prenom->clear();
           ui->lineEdit_ajout_phone->clear();
            ui->lineEdit_ajout_mail->clear();
            QMessageBox ::information(nullptr,QObject::tr("ajouter un client"),
                                              QObject::tr("client ajouté.\n"
                                                  "click ok to exit"),QMessageBox::Ok);
        }

        else
        {
            QMessageBox ::critical(nullptr,QObject::tr("ajouter un client"),
                                              QObject::tr("Erreur.\n"
                                                  "click cancel to exit"),QMessageBox::Cancel);
        }


    }
}



void MainWindow::on_supp_client_clicked()
{
    client tmpclient;
    int id =ui->lineEdit_supp_client->text().toInt();
    QMessageBox msgbox;
    msgbox.setWindowTitle("supprimer");
    msgbox.setText("voulez_vous supprimer ce client?");
    msgbox.setStandardButtons(QMessageBox ::Yes);
    msgbox.addButton(QMessageBox::No);
    if(msgbox.exec()==QMessageBox::Yes)

    {
        bool test=tmpclient.supprimer(id);

    if(test)
    {
        ui->tableView_client->setModel(tmpclient.afficher());
        ui->lineEdit_supp_client->clear();
        QMessageBox ::information(nullptr,QObject::tr("supprimer un client"),
                                          QObject::tr("client supprimé.\n"
                                              "click ok to exit"),QMessageBox::Ok);

    }
    else
    {
        QMessageBox ::critical(nullptr,QObject::tr("supprimer un client"),
                                          QObject::tr("Erreur.\n"
                                              "click cancel to exit"),QMessageBox::Cancel);
    }
    }
    else
    {
        QMessageBox ::critical(nullptr,QObject::tr("ERROR"),
                                          QObject::tr("ID INTROUVABLE.\n"
                                              "click cancel to exit"),QMessageBox::Cancel);
    }
}
void MainWindow::on_modifier_client_clicked()
{
    client tmpclient;
    QString nom = ui->lineEdit_modif_nom->text();
         QString prenom = ui->lineEdit_modif_prenom->text();
         int phone =ui->lineEdit_modif_phone->text().toInt();
         QString mail=ui->lineEdit_modif_mail->text();
         int id =ui->lineEdit_modif_id->text().toInt();

         bool test=tmpclient.modifier_client(id,nom,prenom,phone,mail);
         if(test)
         { ui->tableView_client->setModel(tmpclient.afficher());
                 ui->lineEdit_modif_id->clear();
                 ui->lineEdit_modif_nom->clear();
                 ui->lineEdit_modif_prenom->clear();
                 ui->lineEdit_modif_phone->clear();
                 ui->lineEdit_modif_mail->clear();
             QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                               QObject::tr("client modifié.\n"
                                                   "click ok to exit"),QMessageBox::Ok);

         }
         else
         {
             QMessageBox ::critical(nullptr,QObject::tr("supprimer un client"),
                                               QObject::tr("Erreur.\n"
                                                   "click cancel to exit"),QMessageBox::Cancel);
         }
}

void MainWindow::on_transferer_clicked()
{
    int row=ui->tableView_client->selectionModel()->currentIndex().row();
       QString id=ui->tableView_client->model()->index(row,0).data().toString();
       QString nom=ui->tableView_client->model()->index(row,1).data().toString();
       QString prenom=ui->tableView_client->model()->index(row,2).data().toString();
       QString phone=ui->tableView_client->model()->index(row,4).data().toString();
       QString mail=ui->tableView_client->model()->index(row,3).data().toString();
       if(row==-1)
       {
           QMessageBox ::information(nullptr,QObject::tr("modifier un client"),
                                             QObject::tr("aucune selection.\n"
                                                 "click ok to exit"),QMessageBox::Ok);
       }
       else
       {
           ui->lineEdit_modif_id->setText(id);
           ui->lineEdit_modif_nom->setText(nom);
           ui->lineEdit_modif_prenom->setText(prenom);
           ui->lineEdit_modif_phone->setText(phone);
           ui->lineEdit_modif_mail->setText(mail);
       }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView_client->setModel(cl.rechercher(arg1));
}

void MainWindow::on_pb_PDF_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView_client->model()->rowCount();
    const int columnCount = ui->tableView_client->model()->columnCount();
    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste RH </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)

        if (!ui->tableView_client->isColumnHidden(column))

            out << QString("<th>%1</th>").arg(ui->tableView_client->model()->headerData(column, Qt::Horizontal).toString());

    out << "</tr></thead>\n";
    // data table

    for (int row = 0; row < rowCount; row++)
    {
        out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
        for (int column = 0; column < columnCount; column++)
        {
            if (!ui->tableView_client->isColumnHidden(column))
            {
                QString data = ui->tableView_client->model()->data(ui->tableView_client->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"

        "</body>\n"

        "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");

    if (QFileInfo(fileName).suffix().isEmpty())

    {

        fileName.append(".pdf");

    }

     QPrinter printer (QPrinter::PrinterResolution);
     printer.setOutputFormat(QPrinter::PdfFormat);
     printer.setPaperSize(QPrinter::A4);
     printer.setOutputFileName(fileName);
     QTextDocument doc;
     doc.setHtml(strStream);
     doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
     doc.print(&printer);
}

void MainWindow::on_pb_trier_clicked()
{
    client cl;
    QString crit=ui->comboBoxTri->currentText();
    if(crit=="id")
    {
        ui->tableView_client->setModel(cl.tri_id());
    }
    else if(crit=="prenom")
    {
        ui->tableView_client->setModel(cl.tri_prenom());
    }
    else
    {
        ui->tableView_client->setModel(cl.tri_nom());
    }
}

void MainWindow::on_radioButton_clicked()
{
    QString link="https://www.facebook.com/";
    QDesktopServices::openUrl(link);
}
