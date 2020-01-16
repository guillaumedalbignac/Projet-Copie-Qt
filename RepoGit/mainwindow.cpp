#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "transfertimages.h"
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete obj;
}

void MainWindow::on_pushButton_clicked()
{
   // cheminUtilisateur = QFileDialog::getExistingDirectory(this,tr("Open Directory"),"");
    obj = new TransfertImages;
    if(cheminUtilisateur != "" && obj->detecterCarteSd() == true){
         obj->effectuerTransfert(cheminUtilisateur);
         qDebug() << "Transfert ok...!";
    }
}
