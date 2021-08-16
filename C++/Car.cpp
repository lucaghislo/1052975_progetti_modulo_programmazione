/*
 * car.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include "Car.h"

/*
 * Variabile statica della classe Car, comune a tutte le istanze della classe
 * (essendo classe astratta la variabile, rappresentante il prefisso del numero di telaio
 * dell'auto, sarà valore comune a tutte le istante delle classi derivate della classe Auto)
 */
unsigned int Car::prefix = 0;
/*
 * Primo costruttore senza parametri che inizializza l'auto con valori generici,
 * come nel caso in cui auto venga creata senza essere immatricolata
 */
Car::Car() {
	// Allocazione area di memoria su heap per salvataggio targa
	targa = (char*) malloc(sizeof(char) * 9);
	strcpy(targa, "XX-XXX-XX"); // targa generica pre-immatricolazione
	cout << "built anonymous car with " << targa << " number plate" << endl;

	try {
		Car::buildVIN(prefix);
	} catch (int x) {
		cout << "Errore creazione auto: threshold superata" << endl;
	}

	// Allocazione area di memoria su heap per salvataggio numero di telaio
	numTelaio = (char*) malloc(sizeof(char) * 10);
	strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-costruzione
	cout << "car with " << targa << " has VIN " << numTelaio << endl;

	potenza = minPotenza; // auto pre-immatricolata ha potenza di default
	cout << "car with " << targa << " and VIN " << numTelaio
			<< " has default power of " << potenza << " kW" << endl << endl;

	peso = 1000;

	/*
	 * Incremento del prefisso dopo la creazione dell'auto
	 */
	Car::increasePrefix();
}

/*
 * Costruttore della classe con parametro targa
 */
Car::Car(char *targaInput) {
	// Allocazione area di memoria su heap per salvataggio targa
	targa = (char*) malloc(sizeof(char) * 9);
	strcpy(targa, targaInput); // targa definita da parametro
	cout << "built car with " << targa << " number plate" << endl;

	try {
		Car::buildVIN(prefix);
	} catch (int x) {
		cout << "Errore creazione auto: threshold superata" << endl;
	}

	// Allocazione area di memoria su heap per salvataggio numero di telaio
	numTelaio = (char*) malloc(sizeof(char) * 10);
	strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-costruzione
	cout << "car with " << targa << " has VIN " << numTelaio << endl;

	potenza = minPotenza; // auto pre-immatricolata ha potenza di default
	cout << "car with " << targa << " and VIN " << numTelaio
			<< " has default power of " << potenza << " kW" << endl << endl;

	peso = 1000; // peso posto di default a 1000 Kg

	/*
	 * Incremento del prefisso dopo la creazione dell'auto
	 */
	Car::increasePrefix();
}

/*
 * Costruttore della classe con parametri targa e potenza che
 * sfrutta la member initializer list
 */
Car::Car(char *targaInput, int pesoInput, int potenzaInput) :
		peso(pesoInput), potenza(potenzaInput) {
	// Allocazione area di memoria su heap per salvataggio targa
	targa = (char*) malloc(sizeof(char) * 9);
	strcpy(targa, targaInput); // targa definita da parametro
	cout << "built car with " << targa << " number plate" << endl;

	try {
		Car::buildVIN(prefix);
	} catch (int x) {
		cout << "Errore creazione auto: threshold superata" << endl;
	}

	// Allocazione area di memoria su heap per salvataggio numero di telaio
	numTelaio = (char*) malloc(sizeof(char) * 10);
	strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-costruzione
	cout << "car with " << targa << " has VIN " << numTelaio << endl << endl;

	/*
	 * Incremento del prefisso dopo la creazione dell'auto
	 */
	Car::increasePrefix();
}

/*
 * Implementazione del copy-constructor
 */
Car::Car(const Car &newCar) {
	strcpy(Car::targa, newCar.targa);
	strcpy(Car::numTelaio, newCar.numTelaio);
	Car::potenza = newCar.potenza;
	Car::peso = newCar.peso;
}

void Car::increasePrefix() {
	Car::prefix++;
}

char* Car::buildVIN(int prefix) {
	string str_prefix = to_string(prefix);
	int lenght = str_prefix.length();
	char *VIN = (char*) malloc(sizeof(char) * 10);
	strcpy(VIN, str_prefix.data());

	if (lenght > 10) {
		delete VIN;
		throw 403; // error code nel caso venga superato il limite di immatricolazioni
	} else {
		// costruzione VIN generico con prefisso
		for (int i = 0; i < 10 - lenght; i++) {
			strcat(VIN, "X");
		}
	}

	return VIN;
}

char* Car::getTarga() {
	return Car::targa;
}

void Car::setTarga(char *newTarga) {
	strcpy(Car::targa, newTarga);
}

/*
 * Metodo distruttore della classe Car
 *
 * Car::~Car() {
 delete targa; // deallocazione della targa da heap
 delete numTelaio; // deallocazione del numero di telaio da heap
 }
 *
 *
 */

