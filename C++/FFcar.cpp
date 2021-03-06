/*
 ============================================================================
 Name        : FFcar.cpp
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Implementazione della classe FFcar
 ============================================================================
 */

#include <iostream>
using namespace std;
#include <string>
#include "FFcar.h"

FFcar::FFcar(char *targaInput, int pesoInput, int potenzaInput,
		short fuelCapacity, double urbano, double combinato, double extra) :
		Car(targaInput, pesoInput, potenzaInput), capacitaSerbatoio(
				fuelCapacity) {
	consumi.insert(make_pair("   Urbano", urbano));
	consumi.insert(make_pair("Combinato", combinato));
	consumi.insert(make_pair("    Extra", extra));
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
	cout << "\nFOSSILE FUEL ";
	Car::showInfo();
	cout << "Cap. Ser.:  " << getCapSerb() << " L" << endl;
	printResumee();
}

string FFcar::getClassName() {
	return "F";
}

FFcar::~FFcar() {
	consumi.clear();
	cout << "cleared all FFcars" << endl;
}
