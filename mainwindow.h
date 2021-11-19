#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_client_clicked();

    void on_supp_client_clicked();

    void on_modifier_client_clicked();

    void on_transferer_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pb_PDF_clicked();

    void on_pb_trier_clicked();


    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    client cl;
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
