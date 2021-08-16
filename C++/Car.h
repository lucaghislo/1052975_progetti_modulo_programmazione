/*
 * car.hpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef CAR_H_
#define CAR_H_
#include <string>

class Car {
public:
	Car(); // Metodo costruttore della classe

	/*
	 * Variabile statica della classe Car, comune a tutte le istanze della classe
	 * (essendo classe astratta la variabile, rappresentante il prefisso del numero di telaio
	 * dell'auto, sarà valore comune a tutte le istante delle classi derivate della classe Auto)
	 */
	static int prefix = 0;
	static short minPotenza = 30;

	/*
	 * Distruttore virtuale della classe Car, essendo quest'ultima una classe astratta
	 */
	virtual ~Car() = 0;

private:
	/*
	 * Metodo statico che incrementa il prefisso del numero di telaio nella forma di
	 * variabile statica, comune a tutte le istanze
	 */
	virtual static void increasePrefix = 0;
	char *targa; // targa dell'automobile
	char *numTelaio; // numero di telaio dell'automobile
	short potenza; // potenza dell'automobile in kW

protected:
	/*
	 * Classe auto è una classe astratta: non può essere istanziata,
	 * se non sotto forma delle sue classi derivate FFcar, Ecar e Hcar
	 */
	virtual void showInfo() = 0;
};

#endif /* CAR_H_ */
