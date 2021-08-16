/*
 * car.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
using namespace std;
#include "Car.h"
#include <string>
#include <cstring>

/*
 * Primo costruttore senza parametri che inizializza l'auto con valori generici,
 * come nel caso in cui auto venga creata senza essere immatricolata
 */
Car::Car() {
	/*
	 * Variabile statica della classe Car, comune a tutte le istanze della classe
	 * (essendo classe astratta la variabile, rappresentante il prefisso del numero di telaio
	 * dell'auto, sarà valore comune a tutte le istante delle classi derivate della classe Auto)
	 */
	static int prefix = 0;

	targa = (char*) malloc(sizeof(char) * 9);
	strcpy(targa, "XX-XXX-XX"); // targa generica pre-immatricolazione
	cout << "built anonymous car with " << targa << " number plate";

	numTelaio = (char*) malloc(sizeof(char) * 10);
	strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-csotruzione
	cout << "car with " << targa << " has VIN " << numTelaio;

	potenza = minPotenza; // auto pre-immatricolata ha potenza di default
	cout << "car with " << targa << " and VIN " << numTelaio
			<< " has default power of " << potenza << " kW";
}

char* Car::buildVIN(int prefix) {
	string str_prefix = to_string(prefix);
	int lenght = str_prefix.length();
	string VIN;

	if (lenght > 10)
		throw 403; // error code nel caso venga superato il limite di immatricolazioni
	else
		VIN = str_prefix + "X" * (10 - lenght); // costruzione VIN generico con prefisso

	return VIN;
}

/*
 * Metodo distruttore della classe Car
 */
Car::~Car() {
	delete targa; // deallocazione della targa da heap
	delete numTelaio; // deallocazione del numero di telaio da heap
}
