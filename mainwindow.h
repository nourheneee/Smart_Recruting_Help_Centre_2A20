#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <etudiant.h>
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

private:
    Ui::MainWindow *ui;
    Etudiant E;
};

#endif // MAINWINDOW_H
