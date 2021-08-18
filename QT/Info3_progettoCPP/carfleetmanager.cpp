using namespace std;
#include "carfleetmanager.h"
#include "ui_carfleetmanager.h"
#include <iostream>
#include <cstring>
#include <memory>
#include "Garage.h"
#include "Car.h"
#include "FFcar.h"
#include "Hcar.h"
#include "Ecar.h"
#include <QTextEdit>

CarFleetManager::CarFleetManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CarFleetManager)
{
    ui->setupUi(this);
}

CarFleetManager::~CarFleetManager()
{
    delete ui;
}


void CarFleetManager::on_pulsanteSubmit_clicked()
{
    QString Qtarga = ui -> targa_input -> text();
    int potenza = ui -> potenza_input -> text().toInt();
    int peso = ui -> peso_input -> text().toInt();
    int tipoAuto = ui -> tipoAuto -> currentIndex();
    double capSerb = ui -> capSerb_input -> text().toDouble();
    double consUrbano = ui -> consUrbano_input -> text().toDouble();
    double consCombinato = ui -> consCombinato_input -> text().toDouble();
    double consExtra = ui -> consExtra_input -> text().toDouble();
    int stdCarica1 = ui -> stdCarica1_input -> text().toInt();
    int stdCarica2 = ui -> stdCarica2_input -> text().toInt();
    int stdCarica3 = ui -> stdCarica3_input -> text().toInt();

    std::string targa = Qtarga.toLocal8Bit().constData();
    char *targa_ptr = (char*) malloc(sizeof(char) * targa.length());
    strcpy(targa_ptr, targa.data());

    Garage &g = Garage::getInstance();

    switch (tipoAuto) {
    case 0: {
        unique_ptr<Car> veicoloFF(
        new FFcar(targa_ptr, peso, potenza, capSerb, consUrbano, consCombinato, consExtra));
        g.flotta.push_back(std::move(veicoloFF)); // push dello smart pointer nel vector
        cout << "Creata auto tradizionale" << endl << endl;
        break;
    }

    case 1: {
        unique_ptr<Car> veicoloE(new Ecar(targa_ptr, peso, potenza));
        g.flotta.push_back(std::move(veicoloE));
        cout << "Creata auto elettrica" << endl << endl;
        break;
    }

    case 2:
        vector<int> standards = { stdCarica1, stdCarica2, stdCarica3 };
        unique_ptr<Car> veicoloH(
        new Hcar(targa_ptr, peso, potenza, capSerb, consUrbano, consCombinato, consExtra, standards));
        g.flotta.push_back(std::move(veicoloH));
        cout << "Creata auto ibrida" << endl << endl;
        break;
    }

    string text = "ciao";
    cout << g.stampaFlotta();
    ui->visualizzatore->setText(QString::fromStdString(g.stampaFlotta()));

}

