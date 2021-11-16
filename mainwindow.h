#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_ajouter_client_clicked();

    void on_supp_client_clicked();

    void on_modifier_client_clicked();

    void on_transferer_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
