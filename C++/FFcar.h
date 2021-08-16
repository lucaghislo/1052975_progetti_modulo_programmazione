/*
 * FFcar.h
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef FFCAR_H_
#define FFCAR_H_
#include "Car.h"

class FFcar: virtual public Car {
public:
	FFcar();
private:
	short capacitaSerbatoio;
};

#endif /* FFCAR_H_ */
