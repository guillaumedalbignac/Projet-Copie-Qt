#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_comboBox_2_currentIndexChanged();

private:
    Ui::MainWindow *ui;
    QSqlDatabase maDataBase;
    QSqlQueryModel *model;
    //----------------------------------------//
    QString imagesRecues;
    QSqlQuery *query2;
    QString nomJoueur;
};
#endif // MAINWINDOW_H
