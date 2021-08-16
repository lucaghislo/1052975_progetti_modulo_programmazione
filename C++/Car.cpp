/*
 * car.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
using namespace std;
#include "Car.h"

/*
 * Primo costruttore senza parametri che inizializza l'auto con valori generici,
 * come nel caso in cui auto venga creata senza essere immatricolata
 */
Car::Car() {
	targa = (char*) malloc(sizeof(char) * 9);
	targa = "XX-XXX-XX"; // targa generica pre-immatricolazione
	cout << "built anonymous car with " << targa << " number plate";

	numTelaio = (char*) malloc(sizeof(char) * 10);
	numTelaio = "XXXXXXXXXX"; // VIN generico pre-csotruzione
	cout << "car with " << targa << " has VIN " << numTelaio;

	potenza = minPotenza; // auto pre-immatricolata ha potenza di default
	cout << "car with " << targa << " and VIN " << numTelaio
			<< " has default power of " << potenza << " kW";
}

/*
 * Metodo distruttore della classe Car
 */
Car::~Car() {
	delete targa; // deallocazione della targa da heap
	delete numTelaio; // deallocazione del numero di telaio da heap
}
