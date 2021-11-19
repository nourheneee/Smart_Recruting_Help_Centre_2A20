#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDialog>
#include <QTabWidget>
#include <QTimer>
#include <QTime>
#include <societe.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();

    //void on_pb_modifier_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_2_clicked();

    void mailSent(QString);

  //  void browse();



    //void on_onBrowsebtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pb_tri_nom_clicked();

    void on_pushButton_5_clicked();

    void on_pb_tri_domaine_clicked();

    void on_pushButton_6_clicked();

    void on_pb_rech1_clicked();

    void on_comboRech_activated(const QString &arg1);

    void on_rechPB_clicked();
        void on_pushButton_statistique_clicked();

        void on_statisique_clicked();
            void on_regarder_clicked();
            void on_lineEdit_textChanged(const QString &arg1);


            void on_pushButton_4_clicked();

            void on_rechnom_clicked();

            void on_lineEdit_2_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;
    Societe C;
};

#endif // MAINWINDOW_H
