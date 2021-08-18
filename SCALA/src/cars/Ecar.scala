/*
 * Ecar.h
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe Ecar ottenuta come sottoclasse dalla superclasse
 * Car definita come classe astratta
 *
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
   * Inizializzazione del numero di telaio con prefisso
   * statico tramite metodo buildVIN
   */
  setNumTelaio(buildVIN)

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
   * Costruttore ausiliario che pone a valori di default
   * gli standard di ricarica senza che vengano definiti dall'utente
   *
   */
  def this(targa: String, potenza: Int, peso: Int) {
    this(targa, potenza, peso, 400, ArrayBuffer(110, 230, 380))
  }

  /*
   * Funzione che permette la visualizzazione degli standard di ricarica,
   * utilzzata nella funzione showInfo
   */
  def printResumee {
    print("Standards:  ")
    for (i <- standards)
      print(i + " ")
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
    print("\nELECTRIC ")
    super.showInfo()
    println("Batt. cap:  " + this.getCapBat + " KWh")
    this.printResumee
    println("")
  }
}