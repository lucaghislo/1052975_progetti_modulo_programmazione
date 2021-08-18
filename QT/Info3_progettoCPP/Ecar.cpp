/*
 * Ecar.cpp
 * Author: Luca Ghislotti
 *
 * Implementazione delle classe Ecar
 *
 */

#include <iostream>
using namespace std;
#include <vector>
#include "Ecar.h"

Ecar::Ecar(vector<int> standardsInput) :
        Car() {
    capacitaBatteria = 0;
    standards = standardsInput;
}

Ecar::Ecar(char *targaInput, int pesoInput, int potenzaInput) :
        Car(targaInput, pesoInput, potenzaInput), capacitaBatteria(400) {

    standards.push_back(110);
    standards.push_back(230);
    standards.push_back(380);
}

void Ecar::setBatCap(short batCap) {
    capacitaBatteria = batCap;
}

string Ecar::getClassName() {
    return "E";
}

Ecar::~Ecar() {
    standards.clear();
    cout << "cleared all Ecars" << endl;
}

short Ecar::getCapBat() {
    return capacitaBatteria;
}

/*
 * Stampa degli standard sfruttando iteratore su STL vector
 */
string Ecar::printResumee() {
    string resumee = "Standards:  ";
    for (vector<int>::iterator it = standards.begin(); it != standards.end();
            ++it)
        resumee = resumee + std::to_string(*it) + "  ";
    resumee = resumee + " V\n";

    return resumee;
}

string Ecar::showInfo() {
    string capBat = std::to_string(getCapBat());
    return  "\nELECTRIC " + Car::showInfo() + "  Batt. cap:  " + capBat + " kWh" +"\n" + printResumee() + "\n";
}
