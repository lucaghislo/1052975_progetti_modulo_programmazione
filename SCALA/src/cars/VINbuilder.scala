/*
 * CarFunctions.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Interfaccia (Scala trait) che definisce le funzioni
 * della classe Car dalla quale derivano le sottoclassi
 * Ecar, FFcar, Hcar
 *
 */

package cars

/*
 * Un trait, al contrario di un'interfaccia Java, permette l'implementazione
 * di metodi, garantendo una maggiore flessibilità
 */
trait VINbuilder {
  /*
   * Funzione per la creazione del numero di telaio all'istanziazione
   * della classe, con parametro passato by-name
   * Da notare la possibilità di implementazione del metodo nel trait
   * (corrispettivo dell'interfaccia Java)
   */
  def buildVIN(prefix: => Int): String = {
    var str_prefix = prefix.toString()
    var length = str_prefix.length()

    if (length > 10)
      throw new ArithmeticException("Raggiunto limite immatricolazioni")

    str_prefix + "X" * (10 - length)
  }
}