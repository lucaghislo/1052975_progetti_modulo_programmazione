/*
 * Hcar.hpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef HCAR_H_
#define HCAR_H_
#include "Ecar.h"
#include "FFcar.h"

class Hcar: public Ecar, public FFcar {
public:
	Hcar();
private:
	short capacitaCombinata;
};

#endif /* HCAR_H_ */
