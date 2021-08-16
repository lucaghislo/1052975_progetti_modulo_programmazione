/*
 * FFcar.h
 *
 * Classe derivata da Car che rappresenta l'auto a combustibile
 * fossile (FF: Fossile Fuel)
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef FFCAR_H_
#define FFCAR_H_
#include <map>
#include <string>
#include "Car.h"

class FFcar: virtual public Car {
public:
	/*
	 * Costruttore della classe derivata che sfrutta il costruttore
	 * della classe base
	 */
	FFcar(char *targaInput, int pesoInput, int potenzaInput, short fuelCapacity,
			double urbano, double combi, double extra);

	/*
	 * Prefisso virtual permette di implementare polimorfismo run-time
	 */
	virtual void showInfo();
	virtual void printResumee();
	short getCapSerb(); // ottenimento capacità serbatoio combustibile

private:
	short capacitaSerbatoio; // capacità serbatoio auto tradizionale

	/*
	 * STL map per memorizzare i consumi medi in varie modalità di guida
	 */
	map<string, double> consumi;

protected:
	/*
	 * Distruttore virtual della classe derivata permette invocazione del
	 * distruttore della classe base
	 */
	virtual ~FFcar();
};

#endif /* FFCAR_H_ */
