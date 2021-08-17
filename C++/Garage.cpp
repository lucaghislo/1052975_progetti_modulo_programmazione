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

Garage::Garage() {
}

unique_ptr<Car> Garage::newAuto(int carType) {
	string targa;
	char *targa_ptr = (char*) malloc(sizeof(char) * targa.length());
	int peso, potenza;

	cout << "Targa: ";
	cin >> targa;
	cout << "\nPeso: ";
	cin >> peso;
	cout << "\nPotenza: ";
	cin >> potenza;

	switch (carType) {
	// FFcar
	case 0: {
		short fuelCap;
		double urbano, combi, extra;

		cout << "\nCapacità serbatoio: ";
		cin >> fuelCap;
		cout << "\nConsumo urbano: ";
		cin >> urbano;
		cout << "\nConsumo combinato: ";
		cin >> combi;
		cout << "\nConsumo extra-urbano: ";
		cin >> extra;

		unique_ptr<Car> veicoloFF(
				new FFcar(targa_ptr, peso, potenza, fuelCap, urbano, combi,
						extra));
		return veicoloFF;
	}

	// Ecar
	case 1: {
		unique_ptr<Car> veicoloE(new Ecar(targa_ptr, peso, potenza));
		return veicoloE;
	}

	// Hcar
	case 2: {
		short fuelCap;
		double urbano, combi, extra;
		int s1, s2, s3;

		cout << "\nCapacità serbatoio: ";
		cin >> fuelCap;
		cout << "\nConsumo urbano: ";
		cin >> urbano;
		cout << "\nConsumo combinato: ";
		cin >> combi;
		cout << "\nConsumo extra-urbano: ";
		cin >> extra;
		cout << "\nStandard 1: ";
		cin >> s1;
		cout << "\nStandard 2: ";
		cin >> s2;
		cout << "\nStandard 3: ";
		cin >> s3;

		vector<int> standards = { s1, s2, s3 };

		unique_ptr<Car> veicoloH(
				new Hcar(targa_ptr, peso, potenza, fuelCap, urbano, combi,
						extra, standards));
		return veicoloH;
	}

	default:
		/*
		 * Viene sollevata eccezione se utente non inserisce il corretto
		 * simbolo
		 */
		throw 403; // Error code
	}
}
