/*
 * Hcar.h
 *
 * Auto ibrida (H: Hybrid) � sia un'auto FFcar (Fossile Fuel) che
 * un'auto Ecar (E: electric). Questa classe dimostra i concetti
 * di ereditariet� multipla ed i problemi che ne derivano, come
 * il name clashing
 *
 *  Created on: 16 ago 2021
 *      Author: Luca Ghislotti
 */

#ifndef HCAR_H_
#define HCAR_H_
#include "Ecar.h"
#include "FFcar.h"

/*
 * Risolvo il problema della member duplication sfruttando il
 * problema del diamante, dichiarando Car come classe base
 * virtual sia per Ecar che per FFcar
 */
class Hcar: public Ecar, public FFcar {
public:
	Hcar(char *targaInput, int pesoInput, int potenzaInput, short capInput,
			double urbano, double combinato, double extra,
			vector<int> standardsInput);

	/*
	 * Prefisso virtual permette di implementare polimorfismo run-time
	 */
	virtual void showInfo();
	virtual void printResumee();

	virtual string getClassName();

	/*
	 * Distruttore virtual della classe derivata permette invocazione del
	 * distruttore della classe base
	 */
	virtual ~Hcar();

private:
	unsigned short capacitaCombinata; // autonomia auto ibrida

protected:

};

#endif /* HCAR_H_ */
