#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    filePath2 = "C:/Users/dalbi/Desktop/ProjetBTS/RepoGit/copiesImages";

    ui->pushButton_3->setEnabled(false);
    ui->progressBar->setValue(0);
    ui->progressBar->setVisible(false);
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
            ui->progressBar->setVisible(true);
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
    ui->progressBar->setValue(40);
    powershell->waitForFinished(-1);
    powershell->exitCode();
    filePath.clear();
    parametre.clear();

    ui->progressBar->setValue(100);
    QMessageBox::information(this,"","Transfert des images réussie...!");
    ui->progressBar->setVisible(false);
    //qDebug() << parametre;
}
