#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    csvModel=new QStandardItemModel(this);

    radioGroup = new QButtonGroup(this);
    radioGroup->setExclusive(true);
    radioGroup->addButton(ui->radioTytul, 0);
    radioGroup->addButton(ui->radioAutor, 1);
    radioGroup->addButton(ui->radioRok, 2);
    radioGroup->addButton(ui->radioGatunek, 3);
}

MainWindow::~MainWindow(){
    delete ui;
    delete csvModel;
}

void MainWindow::on_szukajButton_clicked(){
    QString query=ui->poleSzukaj->text();

    QFile file("data.csv");
    if (!file.open(QFile::ReadOnly | QFile::Text) ){
        ui->komunikat->setText(file.fileName()+"nie istnieje");
    }
    else{
        //strumien do odczytania danych z pliku
        QTextStream txtStream(&file);
        //czyszcze tablice
        csvModel->clear();
        QStringList header;
        header<<"Tytul"<<"Autor"<<"Rok wydania"<<"Gatunek";
        csvModel->setHorizontalHeaderLabels(header);
        ui->ksiazkiTabela->setModel(csvModel); // ustaw model w tabeli
        //naglowki tabeli

        // wczytujemy linia po linii az do konca pliku
        while (!txtStream.atEnd()){
            QString line = txtStream.readLine();
            QList<QStandardItem*> list;
            //jesli element zawiera zapytanie to wiersz zostanie wyswietlony
            if(line.contains(query)){
                for (QString item : line.split(";")){
                    list.append(new QStandardItem(item));
                }
                //test, chce sie pozbyc pustych wierszy
                csvModel->insertRow(csvModel->rowCount(), list);
            }
        }
        file.close();
       }

}

void MainWindow::on_wyswietlWszystko_clicked(){
    csvModel->clear();

    QStringList header;
    header<<"Tytul"<<"Autor"<<"Rok wydania"<<"Gatunek";
    csvModel->setHorizontalHeaderLabels(header);
    ui->ksiazkiTabela->setModel(csvModel); // ustaw model w tabeli
    //naglowki tabeli

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
