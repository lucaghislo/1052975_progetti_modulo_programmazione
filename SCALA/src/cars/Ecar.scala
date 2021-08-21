/*
 ============================================================================
 Name        : Ecar.scala
 Package     : package cars
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Classe Ecar ottenuta come sottoclasse dalla superclasse
               Car definita come classe astratta
 ============================================================================
 */

package cars
import scala.collection.mutable._

/*
 * Definizione sottoclasse di Car
 * Da notare il valore di default per il parametro capacitaBatteria
 * nel caso in cui non venga indicato in fase di istanziazione
 * (parametro opzionale impostato di default a 400)
 */
class Ecar(targa: String, potenza: Int, peso: Int, var capacitaBatteria: Int = 400, inputStandards: ArrayBuffer[Int]) extends Car(targa, potenza, peso) {
  /*
   * Lista degli standard di ricarica implementata tramite
   * collezione mutable ListBuffer passata come parametro al
   * costruttore
   */
  var standards = ArrayBuffer.empty[Int]
  standards = inputStandards

  /*
   * Metodi getter e setter per il campo
   * capacitaBatteria
   */
  def getCapBat: Int = capacitaBatteria // getter
  def setCapBat(newCapBat: Int) = capacitaBatteria = newCapBat // setter

  /*
   * Overload del costruttore in Scala tramite
   * utilizzo del costruttore ausiliario
   *
   * Costruttore ausiliario pone a valori di default
   * gli standard di ricarica senza che vengano definiti dall'utente
   *
   */
  def this(targa: String, potenza: Int, peso: Int) {
    this(targa, potenza, peso, 400, ArrayBuffer(110, 230, 380))
  }

  /*
   * Funzione data in input a showInfo()
   * Ha come parametro il numero di spazi, posto di default a 1
   */
  def getArrayBufferContent(numSpaces: Int = 1): String = {
    var output: String = "";

    for (i <- standards)
      output = output + i + " " * numSpaces

    /*
     * Esempio di come in Scala venga ritornata l'ultima espressione
     * senza usare la clausola "return"
     */
    output + "Piero non viene ritornato"
    output
  }

  /*
   * Funzione che permette la visualizzazione degli standard di ricarica,
   * utilzzata nella funzione showInfo
   *
   *
   * Esempio di utilizzo di HOF (Higher Order Function)
   * Viene passata come parametro la funzione di stampa del vettore
   */
  def printResumee(getArrayBufferContent: Int => String) {
    print("Standards:  ")
    print(getArrayBufferContent(2))
    print("V")
  }

  /*
   * Metodo per la visualizzazione delle informazioni
   * dell'auto elettrica (Ecar)
   *
   * Da notare la clausola "override" che permette di ridefinire
   * il medesimo metodo della superclasse
   */
  override def showInfo {
    print("ELECTRIC ")
    super.showInfo()
    println("Batt. cap:  " + this.getCapBat + " KWh")
    this.printResumee(getArrayBufferContent)
    println("")
  }
}