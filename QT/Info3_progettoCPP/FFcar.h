/*
 * FFcar.h
 * Author: Luca Ghislotti
 *
 * Classe derivata da Car che rappresenta l'auto a combustibile
 * fossile (FF: Fossile Fuel)
 *
 */

#ifndef FFCAR_H_
#define FFCAR_H_

#include <map>
#include <string>
#include "Car.h"

class FFcar: virtual public Car {
public:
    /*
     * Costruttore della classe derivata che sfrutta il costruttore
     * della classe base
     */
    FFcar(char *targaInput, int pesoInput, int potenzaInput, short fuelCapacity,
            double urbano, double combi, double extra);

    /*
     * Prefisso virtual permette di implementare polimorfismo run-time
     */
    virtual string showInfo();
    virtual string printResumee();
    short getCapSerb(); // ottenimento capacità serbatoio combustibile

    virtual string getClassName();

    /*
     * Distruttore virtual della classe derivata permette invocazione del
     * distruttore della classe base
     */
    virtual ~FFcar();

private:
    short capacitaSerbatoio; // capacità serbatoio auto tradizionale

    /*
     * STL map per memorizzare i consumi medi in varie modalità di guida
     */
    map<string, double> consumi;
};

#endif /* FFCAR_H_ */
