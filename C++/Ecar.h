/*
 * Ecar.h
 *
 * Classe derivata da Car che rappresenta l'auto elettrica
 * (E: Electric)
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef ECAR_H_
#define ECAR_H_
#include "Car.h"
#include <vector>

/*
 * Classe che rappresenta un'auto elettrica. Deriva dalla
 * classe base Car
 */
class Ecar: virtual public Car {
public:
	/*
	 * Costruttori della classe derivata
	 */
	Ecar(vector<int> standardInput);
	Ecar(char *targaInput, int pesoInput = 1500, int potenzaInput = 50);

	/*
	 * Prefisso virtual permette di implementare polimorfismo run-time
	 */
	virtual void showInfo();
	virtual void printResumee();
	short getCapBat(); // ottenimento capacità batteria
	void setBatCap(short batCap); // metodo per definizione capacità batteria

private:
	short capacitaBatteria; // parametro specifico per le auto elettriche (kWh)
	vector<int> standards; // elenco degli standard di tensione per la ricarica (V)

protected:
	/*
	 * Distruttore virtual della classe derivata permette invocazione del
	 * distruttore della classe base
	 */
	virtual ~Ecar();
};

#endif /* ECAR_H_ */
