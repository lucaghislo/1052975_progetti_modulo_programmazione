/*
 * Hcar.h
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef HCAR_H_
#define HCAR_H_
#include "Ecar.h"
#include "FFcar.h"

// : public Ecar, public FFcar
class Hcar {
public:
	Hcar();
private:
	short capacitaCombinata;
};

#endif /* HCAR_H_ */
