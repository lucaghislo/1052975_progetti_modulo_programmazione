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
 * singleton, allo scopo di garantire che non vi sia pi� di
 * un'istanza di questa classe (evito r)
 */
class Garage {
public:
	static Garage& getInstance() {
		static Garage instance; // Garantita la distruzione dell'istanza
		// Instanziazione al primo uso
		return instance;
	}

	/*
	 * Utilizzo dei puntatori smart: creo funzione che restituisce
	 * smart pointer ad auto creata ed inserita in un STL vector
	 * di smart pointers
	 */
	void newAuto();

	/*
	 * Funzione che, dato in input un raw pointer, restiuisce un bool
	 * che rappresenta il fatto che l'auto passata come parametro sia
	 * elettrica (quindi ibrida o elettrica) oppure no
	 */
	bool isElectric(Car *c);

	/*
	 * Funzione per il print delle informazioni di un'auto
	 */
	void stampaInfoAuto(Car *c);

	/*
	 * Funzione per il print dell'intero STL vector flotta del garage
	 */
	void stampaFlotta();

	/*
	 * Esempio di funzione inline che restituisce il numero di auto
	 * nella flotta
	 */
	inline short countAuto() {
		return flotta.size();
	}

private:
	vector<unique_ptr<Car>> flotta;

	// Costruttore vuoto della classe Garage
	Garage();

	// Copy constructor della classe Garage
	Garage(Garage const&);
};

#endif /* GARAGE_H_ */
