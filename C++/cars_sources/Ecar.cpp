/*
 ============================================================================
 Name        : Ecar.cpp
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Implementazione delle classe Ecar
 ============================================================================
 */

#include <iostream>
using namespace std;
#include <vector>
#include "cars_headers/Ecar.h"

Ecar::Ecar(vector<int> standardsInput) :
		Car() {
	capacitaBatteria = 10;
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
void Ecar::printResumee() {
	cout << "Standards: ";
	for (vector<int>::iterator it = standards.begin(); it != standards.end();
			++it)
		cout << ' ' << *it;
	cout << " V" << endl;
}

void Ecar::showInfo() {
	cout << "\nELECTRIC ";
	Car::showInfo();
	cout << "Batt. cap:  " << getCapBat() << " kWh" << endl;
	printResumee();
	cout << "";
}
