package usage
import cars._

object Main {
  def main(args: Array[String]): Unit = {
    var ec1: AbstractCar = new Ecar("ZA-044-ZB", 10, 10)
    println(ec1.getPeso)
  }
}