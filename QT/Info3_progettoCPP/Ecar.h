/*
 * Ecar.h
 * Author: Luca Ghislotti
 *
 * Classe derivata da Car che rappresenta l'auto elettrica
 * (E: Electric)
 *
 */

#ifndef ECAR_H_
#define ECAR_H_

#include <vector>
#include "Car.h"

/*
* Classe che rappresenta un'auto elettrica. Deriva dalla
* classe base Car
*/
class Ecar: virtual public Car {
public:
   /*
    * Costruttori della classe derivata
    */
   Ecar(vector<int> standardInput);
   Ecar(char *targaInput, int pesoInput = 1500, int potenzaInput = 50);

   /*
    * Prefisso virtual permette di implementare polimorfismo run-time
    */
   virtual string showInfo();
   virtual string printResumee();
   short getCapBat(); // ottenimento capacità batteria
   void setBatCap(short batCap); // metodo per definizione capacità batteria

   virtual string getClassName();

   /*
    * Distruttore virtual della classe derivata permette invocazione del
    * distruttore della classe base
    */
   virtual ~Ecar();

private:
   short capacitaBatteria; // parametro specifico per le auto elettriche (kWh)
   vector<int> standards; // elenco degli standard di tensione per la ricarica (V)
};

#endif /* ECAR_H_ */
