#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath2 = "C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/copiesImages";

    ui->pushButton_3->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    filePath = QFileDialog::getExistingDirectory(this,tr("Open Directory"),"");
    if(filePath !=  ""){
            ui->pushButton_3->setEnabled(true);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    pathFinal = "Copy-Item -Path " + filePath + " -Destination " + filePath2 + " -Recurse";
    //qDebug() << pathFinal;
    parametre << pathFinal;
    powershell = new QProcess();
    powershell->setWorkingDirectory("C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/copiesImages");
    powershell->start(cheminPowershell, parametre);
    powershell->waitForFinished(-1);
    powershell->exitCode();
    filePath.clear();
    parametre.clear();
    //qDebug() << parametre;
}
