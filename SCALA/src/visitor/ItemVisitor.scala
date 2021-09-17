package visitor
import cars._

abstract class ItemVisitor[T] extends ItemVisitorIF[T] {
  def visit(item: FFcar): T;
  def visit(item: Ecar): T;
  def visit(item: Hcar): T;
}

class Information extends ItemVisitor[Double] {
  def visit(item: FFcar): Double = {
    (math floor item.capacitaSerbatoio * item.getConsumi("Combinato") * 100) / 100
  }

  def visit(item: Ecar): Double = {
    (math floor item.capacitaBatteria / (item.getPotenza * 0.006) * 100) / 100
  }

  def visit(item: Hcar): Double = {
    (math floor (item.capacitaBatteria * 1000) / (item.standards(0) * 15) * 100) / 100
  }
}