#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QProcess>
#include "transfertimages.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void maFonctionTimer(); //Fonction servant à vérifier en permannace si une carte SD est présente

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    //Variables pour la fonction de transfert
    QString cheminUtilisateur = "E:/DCIM";
    TransfertImages *obj;   //Pointeur vers un objet de la classe TransfertImages

    //Objet timer utiliser pour maFonctionTimer()
    QTimer *monTimer;

};
#endif // MAINWINDOW_H
