package usage
import cars._

object Main {
  def main(args: Array[String]): Unit = {
    var ec1: Car = new Ecar("ZA-044-ZB", 56, 9)
    ec1.showInfo()
    var ec2: Ecar = new Ecar("AZ-655-CR", 32, 6)
    ec2.showInfo()
  }
}