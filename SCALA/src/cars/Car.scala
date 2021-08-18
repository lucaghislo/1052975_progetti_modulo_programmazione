/*
 * Car.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Interfaccia (Scala trait) che definisce la classe Car dalla
 * quale derivano le sottoclassi Ecar, FFcar, Hcar
 *
 */

package cars

/*
 * Un trait, al contrario di un'interfaccia Java, permette l'implementazione
 * di metodi, garantendo una maggiore flessibilità
 */
trait Car {
  var targa: String
  
}