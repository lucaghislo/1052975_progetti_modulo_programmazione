/*
 ============================================================================
 Name        : Garage.scala
 Package     : package mngmt
 Author      : Luca Ghislotti
 Version     : 1.0
 Copyright   : MIT License
 Description : Oggetto Garage funge da singleton (assume il medesimo ruolo
               del Design Pattern "singleton" implementato in C++) come
               strumento per la gestione della flotta di auto, con i 
               relativi metodi associati
 ============================================================================
 */

package mngmt
import cars._
import scala.io.StdIn._
import scala.collection.mutable._

/*
 * Oggetto visto come Singleton
 */
object Garage {

  /*
   * Flotta di auto come Collezione mutable ListBuffer
   * ListBuffer � realizzata internamente come una lista concatenata
   */
  val flotta = ListBuffer.empty[Car]

  /*
   * Metodo per la creazione di una nuova auto
   */
  def newAuto(Iteration: => Int) {
    // Richiesta all'utente
    if (Iteration == 0) print("Targa: ") else print("\nTarga: ")
      
    val targa = scala.io.StdIn.readLine()
    print("Potenza: ")
    val potenza = scala.io.StdIn.readInt()
    print("Peso: ")
    val peso = scala.io.StdIn.readInt()
    print("carType: ")
    val carType = scala.io.StdIn.readInt()

    carType match {
      // FFcar
      case 0 => {
        print("Capacita serbatoio: ")
        val fuelCap = scala.io.StdIn.readInt()
        print("Consumo urbano: ")
        val urbano = scala.io.StdIn.readDouble()
        print("Consumo combinato: ")
        val combi = scala.io.StdIn.readDouble()
        print("Consumo extra-urbano: ")
        val extra = scala.io.StdIn.readDouble()

        flotta += new FFcar(targa, potenza, peso, fuelCap, urbano, combi, extra)

        println("Creata auto tradizionale\n")
      }

      // Ecar
      case 1 => {
        flotta += new Ecar(targa, potenza, peso)

        println("Creata auto elettrica\n")
      }

      // Hcar
      case 2 => {
        print("Capacita serbatoio: ")
        val fuelCap: Int = scala.io.StdIn.readInt()
        print("Consumo urbano: ")
        val urbano: Double = scala.io.StdIn.readDouble()
        print("Consumo combinato: ")
        val combi: Double = scala.io.StdIn.readDouble()
        print("Consumo extra-urbano: ")
        val extra: Double = scala.io.StdIn.readDouble()
        print("Standard 1: ")
        val s1: Int = scala.io.StdIn.readInt()
        print("Standard 2: ")
        val s2: Int = scala.io.StdIn.readInt()
        print("Standard 3: ")
        val s3: Int = scala.io.StdIn.readInt()

        flotta += new Hcar(targa = targa, potenza = potenza, peso = peso,
          capacitaSerbatoio = fuelCap, inputStandards = ArrayBuffer(s1, s2, s3),
          urbano = urbano, combi = combi, extra = extra)

        println("Creata auto ibrida\n")
      }
    }
  }

  /*
   * Metodo per la stampa della flotta di auto
   */
  def stampaFlotta {
    println("***AUTO NELLA FLOTTA***")
    flotta.foreach {
      case(car) => car.showInfo()
    }
  }
}