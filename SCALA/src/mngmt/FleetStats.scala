/*
 * FleetStats.scala
 * package mngmt
 * Author: Luca Ghislotti
 *
 * Oggetto FleetStats (Singleton) ha lo scopo di effettuare
 * calcoli sulla flotta auto sfruttando i paradigmi
 * Filter, Map, Reduce e Fold
 *
 * Esempio di Functional Programming in Scala
 *
 */

package mngmt
import scala.collection.mutable._
import cars._

object FleetStats {
  /*
   * Metodo che sfrutta l'operatore foldLeft() tramite il quale
   * viene ritornato il peso totale dei veicoli nella flotta
   */
  def pesoTotale(flotta: ListBuffer[Car]): Int = {

    /*
     * Applico foldLeft al ListBuffer flotta utilizzando come
     * valore di inizializzazione lo 0
     */
    flotta.foldLeft(0)((pesoTotale, veicolo) => pesoTotale + veicolo.getPeso)
  }

  /*
   * Metodo che sfrutta l'operatore foldRight tramite il quale
   * viene ritornata la potenza massima tra i veicoli nella flotta
   */
  def maxPotenza(flotta: ListBuffer[Car]): Int = {

    /*
     * Applico foldRight, identico all'operatore foldLeft se non
     * per il fatto che la sequenza viene fatta scorrere da destra
     * verso sinistra
     */
    flotta.foldRight(flotta.head.getPotenza)((veicolo, temp) => temp max veicolo.getPotenza)
  }

  /*
   * Funzione che effettua il calcolo del consumo medio di una FFcar
   * sfruttando il paradigma reduce di Scala
   */
  def consumoMedio(veicolo: FFcar): Double = {

    /*
     * Funzione innestata che permette di ottenere una lista
     * dal secondo campo della Map consumi di FFcar
     */
    def getListFromMap(veicolo: FFcar): MutableList[Double] = {
      var listaConsumi = MutableList[Double]()

      veicolo.getConsumi.foreach {
        case (denominazione, valore) => listaConsumi += valore
      }

      listaConsumi // restituita una MutableList
    }

    val lista = getListFromMap(veicolo)

    // Calcolo consumo medio
    lista.reduce((a, b) => a + b) / lista.length
  }
}