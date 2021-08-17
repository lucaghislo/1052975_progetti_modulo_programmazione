/*
 * Garage.cpp
 *
 * Implementazione della class Garage: sfrutto il concetto di
 * Smart Pointers nella forma unique_ptr<>
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <memory>
#include "Garage.h"
#include "Car.h"
#include "FFcar.h"
#include "Hcar.h"
#include "Ecar.h"
#include <typeinfo>

Garage::Garage() {
}

void Garage::newAuto() {
	string targa;
	char *targa_ptr = (char*) malloc(sizeof(char) * targa.length());
	int peso, potenza;

	cout << "\nTarga: ";
	cin >> targa;
	cout << "Peso: ";
	cin >> peso;
	cout << "Potenza: ";
	cin >> potenza;

	int carType;
	cout << "Tipo auto: ";
	cin >> carType;

	strcpy(targa_ptr, targa.data());

	switch (carType) {
	// FFcar
	case 0: {
		short fuelCap;
		double urbano, combi, extra;

		cout << "Capacità serbatoio: ";
		cin >> fuelCap;
		cout << "Consumo urbano: ";
		cin >> urbano;
		cout << "Consumo combinato: ";
		cin >> combi;
		cout << "Consumo extra-urbano: ";
		cin >> extra;

		/*
		 * Utilizzo dello smart pointer unique_ptr che, essendo univoco,
		 * deve essere esplicitamente spostato nel containter STL
		 * vector (ne esiste una sola copia)
		 */
		unique_ptr<Car> veicoloFF(
				new FFcar(targa_ptr, peso, potenza, fuelCap, urbano, combi,
						extra));
		flotta.push_back(move(veicoloFF)); // push dello smart pointer nel vector
		cout << "Creata auto tradizionale" << endl << endl;
		break;
	}

		// Ecar
	case 1: {
		unique_ptr<Car> veicoloE(new Ecar(targa_ptr, peso, potenza));
		flotta.push_back(move(veicoloE));
		cout << "Creata auto elettrica" << endl << endl;
		break;
	}

		// Hcar
	case 2: {
		short fuelCap;
		double urbano, combi, extra;
		int s1, s2, s3;

		cout << "Capacità serbatoio: ";
		cin >> fuelCap;
		cout << "Consumo urbano: ";
		cin >> urbano;
		cout << "Consumo combinato: ";
		cin >> combi;
		cout << "Consumo extra-urbano: ";
		cin >> extra;
		cout << "Standard 1: ";
		cin >> s1;
		cout << "Standard 2: ";
		cin >> s2;
		cout << "Standard 3: ";
		cin >> s3;

		vector<int> standards = { s1, s2, s3 };

		unique_ptr<Car> veicoloH(
				new Hcar(targa_ptr, peso, potenza, fuelCap, urbano, combi,
						extra, standards));
		flotta.push_back(move(veicoloH));
		cout << "Creata auto ibrida" << endl << endl;
		break;
	}

	default:
		/*
		 * Viene sollevata eccezione se utente non inserisce il corretto
		 * simbolo
		 */
		throw 403; // Error code
	}
}

bool Garage::isElectric(Car *c) {
	if (c->getClassName() == "E" || c->getClassName() == "H")
		return true;
	else
		return false;
}

void Garage::stampaInfoAuto(Car *c) {
	c->showInfo();
}

void Garage::stampaFlotta() {
	cout << "***AUTO NELLA FLOTTA***" << endl;
	for (auto const &i : flotta) {
		i.get()->showInfo();
	}
}
