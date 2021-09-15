/*
 ============================================================================
 Name        : Main.cpp
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Classe main del progetto, in cui ne viene testato
 il funzionamento
 ============================================================================
 */

#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include "Garage.h"
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
	 *  All'utente viene richiesto quante auto inserire:
	 * alla creazione, vengono inserite in un vector di cui viene restuito
	 * lo smart pointer all'istanza di Car (una delle sue classi derivate) e
	 * vengono stampate le informazioni associate all'intera flotta tramite
	 * la funzione stampaFlott() che sfrutta showInfo() specializzata
	 * per ciascun tipo di auto
	 */

	int count = 0;
	cout << "Numero di auto da inserire: ";
	cin >> count;

	while (count > 0) {
		try {
			g.newAuto();
			g.stampaFlotta();
		} catch (int x) {
			cout << "Errore selezione tipo auto" << endl;
		}
		count--;
	}

	g.printToFile();
}
