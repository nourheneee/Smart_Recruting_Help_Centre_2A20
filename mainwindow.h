#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include<QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();



    void on_pb_modifier_clicked();

    void on_pb_image_clicked();

    void on_pb_recherche_id_clicked();

    void on_pb_recherche_nom_clicked();

    void on_pb_recherche_poste_clicked();

    void on_pb_trier_sexe_clicked();

    void on_pb_trier_salaire_clicked();

    void on_pb_trirer_poste_clicked();

    void on_pb_age_stat_clicked();



    void on_pb_absences_stat_clicked();

    void on_pb_heures_de_travail_stat_clicked();

    void on_le_id_r_textChanged(const QString &arg1);

    void on_le_nom_r_textChanged(const QString &arg1);

    void on_le_poste_r_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Employe E;
};
#endif // MAINWINDOW_H
