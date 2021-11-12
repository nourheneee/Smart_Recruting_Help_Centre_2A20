#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    Ui::MainWindow *ui;
    Societe C;
};

#endif // MAINWINDOW_H
