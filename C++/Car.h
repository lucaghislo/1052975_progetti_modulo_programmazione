/*
 * car.h
 *
 * Header della classe automobile utilizzata come
 * template per la creazione delle automobili elettriche, ibride e
 * tradizionali nella forma di classi derivate
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef CAR_HPP_
#define CAR_HPP_
#include <string>
#include <vector>
using namespace std;

class Car {
public:
	/*
	 * Overload del costruttore
	 */
	Car(); // Metodo costruttore della classe

	/*
	 * Costruttore con parametri targa, potenza e peso: di default la potenza viene
	 * impostata al minimo valore di potenza definito nella classe Car
	 */
	Car(char *targaInput, int pesoInput = 1000, int potenzaInput =
			Car::minPotenza);

	// Definizione del copy-constructor per la classe Car
	Car(const Car &newCar);

	char* getTarga(); // metodo per ottenere targa auto
	char* getVIN(); // metodo per ottenere numero di telaio auto
	short getPotenza(); // metodo per ottenere potenza auto
	short getPeso(); // metodo per ottenere peso auto

	void setTarga(string newTarga); // metodo per settare targa auto

	/*
	 * Prefisso virtual permette di implementare polimorfismo run-time.
	 * Notazione "= 0" implica non implementazione del metodo nella classe
	 * Car ma solo nelle sue classi derivate
	 */
	virtual void printResumee() = 0;

	/*
	 * Classe TaxCalc definita amica allo scopo di accedere al campo privato
	 * potenza ed effettuare calcolo bollo auto
	 */
	template<typename T> friend class TaxCalc;

	/*
	 * Classe auto è una classe astratta: non può essere istanziata,
	 * se non sotto forma delle sue classi derivate FFcar, Ecar e Hcar
	 * (motivazione notazione "= 0")
	 */
	virtual void showInfo() = 0;

private:
	/*
	 * Metodo statico che incrementa il prefisso del numero di telaio nella forma di
	 * variabile statica, comune a tutte le istanze
	 */
	char *targa; // targa dell'automobile
	char *numTelaio; // numero di telaio dell'automobile
	unsigned short potenza; // potenza dell'automobile (kW)
	unsigned short peso; // peso dell'auto (Kg)
	static unsigned const short minPotenza = 30; // costante: potenza minima automobile
	static unsigned int prefix; // prefisso per costruzione numero di telaio

protected:
	/*
	 * Metodo per costruire il numero di telaio sulla base del prefisso statico
	 * comune a tutte le auto: nel caso in cui venga superato il numero massim
	 * di auto immatricolabili (su 10 cifre del numero di telaio) viene sollevata
	 * un'eccezione
	 */
	char* buildVIN(int prefix);

	/*
	 * Metodo per incrementare il prefisso automaticamente alla creazione di una
	 * nuova auto
	 */
	static void increasePrefix();

	/*
	 * Distruttore virtuale della classe Car, essendo quest'ultima una classe astratta
	 */
	virtual ~Car();
};

#endif /* CAR_H_ */
