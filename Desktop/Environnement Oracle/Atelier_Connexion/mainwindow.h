#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "entretient.h"
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

    void on_tab_entretient_activated(const QModelIndex &index);

    void on_pb_sup_clicked();

private:
    Ui::MainWindow *ui;
    entretient E ;
};

#endif // MAINWINDOW_H
