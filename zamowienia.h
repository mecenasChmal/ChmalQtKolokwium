#ifndef ZAMOWIENIA_H
#define ZAMOWIENIA_H

#include <QDialog>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QSortFilterProxyModel>
namespace Ui {
class Zamowienia;
}

class Zamowienia : public QDialog
{
    Q_OBJECT

public:
    explicit Zamowienia(QWidget *parent = nullptr);
    void setModel();
    ~Zamowienia();

private slots:
    void on_pbDodaj_clicked();

    void on_pbUsun_clicked();

    void on_pbPotwierdz_clicked();

private:
    Ui::Zamowienia *zam;
    QStandardItemModel *csvModel; //model- obsluga danych
};

#endif // ZAMOWIENIA_H
