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
 * Definizione del companion object associato alla classe VINbuilder
 * allo scopo di mantenere prefix come campo statico (assente in Scala)
 */
object VINBuilder {
  var prefix = 0
  def increasePrefix = {
    prefix += 1;
  }
}

class VINbuilder {
  import VINBuilder._
  /*
   * Funzione per la creazione del numero di telaio all'istanziazione
   * della classe, con parametro passato by-name
   */
  def buildVIN: String = {
    var str_prefix = prefix.toString()
    var length = str_prefix.length()

    if (length > 10)
      throw new ArithmeticException("Raggiunto limite immatricolazioni")

    increasePrefix
    str_prefix + "X" * (10 - length)
  }
}