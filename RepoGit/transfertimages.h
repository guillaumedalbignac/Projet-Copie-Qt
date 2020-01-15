#ifndef TRANSFERTIMAGES_H
#define TRANSFERTIMAGES_H

#include <QObject>
#include <QProcess>

class TransfertImages : public QObject
{
    Q_OBJECT
public:
    TransfertImages();
    void effectuerTransfert(QString cheminDonne);

signals:

private:
    //Variable utiliser pour le transfert des images
     QString cheminFinal = "C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/copiesImages";
     QString cheminComplet;
     QStringList commandePowershell;
     QString cheminAccesPowershell = "C:/Windows/system32/WindowsPowerShell/v1.0/powershell.exe";
     QProcess *processTransfert;
};

#endif // TRANSFERTIMAGES_H
