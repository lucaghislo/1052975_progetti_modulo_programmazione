/*
 * Hcar.cpp
 * Author: Luca Ghislotti
 *
 * Implementazione della classe Hcar
 *
 */

#include <iostream>
using namespace std;
#include "FFcar.h"
#include "Ecar.h"
#include "Hcar.h"

/*
 * Costruttore della classe derivata che sfrutta i costruttori delle sue
 * classi base
 */
Hcar::Hcar(char *targaInput, int pesoInput, int potenzaInput, short capInput,
        double urbano, double combinato, double extra,
        vector<int> standardsInput) :
        Car(targaInput, pesoInput, potenzaInput), FFcar(targaInput, pesoInput,
                potenzaInput, capInput, urbano, combinato, extra), Ecar(
                standardsInput) {
    capacitaCombinata = 300; // inizializzazione della capacità combinata auto ibrida
}

string Hcar::showInfo() {
    return + "\nHYBRID " + Car::showInfo() + printResumee();
}

string Hcar::printResumee() {
    return "  Cap. Ser.:  " + std::to_string(getCapSerb()) + " L\n  Bat. cap.:  " + std::to_string(getCapBat()) + " kWh\n  Cap. Co.:  " + std::to_string(capacitaCombinata) + " km\n";
}

string Hcar::getClassName() {
    return "H";
}

Hcar::~Hcar() {
    cout << "cleared all Hcars" << endl;
}
