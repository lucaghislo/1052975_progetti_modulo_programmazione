/*
 * main.cpp
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#include <iostream>
#include "Garage.h"
#include <cstring>
using namespace std;

#include "Car.h"

int main() {
	Car *c1 = new Car();
	Car *c2 = new Car();

	char *targa = (char*) malloc(sizeof("ZA-044-ZB"));
	strcpy(targa, "ZA-044-ZB");
	//Car* c3 = new Car(targa);
	Car *c4 = new Car(targa, 1350, 170);

	cout << "Targa auto c1: " << c1->getTarga() << endl;
	c1->setTarga("AZ-655-CR");
	cout << "Targa auto c1: " << c1->getTarga() << endl;

	Car *c5(c4);
	cout << "Targa auto c5: " << c1->getTarga() << endl;

	Car *c6(c5);
	cout << "Targa auto c6: " << c1->getTarga() << endl;
}

