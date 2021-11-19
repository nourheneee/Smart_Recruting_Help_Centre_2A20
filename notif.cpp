#include "notif.h"
notif::notif()
{

}
void notif::notif_system()
{
    QSystemTrayIcon * notifyIcon = new QSystemTrayIcon();
    notifyIcon->show();
    notifyIcon->showMessage("gestion des societe","societe ajoutee",QSystemTrayIcon::Information,15000);
}
