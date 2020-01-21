#include "transfertimages.h"
#include <QFileDialog>
#include <QDebug>
#include <QStorageInfo>
#include <QMessageBox>

TransfertImages::TransfertImages() : QObject()
{

}

void TransfertImages::effectuerTransfert(QString cheminDonne)   //Fonction permettant de réaliser le transfert via des commandes Powershell
{
        cheminComplet = "Copy-Item -Path " + cheminDonne + " -Destination " + cheminFinal + " -Recurse";
        commandePowershell << cheminComplet;    //Création et stockage de la future commande Powershell de copie des fichiers
        //qDebug() << commandePowershell;
        processTransfert = new QProcess();
        processTransfert->setWorkingDirectory("C:/Users/Default/Desktop");  //On définie l'emplacement de travail pour Powershell
        processTransfert->start(cheminAccesPowershell, commandePowershell); //On démarre le transfert
        processTransfert->waitForFinished(-1);
        processTransfert->exitCode();
        commandePowershell.clear(); //Une fois terminée on vide la avriable contenant la commande Powershell
        //qDebug() << "Transfert terminé...!";
        QMessageBox::information(qobject_cast<QWidget *> (parent()),"","Transfert terminée...!");
}

bool TransfertImages::detecterCarteSd() //Fonction permettant la détection d'insertion d'une carte SD
{
    QString infoDisque;
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
            infoDisque = storage.displayName(); //On récupère pour chaque disque son nom et on le stock dans une variable QString
            //qDebug() << infoDisque;
     }
    if(infoDisque == "E:/"){    //Si le nom correspond à celui de la carte SD utilisé, la fonction renvoie true (le reste du temps false)
        qDebug() << "carte sd detecte !";
        return true;
    }else{
        qDebug() << "pas de carte sd detecte !";
        return false;
    }
}


