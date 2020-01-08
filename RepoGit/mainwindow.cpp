#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDir>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir monRepertoire("C:/User/dalbi/Desktop/ProjetBTS/RepoGit");
    foreach(QFileInfo var, monRepertoire.entryInfoList()){
        ui->comboBox->addItem(var.absoluteFilePath());

    }
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
