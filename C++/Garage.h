/*
 * Garage.h
 *
 * Classe Garage permette di utilizzare le auto e gestirle
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef GARAGE_H_
#define GARAGE_H_
#include "Car.h"
#include <vector>
#include <memory>
#include <string>

/*
 * Implemento la classe Garage sfruttando il design pattern
 * singleton, allo scopo di garantire che non vi sia più di
 * un'istanza di questa classe (evito r)
 */
class Garage {
public:
	static Garage& getInstance() {
		static Garage instance; // Garantita la distruzione dell'istanza
		// Instanziazione al primo uso
		return instance;
	}

	unique_ptr<Car> newAuto(int carType);

private:
	vector<unique_ptr<Car>> flotta;

	// Costruttore vuoto della classe Garage
	Garage();

	// Copy constructor della classe Garage
	Garage(Garage const&);
};

#endif /* GARAGE_H_ */
