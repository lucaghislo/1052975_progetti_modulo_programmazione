/*
 * main.cpp
 *
 * Classe main del progetto, in cui ne viene testato
 * il funzionamento
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
#include "Garage.h"
#include <cstring>
#include <vector>
using namespace std;

#include "Car.h"
#include "Ecar.h"
#include "FFcar.h"
#include "Hcar.h"
#include "TaxCalc.h"
#include "Garage.h"

int main() {
	/*
	 * Istanziazione del garage sfruttando il design pattern singleton
	 */
	Garage &g = Garage::getInstance();

	/*
	 * All'utente viene richiesto ad inoltranza di inserire auto:
	 * alla creazione, vengono inserite in un vector di cui viene restuito
	 * lo smart pointer all'istanza di Car (una delle sue classi derivate),
	 * stampato il risultato della funzione isElectric() e le informazioni
	 * associate all'auto creata con la funzione showInfo()
	 */
	while (true) {
		try {
			g.newAuto();
			g.stampaFlotta();

		} catch (int x) {
			cout << "Errore selezione tipo auto";
		}
	}
}
