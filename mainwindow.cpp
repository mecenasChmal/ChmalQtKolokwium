#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    setModel();

}
void MainWindow::setModel(){
    csvModel=new QStandardItemModel(this); //model do wczytania danych
    proxyModel=new QSortFilterProxyModel(this); //model do sortowania tabeli
    proxyModel->setSourceModel(csvModel);
    ui->ksiazkiTabela->setModel(proxyModel); //ustawienie modelu w tabeli
    ui->ksiazkiTabela->setSortingEnabled(true);
    //pogrupowanie przyciskow i przypisanie wartosci
    radioGroup = new QButtonGroup(this);
    radioGroup->setExclusive(true);
    radioGroup->addButton(ui->radioTytul, 0);
    radioGroup->addButton(ui->radioAutor, 1);
    radioGroup->addButton(ui->radioRok, 2);
    radioGroup->addButton(ui->radioGatunek, 3);


    //wczytanie tablicy
    on_wyswietlWszystko_clicked();

}
MainWindow::~MainWindow(){
    delete ui;
    delete csvModel;
    delete proxyModel;
}

void MainWindow::on_szukajButton_clicked(){
    QString query=ui->poleSzukaj->text(); //ustawienie zapytania
    int option=radioGroup->checkedId(); //po czym szukamy
    proxyModel->setFilterKeyColumn(option); //wybranie kolumny w ktorej bedziemy szukac
    proxyModel->setFilterRegExp(query); //przeszukiwanie
}

void MainWindow::on_wyswietlWszystko_clicked(){
    csvModel->clear();
    proxyModel->setFilterRegExp(""); //usuniecie filtra
    //naglowki tabeli
    QStringList header;
    header<<"Tytul"<<"Autor"<<"Rok wydania"<<"Gatunek";
    csvModel->setHorizontalHeaderLabels(header);
    ui->ksiazkiTabela->setColumnWidth(0,200);
     //wczytujemy plik data.csv
    QFile file("data.csv");
    if (!file.open(QFile::ReadOnly | QFile::Text) ){
        ui->komunikat->setText(file.fileName()+"nie istnieje");
    }
    else{
        //strumien do odczytania danych z pliku
        QTextStream txtStream(&file);
        // wczytujemy linia po linii az do konca pliku
        while (!txtStream.atEnd()){
            QString line = txtStream.readLine();
            // dodajemy linie do modelu
            QList<QStandardItem*> list;
            for (QString item : line.split(";")){
                list.append(new QStandardItem(item));
            }
            csvModel->insertRow(csvModel->rowCount(), list);
        }
        file.close();
       }
}

void MainWindow::on_actionDodaj_triggered(){
    Dodawanie dodawanie;
    dodawanie.setModal(true);
    dodawanie.exec();
}

void MainWindow::on_actionZamow_triggered(){
    Zamowienia zamowienia;
    zamowienia.setModal(true);
    zamowienia.exec();
}
