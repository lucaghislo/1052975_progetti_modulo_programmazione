/*
 * Car.cpp
 * Author: Luca Ghislotti
 *
 * File di implementazione dei metodi della classe Car
 *
 */

#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include<sstream>
#include "Car.h"

/*
 * Variabile statica della classe Car, comune a tutte le istanze della classe
 * (essendo classe astratta la variabile, rappresentante il prefisso del numero di telaio
 * dell'auto, sarà valore comune a tutte le istante delle classi derivate della classe Auto)
 */
unsigned int Car::prefix = 0;
/*
 * Primo costruttore senza parametri che inizializza l'auto con valori generici,
 * come nel caso in cui auto venga creata senza essere immatricolata
 */
Car::Car() {
    // Allocazione area di memoria su heap per salvataggio targa
    targa = (char*) malloc(sizeof(char) * 9);
    strcpy(targa, "XX-XXX-XX"); // targa generica pre-immatricolazione

    try {
        Car::buildVIN(prefix);
    } catch (int x) {
        cout << "Errore creazione auto: threshold superata" << endl;
    }

    // Allocazione area di memoria su heap per salvataggio numero di telaio
    numTelaio = (char*) malloc(sizeof(char) * 10);
    strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-costruzione

    potenza = minPotenza; // auto pre-immatricolata ha potenza di default

    peso = 1000;

    /*
     * Incremento del prefisso dopo la creazione dell'auto
     */
    Car::increasePrefix();
}

/*
 * Costruttore della classe con parametri targa e potenza che
 * sfrutta la member initializer list
 */
Car::Car(char *targaInput, int pesoInput, int potenzaInput) :
        peso(pesoInput), potenza(potenzaInput) {
    // Allocazione area di memoria su heap per salvataggio targa
    targa = (char*) malloc(sizeof(char) * 9);
    strcpy(targa, targaInput); // targa definita da parametro

    try {
        Car::buildVIN(prefix);
    } catch (int x) {
        cout << "Errore creazione auto: threshold superata" << endl;
    }

    // Allocazione area di memoria su heap per salvataggio numero di telaio
    numTelaio = (char*) malloc(sizeof(char) * 10);
    strcpy(numTelaio, buildVIN(prefix)); // VIN generico pre-costruzione

    /*
     * Incremento del prefisso dopo la creazione dell'auto
     */
    Car::increasePrefix();
}

/*
 * Implementazione del copy-constructor
 */
Car::Car(const Car &newCar) {
    strcpy(targa, newCar.targa);
    strcpy(numTelaio, newCar.numTelaio);
    Car::potenza = newCar.potenza;
    Car::peso = newCar.peso;
}

void Car::increasePrefix() {
    Car::prefix++;
}

char* Car::buildVIN(int prefix) {
    string str_prefix = to_string(prefix);
    int length = str_prefix.length();
    char *VIN = (char*) malloc(sizeof(char) * 10);
    strcpy(VIN, str_prefix.data());

    if (length > 10) {
        delete VIN;
        throw 403; // error code nel caso venga superato il limite di immatricolazioni
    } else {
        // costruzione VIN generico con prefisso
        for (int i = 0; i < 10 - length; i++) {
            strcat(VIN, "X");
        }
    }

    return VIN;
}

char* Car::getTarga() {
    return Car::targa;
}

char* Car::getVIN() {
    return Car::numTelaio;
}

short Car::getPotenza() {
    return Car::potenza;
}

short Car::getPeso() {
    return Car::peso;
}

void Car::setTarga(string newTarga) {
    if (newTarga.length() > 9)
        throw 403;
    else
        strcpy(targa, newTarga.data());
}

string Car::showInfo() {
    string targa = getTarga();
    string VIN = getVIN();
    string potenza = std::to_string(getPotenza());
    string peso = std::to_string(getPeso());
    return "CAR DATA SUMMARY\n        Targa:  " + targa + "\n           VIN:  " + VIN + "\n   Potenza:  " + potenza + " kW\n         Peso:  " +peso + " kg\n";
}

/*
 * Metodo distruttore della classe Car
 *
 */
Car::~Car() {
    delete targa; // deallocazione della targa da heap
    delete numTelaio; // deallocazione del numero di telaio da heap
    cout << "cleared all cars" << endl;
}
