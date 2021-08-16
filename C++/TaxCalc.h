/*
 * TaxCalc.h
 *
 *  Created on: 16 ago 2021
 *      Author: ghisl
 */

#ifndef TAXCALC_H_
#define TAXCALC_H_

#include <iostream>
using namespace std;

//TODO documentazione classe amica template con template funzione

/*
 * Classe TaxCalc definita come template in funzione del parametro
 * generico T
 */
template<typename T> class TaxCalc {
	T cavalliFiscali;
	static const int fattoreCorrettivo = 1.37;

public:
	TaxCalc(T const &cf) :
			cavalliFiscali(cf) {
	}

	template<typename S> T calcoloBollo(S c) {
		return c->potenza * cavalliFiscali * fattoreCorrettivo;
	}
};

#endif /* TAXCALC_H_ */
