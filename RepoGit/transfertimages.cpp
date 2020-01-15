#include "transfertimages.h"
#include <QFileDialog>
#include <QDebug>

TransfertImages::TransfertImages() : QObject()
{

}

void TransfertImages::effectuerTransfert(QString cheminDonne){

        cheminComplet = "Copy-Item -Path " + cheminDonne + " -Destination " + cheminFinal + " -Recurse";
        commandePowershell << cheminComplet;
        qDebug() << commandePowershell;
        processTransfert = new QProcess();
        processTransfert->setWorkingDirectory("C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/copiesImages");
        processTransfert->start(cheminAccesPowershell, commandePowershell);
        processTransfert->waitForFinished(-1);
        processTransfert->exitCode();
        commandePowershell.clear();
}

