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

abstract class Car(var targa: String, var potenza: Int, var peso: Int) extends VINbuilder {
  // Numero di telaio definito internamente con valore di default
  private var numTelaio: String = "XXXXXXXXXX"

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
  def getTarga: String = targa
  def getNumTelaio: String = numTelaio
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