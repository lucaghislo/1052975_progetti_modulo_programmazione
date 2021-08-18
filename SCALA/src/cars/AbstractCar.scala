/*
 * AbstractCar.scala
 * package cars
 * Author: Luca Ghislotti
 *
 * Classe astratta che rappresenta il tipo Car ereditato
 * dalle sottoclassi Ecar, FFcar, Hcar
 *
 */

package cars

abstract class AbstractCar {
  // Definizione di Values, immutable
  private val _minPotenza = 30; // potenza minima (costante) per inizializzazione

  // Definizione di Variables, mutable
  private var numTelaio: String = "XXXXXXXXXX" // numero di telaio dell'automobile
  private var targa: String = "XX-XXX-XX" // targa dell'automobile
  private var potenza: Int = 0 // potenza dell'automobile
  private var peso: Int = 0 // peso dell'automobile

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
  def getTarga: String = targa
  def getTelaio: String = numTelaio
  def getPotenza: Int = potenza
  def getPeso: Int = peso
  def getPrefix: Int = prefix

  /*
   * Metodi setter per Car: da notare la sintassi
   * molto più snella rispetto a Java
   */
  def setTarga(newTarga: String) = targa = newTarga
  def setNumTelaio(newTelaio: String) = numTelaio = newTelaio
  def setPotenza(newPotenza: Int) = potenza = newPotenza
  def setPeso(newPeso: Int) = peso = newPeso

  /*
   * Funzione per incrementare il prefisso del telaio alla
   * creazione di un'automobile di qualsiasi tipo
   */
  def increasePrefix = prefix += 1

  /*
   * Metodo, overrided nelle sottoclassi, per la visualizzazione delle
   * informazioni associate all'automobile
   */
  def showInfo() = {
    println("CAR DATA SUMMARY")
    println("    Targa:  " + getTarga)
    println("      VIN:  " + getTarga)
    println("  Potenza:  " + getPotenza + " kW")
    println("     Peso:  " + getPeso + " kg")
  }
}