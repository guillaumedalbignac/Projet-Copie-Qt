#ifndef TRANSFERTIMAGES_H
#define TRANSFERTIMAGES_H

#include <QObject>
#include <QProcess>
#include <QStorageInfo>

class TransfertImages : public QObject
{
    Q_OBJECT
public:
    TransfertImages();
    void effectuerTransfert(QString cheminDonne);
    bool detecterCarteSd();

signals:

private:
    //Variable utiliser pour le transfert des images
     QString cheminFinal = "C:/Users/dalbi/Desktop/copie";
     QString cheminComplet;
     QStringList commandePowershell;
     QString cheminAccesPowershell = "C:/Windows/system32/WindowsPowerShell/v1.0/powershell.exe";
     QProcess *processTransfert;
};

#endif // TRANSFERTIMAGES_H
