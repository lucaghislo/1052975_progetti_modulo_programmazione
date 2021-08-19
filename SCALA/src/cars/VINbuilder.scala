/*
 * VINbuilder.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe che permette la creazione del numero di telaio delle
 * automobili. Per mantenere il prefisso statico, si definisce un
 * companion object con lo stesso nome della classe compagna
 *
 */

package cars

/*
 * Definizione del companion object associato alla classe VINbuilder
 * allo scopo di mantenere prefix come campo statico (assente in Scala)
 *
 * Oggetto Singleton
 *
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
   * della classe
   */
  def buildVIN: String = {
    var str_prefix = prefix.toString()
    var length = str_prefix.length()

    if (length > 10)
      throw new Exception("Errore")

    increasePrefix
    str_prefix + "X" * (10 - length)
  }
}