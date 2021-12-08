#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtMultimedia/QSound>

#include <QMainWindow>
#include "entretient.h"
#include "arduino.h"
#include "reclamation.h"
namespace Ui {
class MainWindow;
}
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

   // void on_tab_entretient_activated(const QModelIndex &index);

    void on_pb_sup_clicked();

   // void on_tabWidget_currentChanged(int index);

    void on_pb_ajouter_2_clicked();

   // void on_pushButton_clicked();

    void on_recherche_clicked();

    void on_trier_nom_clicked();

    void on_trier_age_clicked();

    void on_trier_prenom_clicked();

    void on_envoi_bur_clicked();

    void on_mess_bur_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_le_nom_rech_textChanged(const QString &arg1);

    void update_temperature();

    void on_pushButton_5_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_image_clicked();

    void on_le_id_r_textChanged(const QString &arg1);

    void on_le_nom_r_textChanged(const QString &arg1);

    void on_le_poste_r_textChanged(const QString &arg1);

    void on_pb_trier_sexe_clicked();

    void on_pb_trier_salaire_clicked();

    void on_pb_trirer_poste_clicked();

    void on_pb_age_stat_clicked();

    void on_pb_absences_stat_clicked();

    void on_pb_heures_de_travail_stat_clicked();

    void on_entr_clicked();

    void on_emp_clicked();

    void on_pushButton_7_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_entrer_clicked();

    void on_pb_tri_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_pb_excel_2_clicked();

    void on_pushButton_8_clicked();

    void on_pb_ajouter_5_clicked();

    void on_pushButton_12_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pb_modifier_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pb_tri_nom_clicked();

    void on_pb_tri_domaine_clicked();

    void on_statisique_clicked();

    void on_leRech_textChanged(const QString &arg1);

    void on_rechPB_clicked();

    void on_pushButton_11_clicked();

    void on_regarder_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_31_clicked();

    void on_logiin_clicked();

    void on_pushButton_6_clicked();

    void on_ajouter_client_2_clicked();

    void on_supp_client_2_clicked();

    void on_radioButton_clicked();

    void on_pb_PDF_clicked();

    void on_pb_trier_clicked();

    void on_modifier_client_2_clicked();

    void on_transferer_2_clicked();

    void on_lineEdit_777_textChanged(const QString &arg1);

    void on_pushButton_32_clicked();

private:
    Ui::MainWindow *ui;
    entretient E ;
    QString File = "C:\\Users\\foura\\Desktop\\Environnement_Oracle\\Atelier_Connexion\\Historique.txt";
     QSound *son ;
     QByteArray data; // variable contenant les données reçues
     arduino A;
     QCamera *mCamera;
     QCameraViewfinder *mCameraViewfinder;
     QCameraImageCapture *mCameraImageCapture;
     QVBoxLayout *mLayout;
     QMenu *mOptionsMenu;
     QAction *mAllumerAction;
     QAction *mEteindreAction;
     QAction *mCapturerAction;
};

#endif // MAINWINDOW_H
