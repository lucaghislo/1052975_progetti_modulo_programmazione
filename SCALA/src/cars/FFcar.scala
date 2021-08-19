/*
 * FFcar.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe FFcar ottenuta come sottoclasse dalla superclasse
 * Car, definita come interfaccia (Scala trait)
 *
 */

package cars

/*
 * Sottoclasse costruita sfruttando il costruttore della superclasse Car,
 * a cui vengono aggiunti i campi specifici per le auto tradizionali
 */
class FFcar(targa: String, potenza: Int, peso: Int, var capacitaSerbatoio: Int = 50, urbano: Double = 4.5,
  combi: Double = 5.6, extra: Double = 7.3) extends Car(targa, potenza, peso) {
    
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

  /*
   * Funzione per effettuare la stampa dell'auto FFcar
   *
   * Da notare l'utilizzo di funzioni innestate: si costruisce
   * internamente una funzione per la stampa dei consumi
   *
   * Da notare la clausola "override" che permette di ridefinire
   * il medesimo metodo della superclasse
   */
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

    print("FOSSILE FUEL ")
    super.showInfo() // utilizzo del costrutto super per richiamare il metodo della superclasse
    println("Cap. Ser.:  " + getCapSerb + " L")
    printResumee
    println("")
  }
}