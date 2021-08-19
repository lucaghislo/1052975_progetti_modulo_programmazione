/*
 * FleetStatsTrait.scala
 * package mngmt
 * Author: Luca Ghislotti
 *
 * Interfaccia (Scala Trait) che contiene tutti i metodi
 * implementati dall'oggetto Singleton FleetStats
 *
 */

package mngmt
import scala.collection.mutable._
import cars._

trait FleetStatsTrait {
  /*
   * Metodo che sfrutta l'operatore foldLeft() tramite il quale
   * viene ritornato il peso totale dei veicoli nella flotta
   */
  def pesoTotale(flotta: ListBuffer[Car]): Int
  
  /*
   * Metodo che sfrutta l'operatore foldRight tramite il quale
   * viene ritornata la potenza massima tra i veicoli nella flotta
   */
  def maxPotenza(flotta: ListBuffer[Car]): Int
  
  /*
   * Funzione che effettua il calcolo del consumo medio di una FFcar
   * sfruttando il paradigma reduce di Scala
   */
  def consumoMedio(veicolo: FFcar): Double
  
  /*
   * Metodo che permette di ottenere una lista delle auto che
   * devono pagare il superbollo (potenza > 183kW)
   *
   * Il metodo sfrutta il costrutto filter
   */
  def autoSuperbollo(flotta: ListBuffer[Car]): ListBuffer[Car]
  
  /*
   * Metodo che calcola la potenza massima in CV sfruttando:
   * - Map: per mappare i kW in CV
   * - Reduce: per cercare la massima potenza in CV
   */
  def MapReduce(flotta: ListBuffer[Car]): Int
}