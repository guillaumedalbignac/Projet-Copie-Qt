#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Setup combobox du choix des images
    QDir monRepertoire("C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/img");
    foreach(QFileInfo var, monRepertoire.entryInfoList()){
        ui->comboBox->addItem(var.absoluteFilePath());
    }

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
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QPixmap photos = ui->comboBox->currentText();
    ui->label_2->setPixmap(photos.scaled(779,443, Qt::KeepAspectRatioByExpanding));
}
