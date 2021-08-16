/*
 * car.h
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef CAR_HPP_
#define CAR_HPP_
#include <string>

class Car {
public:
	/*
	 * Overload del costruttore
	 */
	Car(); // Metodo costruttore della classe
	Car(char *targaInput); // Metodo costruttore della classe con parametro targa

	/*
	 * Costruttore con parametri targa e potenza: di default la potenza viene impostata
	 * al minimo valore di potenza definito nella classe Car
	 */
	Car(char *targaInput, int pesoInput, int potenzaInput);

	// Definizione del copy-constructor per la classe Car
	Car(const Car& newCar);

	/*
	 * Distruttore virtuale della classe Car, essendo quest'ultima una classe astratta
	 */
	//virtual ~Car() = 0;

	char* getTarga();
	void setTarga(char* newTarga);

private:
	/*
	 * Metodo statico che incrementa il prefisso del numero di telaio nella forma di
	 * variabile statica, comune a tutte le istanze
	 */
	char *targa; // targa dell'automobile
	char *numTelaio; // numero di telaio dell'automobile
	unsigned short potenza; // potenza dell'automobile in kW
	unsigned short peso; // peso dell'auto in Kg
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
	 * Classe auto è una classe astratta: non può essere istanziata,
	 * se non sotto forma delle sue classi derivate FFcar, Ecar e Hcar
	 */
	//virtual void showInfo() = 0;
};

#endif /* CAR_H_ */
