/*
 * FFcar.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
#include "FFcar.h"
#include <string>
using namespace std;

FFcar::FFcar(char *targaInput, int pesoInput, int potenzaInput,
		short fuelCapacity, double urbano, double combinato, double extra) :
		Car(targaInput, pesoInput, potenzaInput), capacitaSerbatoio(
				fuelCapacity) {
	consumi.insert(make_pair("    Urbano", urbano));
	consumi.insert(make_pair(" Combinato", combinato));
	consumi.insert(make_pair("     Extra", extra));
}

short FFcar::getCapSerb() {
	return capacitaSerbatoio;
}

void FFcar::printResumee() {
	for (map<string, double>::iterator it = consumi.begin();
			it != consumi.end(); ++it)
		cout << it->first << ":  " << it->second << " L/100km\n";
}

void FFcar::showInfo() {
	cout << "\nFOSSILE FUEL CAR DATA SUMMARY" << endl;
	cout << "     Targa:  " << getTarga() << endl;
	cout << "       VIN:  " << getVIN() << endl;
	cout << "   Potenza:  " << getPotenza() << " kW" << endl;
	cout << "      Peso:  " << getPeso() << " kg" << endl;
	cout << "Cap. Serb.:  " << getCapSerb() << " L" << endl;
	printResumee();
}

FFcar::~FFcar() {
	consumi.clear();
	cout << "cleared all FFcars" << endl;
}

