/*
 * Ecar.h
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe Ecar ottenuta come sottoclasse dalla superclasse
 * Car, definita come interfaccia (Scala trait)
 *
 */

package cars

class Ecar(targa: String, potenza: Int, peso: Int) extends Car(targa, potenza, peso) {
  setNumTelaio(buildVIN)
}