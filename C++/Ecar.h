/*
 * Ecar.h
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef ECAR_H_
#define ECAR_H_
#include "Car.h"

/*
 * Classe che rappresenta un'auto elettrica. Deriva dalla
 */
class Ecar: virtual public Car {
public:
	Ecar();
private:
	short capacitaBatteria;
};

#endif /* ECAR_H_ */
