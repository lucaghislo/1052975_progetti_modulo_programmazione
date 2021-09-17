/*
 ============================================================================
 Name        : Hcar.scala
 Package     : package cars
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Classe Hcar ottenuta come sottoclasse dalla superclasse
               Car, definita come interfaccia (Scala trait)
 ============================================================================
 */

package cars
import scala.collection.mutable._
import visitor._

/*
 * In Scala, come in Java, non � permessa ereditariet� multipla.
 * Ho peranto esteso la classe Ecar e, non potendo estendere anche la
 * classe FFcar (come invece fatto in C++) ho aggiunto i campi mancanti
 */
class Hcar(targa: String, potenza: Int = 110, peso: Int = 1500, capBatteria: Int = 400,
  var capacitaSerbatoio: Int = 50, inputStandards: ArrayBuffer[Int] = ArrayBuffer(110, 220),
  urbano: Double = 1.4, combi: Double = 2.3, extra: Double = 1.9)
  extends Ecar(targa, potenza, peso, capBatteria, inputStandards) {

  /*
   * Creazione mappa per effettuare l'associazione tra
   * la denonminazione del consumo ed il valore vero e proprio
   */
  val consumi = Map(
    "   Urbano" -> urbano,
    "Combinato" -> combi,
    "    Extra" -> extra)

  /*
   * Metodi getter e setter per il campo
   * capacitaSerbatoio
   */
  def getCapSerb: Int = capacitaSerbatoio // getter
  def setCapSerb(newCapSer: Int) = capacitaSerbatoio = newCapSer // setter

  override def showInfo {
    /*
     * Funzione innestata per effettuare la stampa dei consumi
     * La mappa viene iterata tramite ciclo foreach restituendo
     * la coppia <denominazione, consumo>
     */
    def printResumee {
      consumi.foreach {
        case (denominazione, valore) => println(s"$denominazione:  $valore L/100km")
      }
    }

    print("\nPETROL AND ")
    super.showInfo() // utilizzo del costrutto super per richiamare il metodo della superclasse
    println("Cap. Ser.:  " + getCapSerb + " L")
    printResumee
  }
}