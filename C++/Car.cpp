/*
 ============================================================================
 Name        : Car.cpp
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : File di implementazione dei metodi della classe Car
 ============================================================================
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

	try {
		Car::buildVIN(prefix);
	} catch (int x) {
		cout << "Errore creazione auto: threshold superata" << endl;
	}

	// Allocazione area di memoria su heap per salvataggio numero di telaio
	numTelaio = new string();
	*numTelaio = buildVIN(prefix); // VIN generico pre-costruzione

	potenza = minPotenza; // auto pre-immatricolata ha potenza di default
	peso = 1000; // peso di default

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
	targa = strcpy((char*) malloc(sizeof(char) * 9), "XX-XXX-XX");

	if (strlen(targaInput) == 9)
		strcpy(targa, targaInput); // targa definita da parametro

	try {
		// Allocazione area di memoria su heap per salvataggio numero di telaio
		numTelaio = new string();
		*numTelaio = buildVIN(prefix); // VIN generico pre-costruzione
	} catch (int x) {
		cout << "Errore creazione auto: threshold superata" << endl;
	}

	/*
	 * Incremento del prefisso dopo la creazione dell'auto
	 */
	Car::increasePrefix();
}

/*
 * Implementazione del copy-constructor
 */
Car::Car(const Car &newCar) {
	strcpy(targa, newCar.targa);
	numTelaio = newCar.numTelaio;
	Car::potenza = newCar.potenza;
	Car::peso = newCar.peso;
}

void Car::increasePrefix() {
	Car::prefix++;
}

string Car::buildVIN(const int &prefix) {
	string str_prefix = to_string(prefix);
	int length = str_prefix.length();
	string VIN = str_prefix;

	if (length > 10) {
		throw 403; // error code nel caso venga superato il limite di immatricolazioni
	} else {
		// costruzione VIN generico con prefisso
		for (int i = 0; i < 10 - length; i++) {
			VIN += "X";
		}
	}

	return VIN;
}

char* Car::getTarga() {
	return Car::targa;
}

string Car::getVIN() {
	return *numTelaio;
}

short Car::getPotenza() {
	return Car::potenza;
}

short Car::getPeso() {
	return Car::peso;
}

void Car::setTarga(string newTarga) {
	if (newTarga.length() > 9)
		throw 403;
	else
		strcpy(targa, newTarga.data());
}

void Car::showInfo() {
	cout << "CAR DATA SUMMARY" << endl;
	cout << "    Targa:  " << getTarga() << endl;
	cout << "      VIN:  " << getVIN() << endl;
	cout << "  Potenza:  " << getPotenza() << " kW" << endl;
	cout << "     Peso:  " << getPeso() << " kg" << endl;
}

/*
 * Metodo distruttore della classe Car
 *
 */
Car::~Car() {
	free(targa); // deallocazione della targa da heap
	delete numTelaio; // deallocazione del numero di telaio da heap
	cout << "cleared all cars" << endl;
}
