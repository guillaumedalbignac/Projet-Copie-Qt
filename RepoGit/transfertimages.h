#ifndef TRANSFERTIMAGES_H
#define TRANSFERTIMAGES_H

#include <QObject>
#include <QProcess>
#include <QStorageInfo>
#include <QTimer>

class TransfertImages : public QObject
{
    Q_OBJECT
public:
    TransfertImages();
    void effectuerTransfert(QString cheminDonne);
    bool detecterCarteSd();

signals:

private:
    //Variables utiliser pour la fonction de transfert d'images
     QString cheminFinal = "C:/Users/dalbi/Desktop/copie";  //Chemin d'accès où les fichiers seront déplacés
     QString cheminComplet;
     QStringList commandePowershell;
     QString cheminAccesPowershell = "C:/Windows/system32/WindowsPowerShell/v1.0/powershell.exe";
     QProcess *processTransfert;    //Pointeur permettant de démarrer le processus de copie des fichiers
};

#endif // TRANSFERTIMAGES_H
