#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel> //do dodawania elementow do tablicy
#include <QButtonGroup>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSortFilterProxyModel>
#include "dodawanie.h"
#include "zamowienia.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setModel();
    ~MainWindow();



private slots:
    void on_szukajButton_clicked();
    void on_wyswietlWszystko_clicked();

    void on_actionDodaj_triggered();

    void on_actionZamow_triggered();

private:
    QStandardItemModel *csvModel; //model- obsluga danych
    Ui::MainWindow *ui;
    QButtonGroup *radioGroup;
    QSortFilterProxyModel *proxyModel;
};

#endif // MAINWINDOW_H
