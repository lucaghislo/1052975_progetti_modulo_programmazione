/*
 * Carfleetmanager.cpp
 * Author: Luca Ghislotti
 *
 * File di implementazione delle lambda functions associate
 * all'interazione dell'utente con l'interfaccia grafica
 *
 */

#include "Carfleetmanager.h"
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
#include <QColorDialog>

CarFleetManager::CarFleetManager(QWidget *parent): QWidget(parent), ui(new Ui::CarFleetManager) {
    ui->setupUi(this);

    ui->stdCarica1_input->setEnabled(false);
    ui->stdCarica2_input->setEnabled(false);
    ui->stdCarica3_input->setEnabled(false);
}

CarFleetManager::~CarFleetManager() {
    delete ui;
}


/*
 *  Metodo che preleva i valori dalla caselle di testo, costruisce
 *  l'auto (in funzione del tipo di auto selezionato) con i dati
 *  inseriti ed effettua il refresh dell'output con lo stato
 *  attuale della flotta
 */
void CarFleetManager::on_pulsanteSubmit_clicked() {
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

    if(targa.compare("") == 0 || targa.length() > 7)
       targa = "XX-XXX-XX";

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

    cout << g.stampaFlotta();
    ui->visualizzatore->setText(QString::fromStdString(g.stampaFlotta()));

    ui -> targa_input -> setText("");
    ui -> potenza_input -> setText("");
    ui -> peso_input -> setText("");
    ui -> tipoAuto -> setCurrentIndex(0);
    ui -> capSerb_input -> setText("");
    ui -> consUrbano_input -> setText("");
    ui -> consCombinato_input -> setText("");
    ui -> consExtra_input -> setText("");
    ui -> stdCarica1_input -> setText("");
    ui -> stdCarica2_input -> setText("");
    ui -> stdCarica3_input -> setText("");

}

/*
 *  Metodo per garantire la coerenza dei campi in funione del
 *  tipo di auto mostrato dal QComboBox
 */
void CarFleetManager::on_tipoAuto_currentIndexChanged() {
    switch(ui->tipoAuto->currentIndex()) {
    case 0: {
        ui->stdCarica1_input->setEnabled(false);
        ui->stdCarica2_input->setEnabled(false);
        ui->stdCarica3_input->setEnabled(false);
        ui->capSerb_input->setEnabled(true);
        ui->consCombinato_input->setEnabled(true);
        ui->consExtra_input->setEnabled(true);
        ui->consUrbano_input->setEnabled(true);
        break;
    }
    case 1: {
        ui->stdCarica1_input->setEnabled(false);
        ui->stdCarica2_input->setEnabled(false);
        ui->stdCarica3_input->setEnabled(false);
        ui->capSerb_input->setEnabled(false);
        ui->consCombinato_input->setEnabled(false);
        ui->consExtra_input->setEnabled(false);
        ui->consUrbano_input->setEnabled(false);
        break;
    }
    case 2:
        ui->stdCarica1_input->setEnabled(true);
        ui->stdCarica2_input->setEnabled(true);
        ui->stdCarica3_input->setEnabled(true);
        ui->capSerb_input->setEnabled(true);
        ui->consCombinato_input->setEnabled(true);
        ui->consExtra_input->setEnabled(true);
        ui->consUrbano_input->setEnabled(true);
        break;
    }
}
