/*
 * main.cpp
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
#include "TaxCalc.h"

int main() {
	/*
	 * Car *c1 = new Car();
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
	 */

	vector<int> myStandards = { 180, 260, 420 };
	Ecar *ec1 = new Ecar(myStandards);
	cout << "Targa auto elettrica ec1: " << ec1->getTarga() << endl;
	try {
		ec1->setTarga("EL-101-LEEEEEEEEE");
	} catch (int x) {
		cout << "Formato targa errato! Cannot update" << endl;
	}
	cout << "Targa auto elettrica ec1: " << ec1->getTarga() << endl;
	ec1->showInfo();

	FFcar *ffc1 = new FFcar("ZA-044-ZB", 1200, 149, 50, 4.5, 5.5, 8.9);
	cout << "Targa auto tradizionale ffc1: " << ffc1->getTarga() << endl;
	try {
		ffc1->setTarga("EL-101-LE");
	} catch (int x) {
		cout << "Formato targa errato! Cannot update" << endl;
	}
	cout << "Targa auto elettrica ffc1: " << ec1->getTarga() << endl;
	ffc1->showInfo();

	TaxCalc<double> tc(5.3);
	cout << tc.calcoloBollo(ffc1) << endl;
}
