package usage
import cars._

object Main {
  def main(args: Array[String]): Unit = {
    try {
      var ec1: Car = new FFcar("ZA-044-ZB", 56, 40)
      ec1.showInfo()
      var ec2: Ecar = new Ecar("AZ-655-CRRRRRR", 32, 6)
      ec2.showInfo()
      ec2.getTarga
    } catch {
      case _: Throwable => println("\nErrore formato targa")
    }
  }
}