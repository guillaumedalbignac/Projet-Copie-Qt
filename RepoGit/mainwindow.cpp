#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transfertimages.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Mise en place du timer de détection de la carte SD
    monTimer = new QTimer;

    connect(monTimer, SIGNAL(timeout()), this, SLOT(maFonctionTimer()));    //Connection du timer créer avec la fonction maFonctionTimer()
    monTimer->start(1000);  //Démarrage du timer à 1s
}

MainWindow::~MainWindow()
{
    //Destruction des objets du programme
    delete ui;
    delete obj;
}

void MainWindow::on_pushButton_clicked()
{
   //TODO début process analyse d'images
}

void MainWindow::maFonctionTimer()  //Fonction utilisé en boucle pour détecter la présence d'une carte SD au démarrage du programme
{    
    obj = new TransfertImages;  //Le pointeur devient un nouvelle objet de la class TransfertImages

    if(cheminUtilisateur != "" && obj->detecterCarteSd() == true){
         obj->effectuerTransfert(cheminUtilisateur);    //Appel de la fonction de transfert avec pour argument le chemi d'accès
         qDebug() << "Transfert ok...!";
         monTimer->stop();  //Arret du timer suite à un transfert réussie
        }
}

