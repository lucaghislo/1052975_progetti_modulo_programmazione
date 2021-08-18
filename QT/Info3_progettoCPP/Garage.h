/*
 * Garage.h
 * Author: Luca Ghislotti
 *
 * Classe Garage permette di utilizzare le auto e gestirle
 *
 */

#ifndef GARAGE_H_
#define GARAGE_H_
#include <vector>
#include <memory>
#include "Car.h"

/*
 * Implemento la classe Garage sfruttando il design pattern
 * singleton, allo scopo di garantire che non vi sia più di
 * un'istanza di questa classe (evito r)
 */
class Garage {
public:
    static Garage& getInstance() {
        static Garage instance; // Garantita la distruzione dell'istanza
        // Instanziazione al primo uso
        return instance;
    }

    /*
     * Utilizzo dei puntatori smart: creo funzione che restituisce
     * smart pointer ad auto creata ed inserita in un STL vector
     * di smart pointers
     */
    void newAuto();

    /*
     * Funzione che, dato in input un raw pointer, restiuisce un bool
     * che rappresenta il fatto che l'auto passata come parametro sia
     * elettrica (quindi ibrida o elettrica) oppure no
     */
    bool isElectric(Car *c);

    /*
     * Funzione per il print delle informazioni di un'auto
     */
    void stampaInfoAuto(Car &c) const;

    /*
     * Funzione per il print dell'intero STL vector flotta del garage
     */
    string stampaFlotta();

    /*
     * Esempio di funzione inline che restituisce il numero di auto
     * nella flotta
     */
    inline short countAuto() {
        return flotta.size();
    }

    /*
     * STL vector di unique_ptr ognuno dei quali punta alle auto
     * presenti nella flotta
     */
    vector<unique_ptr<Car>> flotta;

private:
    // Costruttore vuoto della classe Garage
    Garage();

    // Copy constructor della classe Garage
    Garage(Garage const&);
};

#endif /* GARAGE_H_ */
