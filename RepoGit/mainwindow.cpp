#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//----------------------------------------------------------------\\
    //Préparation de la base de données
    ui->statusbar->addWidget(ui->labelStatusBar);
    maDataBase = QSqlDatabase::addDatabase("QSQLITE");
    maDataBase.setDatabaseName("C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/bdd/basetest.db");

    //Affichage de la base de données
    maDataBase.open();
    this->model = new QSqlQueryModel();

    if(maDataBase.open()){
        ui->labelStatusBar->setText("Connexion à la base de données OK...!");
    }else{
        ui->labelStatusBar->setText("Impossible de se connecter à la base de données...");
    }
    model->setQuery("SELECT * FROM joueurs");

    //Mise en forme des données
    ui->tableView->setModel(model);

//----------------------------------------------------------------\\
    //Séléction du joueur par query sql
    QSqlQuery query;
    query.prepare("SELECT DISTINCT prenom FROM joueurs");
    query.exec();

    if(query.exec()){
        while(query.next()){
            ui->comboBox_2->addItem(query.value(0).toString());
        }
    }
    else{
        QMessageBox::critical(this,"Erreur",query.lastError().text());
    }
//----------------------------------------------------------------\\


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_2_currentIndexChanged()
{
    //Affichage du tag image correspondant au joueur selectionner

    nomJoueur = ui->comboBox_2->currentText();  //Récupération du nom du joueur séléctionner
    query2 = new QSqlQuery;
    query2->exec("SELECT DISTINCT imagetir FROM joueurs WHERE prenom='" + nomJoueur + "'"); //Query SQL pour les tags d'images relatives aux tirs

    if(query2->isActive() && query2->isSelect()){
       while(query2->next()){
            imagesRecues = imagesRecues + query2->value(0).toString() + "\n";   //Chaque nouveau tag est stockée dans un QString
            }
        ui->textEdit->setText(imagesRecues);    //Affichage du/des tag(s) correspondants au joueur
        qDebug() << nomJoueur;
    }
    else{
        QMessageBox::critical(this,"Erreur",query2->lastError().text());
    }
    imagesRecues = "";  //Vidage du plainText à chaque changement de selection
}
