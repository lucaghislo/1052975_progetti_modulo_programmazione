package usage
import scala.collection.mutable._
import cars._
import mngmt._

object Main {
  def main(args: Array[String]): Unit = {

    /*
	 * All'utente viene richiesto ad inoltranza di inserire auto:
	 * alla creazione, vengono inserite in un vector di cui viene restuito
	 * lo smart pointer all'istanza di Car (una delle sue classi derivate) e
	 * vengono stampate le informazioni associate all'intera flotta tramite
	 * la funzione stampaFlott() che sfrutta showInfo() specializzata
	 * per ciascun tipo di auto
	 */
    var i: Int = 0
    while (true) {
      try {
        Garage.newAuto(i)
        Garage.stampaFlotta
        i = i + 1

        println("\n    Peso totale:  " + FleetStats.pesoTotale(Garage.flotta) + " Kg")
        println("Massima potenza:  " + FleetStats.maxPotenza(Garage.flotta) + " KW")
      } catch {
        case _: Throwable => println("\nErrore formato targa")
      }
    }
  }
}