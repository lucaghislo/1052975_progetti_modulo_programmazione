/*
 * Hcar.cpp
 *
 * Implementazione della classe Hcar
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include "Hcar.h"
#include <iostream>
using namespace std;
#include "FFcar.h"
#include "Ecar.h"

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

void Hcar::showInfo() {
	cout << "\nHYBRID ";
	Car::showInfo(); // risoluzione esplicita del name clashing
	printResumee();
}

void Hcar::printResumee() {
	cout << "Cap. Ser.:  " << getCapSerb() << " L" << endl;
	cout << "Bat. cap.:  " << getCapBat() << " kWh" << endl;
	cout << " Cap. Co.:  " << capacitaCombinata << " km" << endl << endl;
}

string Hcar::getClassName() {
	return "H";
}

Hcar::~Hcar() {
	cout << "cleared all Hcars" << endl;
}
