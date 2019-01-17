#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel> //do dodawania elementow do tablicy
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_szukajButton_clicked();

    void on_wyswietlWszystko_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *csvModel; //model- obsluga danych
    QButtonGroup *radioGroup;
};

#endif // MAINWINDOW_H
