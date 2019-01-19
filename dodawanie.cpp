#include "dodawanie.h"
#include "ui_dodawanie.h"

Dodawanie::Dodawanie(QWidget *parent) :
    QDialog(parent),
    dd(new Ui::Dodawanie){
    dd->setupUi(this);
}

Dodawanie::~Dodawanie(){
    delete dd;
}

void Dodawanie::on_dodajButton_clicked(){
     //wczytujemy plik data.csv
    QFile file("data.csv");
    if (!file.open(QFile::WriteOnly | QIODevice::Append | QFile::Text) ){
        qDebug()<<file.fileName()+"nie istnieje";
    }
    else{
        //zapisywanie danych do pliku: operator <<
        QTextStream txtStream(&file);
        QString tytul=dd->pTytul->text();
        QString autor=dd->pAutor->text();
        QString rok=dd->pRokWydania->text();
        QString gatunek=dd->pGatunek->text();
        txtStream<<tytul+";"+autor+";"+rok+";"+gatunek<<endl;
        file.flush();

        file.close();
       }
    dd->pTytul->setText("");
    dd->pAutor->setText("");
    dd->pRokWydania->setText("");
    dd->pGatunek->setText("");
}

