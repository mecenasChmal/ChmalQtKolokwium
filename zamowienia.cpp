#include "zamowienia.h"
#include "ui_zamowienia.h"

Zamowienia::Zamowienia(QWidget *parent) :
    QDialog(parent),
    zam(new Ui::Zamowienia)
{
    zam->setupUi(this);
    setModel();

}

Zamowienia::~Zamowienia(){
    delete zam;
}
void Zamowienia::setModel(){
    csvModel=new QStandardItemModel(this); //model do wczytania danych
    QFile file("data.csv");
    if (!file.open(QFile::ReadOnly | QFile::Text) ){
        zam->lLiczba->setText(file.fileName()+"nie istnieje");
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
    zam->cbPozycje->setModel(csvModel);
}

void Zamowienia::on_pbDodaj_clicked(){
    zam->lista->addItem(zam->cbPozycje->itemText(zam->cbPozycje->currentIndex()));
    int zamowienia=0;
    for(int i=0;i<zam->lista->count();i++){
        zamowienia+=1;
    }
    zam->suma->setText(QString::number(zamowienia));
}

void Zamowienia::on_pbUsun_clicked(){
    int index=zam->lista->currentRow();
    zam->lista->takeItem(index);
    int zamowienia=zam->suma->text().toInt()-1;
    zam->suma->setText(QString::number(zamowienia));
}

void Zamowienia::on_pbPotwierdz_clicked(){
    QDialog::done(0);
}
