/*
 ============================================================================
 Name        : Main.scala
 Package     : package usage
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : All'utente viene richiesto ad inoltranza di inserire auto:
	             alla creazione, vengono inserite in un ListBuffer e vengono 
	             stampate le informazioni associate all'intera flotta tramite 
	             la funzione stampaFlotta() che sfrutta showInfo() 
	             specializzata per ciascun tipo di auto
 ============================================================================
 */

package usage
import scala.collection.mutable._
import cars._
import mngmt._

object Main {
  def main(args: Array[String]): Unit = {
    var i: Int = 0
    while (true) {
      try {
        Garage.newAuto(i)
        Garage.stampaFlotta
        i += 1

        println("\n    Peso totale:  " + FleetStats.pesoTotale(Garage.flotta) + " Kg")
        println("Massima potenza:  " + FleetStats.maxPotenza(Garage.flotta) + " KW")
        println("Massima potenza:  " + FleetStats.MapReduce(Garage.flotta) + " CV")
      } catch {
        case _: Throwable => println("\nErrore formato targa")
      }
    }
  }
}