/*
 * Garage.scala
 * package mngmt
 * Author: Luca Ghislotti
 *
 * Oggetto Garage funge da singleton (assume il medesimo ruolo
 * del Design Pattern "singleton" implementato in C++) come strumento
 * per la gestione della flotta di auto, con i relativi metodi associati
 *
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
   * ListBuffer è realizzata internamente come una lista concatenata
   */
  val flotta = ListBuffer.empty[Car]

  // Richiesta all'utente
  print("Targa: ")
  val targa = scala.io.StdIn.readLine()
  println("Potenza: ")
  val potenza = scala.io.StdIn.readInt()
  println("Peso: ")
  val peso = scala.io.StdIn.readInt()
  println("carType: ")
  val carType = scala.io.StdIn.readInt()

  carType match {
    // FFcar
    case 0 => {
      println("Capacità serbatoio: ")
      val fuelCap = scala.io.StdIn.readInt()
      println("Consumo urbano: ")
      val urbano = scala.io.StdIn.readDouble()
      println("Consumo combinato: ")
      val combi = scala.io.StdIn.readDouble()
      println("Consumo extra-urbano: ")
      val extra = scala.io.StdIn.readDouble()

      flotta += new FFcar(targa, potenza, peso, fuelCap, urbano, combi, extra)

      println("Creata auto tradizionale")
    }

    // Ecar
    case 1 => {
      flotta += new Ecar(targa, potenza, peso)

      println("Creata auto elettrica")
    }

    // Hcar
    case 2 => {
      println("Capacità serbatoio: ")
      val fuelCap: Int = scala.io.StdIn.readInt()
      println("Consumo urbano: ")
      val urbano: Double = scala.io.StdIn.readDouble()
      println("Consumo combinato: ")
      val combi: Double = scala.io.StdIn.readDouble()
      println("Consumo extra-urbano: ")
      val extra: Double = scala.io.StdIn.readDouble()
      println("Standard 1: ")
      val s1: Int = scala.io.StdIn.readInt()
      println("Standard 2: ")
      val s2: Int = scala.io.StdIn.readInt()
      println("Standard 3: ")
      val s3: Int = scala.io.StdIn.readInt()

      flotta += new Hcar(targa = targa, potenza = potenza, peso = peso,
        capacitaSerbatoio = fuelCap, inputStandards = ArrayBuffer(s1, s2, s3),
        urbano = urbano, combi = combi, extra = extra)

      println("Creata auto ibrida")
    }
  }
}