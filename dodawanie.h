#ifndef DODAWANIE_H
#define DODAWANIE_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
namespace Ui {
class Dodawanie;
}

class Dodawanie : public QDialog
{
    Q_OBJECT

public:
    explicit Dodawanie(QWidget *parent = nullptr);
    ~Dodawanie();

private slots:
    void on_dodajButton_clicked();


private:
    Ui::Dodawanie *dd;
};

#endif // DODAWANIE_H
