/*
 * TaxCalc.h
 *
 * Classe indipendente dalla gerarchia Car - Ecar - FFcar, amica della
 * classe Car, che accedere al campo "potenza" della classe Car allo scopo
 * di effettuare il calcolo del bollo auto
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef TAXCALC_H_
#define TAXCALC_H_

#include <iostream>
using namespace std;

/*
 * Classe TaxCalc definita come template in funzione del parametro
 * generico T: è possibile descrivere il bollo auto sotto forma di
 * valore numerico intero (int o short) oppure in virgola mobile
 * (double o float)
 */
template<typename T> class TaxCalc {
	static const int fattoreCorrettivo = 1.37; // costante
	T cavalliFiscali; // definito dall'utente all'istanziazione della classe

public:
	/*
	 * Costruttore della classe generica. Il passaggio del parametro (generico)
	 * avviene tramite riferimento const
	 */
	TaxCalc(T const &cf) :
			cavalliFiscali(cf) {
	}

	/*
	 * Function template per il calcolo del bollo auto dato il tipo
	 * generico S
	 */
	template<typename S> T calcoloBollo(S c) {
		return c->potenza * cavalliFiscali * fattoreCorrettivo;
	}
};

#endif /* TAXCALC_H_ */
