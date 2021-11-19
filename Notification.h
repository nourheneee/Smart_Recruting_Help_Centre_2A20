#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajouter();
    void notification_supprimer();
    void notification_modifier();
    void notification_chercherid();
    void notification_cherchernom();
 //   void notification_recherche();
};
#endif // NOTIFICATION_H
