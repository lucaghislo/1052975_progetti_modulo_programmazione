/*
 * Car.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe astratta che rappresenta il tipo Car ereditato
 * dalle sottoclassi Ecar, FFcar, Hcar
 *
 */

package cars

/*
 * Classe astratta con campi privati che estende la
 * classe VINbuilder contenente i metodi per la creazione del
 * numero di telaio (uso del campo statico prefix)
 */
abstract class Car(private var targa: String, private var potenza: Int, private var peso: Int) extends VINbuilder {

  /*
   * Expression oriented programming
   *
   * Check di integrità della targa: se eccede il numero di caratteri,
   * viene sollevata un'eccezione intercettata al momento della costruzione
   */
  targa = if (targa.length() <= 9) targa else throw new Exception("Errore")

  // Numero di telaio definito internamente con valore di default
  private var numTelaio: String = "XXXXXXXXXX"
  
   /*
   * Blocco try-catch per intercettare eccezione
   * sollevata durante la creazione del VIN
   */
  try {
    /*
     * Inizializzazione del numero di telaio con prefisso
     * statico tramite metodo buildVIN
     */
    setNumTelaio(buildVIN)
  } catch {
    case _: Throwable => println("\nErrore: raggiunto limite immatricolazioni")
  }

  // Definizione di Values, immutable
  private val minPotenza = 30; // potenza minima (costante) per inizializzazione

  /*
   * Prefisso per inizializzazione del numero di telaio,
   * incrementato ad ogni istanziazione della classe allo scopo di rendere
   * univoco il numero di telaio
   */
  private var prefix: Int = 0

  /*
   * Metodi getter per Car: da notare la sintassi
   * molto più snella rispetto a Java
   */
  def getTarga = targa // esempio di type inference
  def getNumTelaio: String = numTelaio // tipo di ritorno esplicitato
  def getPotenza: Int = potenza
  def getPeso: Int = peso
  def getPrefix: Int = prefix

  /*
   * Metodi setter per Car: da notare la sintassi
   * molto più snella rispetto a Java
   */
  def setTarga(newTarga: String) = targa = newTarga // esempio di call-by-value
  def setNumTelaio(newTelaio: => String) = numTelaio = newTelaio // esempio di call-by-name
  def setPotenza(newPotenza: Int) = potenza = newPotenza
  def setPeso(newPeso: Int) = peso = newPeso

  /*
   * Metodo, overrided nelle sottoclassi, per la visualizzazione delle
   * informazioni associate all'automobile
   */
  def showInfo() = {
    println("CAR DATA SUMMARY")
    println("    Targa:  " + getTarga)
    println("      VIN:  " + getNumTelaio)
    println("  Potenza:  " + getPotenza + " kW")
    println("     Peso:  " + getPeso + " kg")
  }
}