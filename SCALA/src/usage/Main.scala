package usage
import scala.collection.mutable._
import cars._
import mngmt._

object Main {
  def main(args: Array[String]): Unit = {
    /*
     * try {
      var ec1: Car = new FFcar("ZA-044-ZB", 56, 40)
      ec1.showInfo()

      var ec2: Ecar = new Ecar("AZ-655-CR", 32, 6)
      ec2.showInfo()

      var ec3: Hcar = new Hcar("AZ-655-CR")
      ec3.showInfo()

    } catch {
      case _: Throwable => println("\nErrore formato targa")
    }
    *
    */

    var i: Int = 0
    while (true) {
      try {
        Garage.newAuto(i)
        Garage.stampaFlotta
        i = i + 1
      } catch {
        case _: Throwable => println("\nErrore formato targa")
      }
    }
  }
}