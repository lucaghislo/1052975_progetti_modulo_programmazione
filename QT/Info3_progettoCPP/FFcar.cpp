/*
 * FFcar.cpp
 * Author: Luca Ghislotti
 *
 * Implementazione della classe FFcar
 *
 */

#include <iostream>
using namespace std;
#include <string>
#include "FFcar.h"

FFcar::FFcar(char *targaInput, int pesoInput, int potenzaInput,
        short fuelCapacity, double urbano, double combinato, double extra) :
        Car(targaInput, pesoInput, potenzaInput), capacitaSerbatoio(
                fuelCapacity) {
    consumi.insert(make_pair("    Urbano ", urbano));
    consumi.insert(make_pair("    Combi. ", combinato));
    consumi.insert(make_pair("      Extra", extra));
}

short FFcar::getCapSerb() {
    return capacitaSerbatoio;
}

string FFcar::printResumee() {
    string resumee = "";
    for (auto it = consumi.cbegin(); it!=consumi.cend(); it++)
        resumee = resumee + it->first + ":  " + std::to_string(it->second) +" L/100km\n";

    return resumee;
}

string FFcar::showInfo() {
    return "\nFOSSILE FUEL " + Car::showInfo() + "  Cap. Ser.:  " + std::to_string(getCapSerb()) + " L" + "\n" + printResumee();
}

string FFcar::getClassName() {
    return "F";
}

FFcar::~FFcar() {
    consumi.clear();
    cout << "cleared all FFcars" << endl;
}
