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

class Ecar(targa: String, potenza: Int, peso: Int) extends AbstractCar with VINbuilder {
  setNumTelaio(buildVIN(getPrefix))
}