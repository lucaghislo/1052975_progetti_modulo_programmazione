/*
 * Ecar.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
#include <vector>
using namespace std;
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

	printResumee();
}

void Ecar::setBatCap(short batCap) {
	capacitaBatteria = batCap;
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
	cout << " V\n" << endl;
}

void Ecar::showInfo() {
	cout << "\nELECTRIC ";
	Car::showInfo();
	cout << "Batt. cap:  " << getCapBat() << " kWh" << endl;
	printResumee();
}
