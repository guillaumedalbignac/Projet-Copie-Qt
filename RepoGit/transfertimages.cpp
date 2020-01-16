#include "transfertimages.h"
#include <QFileDialog>
#include <QDebug>
#include <QStorageInfo>

TransfertImages::TransfertImages() : QObject()
{

}

void TransfertImages::effectuerTransfert(QString cheminDonne)
{
        cheminComplet = "Copy-Item -Path " + cheminDonne + " -Destination " + cheminFinal + " -Recurse";
        commandePowershell << cheminComplet;
        qDebug() << commandePowershell;
        processTransfert = new QProcess();
        processTransfert->setWorkingDirectory("C:/Users/Default/Desktop");
        processTransfert->start(cheminAccesPowershell, commandePowershell);
        processTransfert->waitForFinished(-1);
        processTransfert->exitCode();
        commandePowershell.clear();
}

bool TransfertImages::detecterCarteSd()
{
    QString infoDisque;
    foreach (const QStorageInfo &storage, QStorageInfo::mountedVolumes()) {
            infoDisque = storage.displayName();
            qDebug() << infoDisque;
     }
    if(infoDisque == "E:/"){
        qDebug() << "carte sd detecte !";
        return true;
    }else{
        qDebug() << "pas de carte sd detecte !";
        return false;
    }
}

