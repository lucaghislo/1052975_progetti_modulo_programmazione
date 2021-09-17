package visitor
import cars._

trait ItemVisitorIF[T] {
  def visit(item: FFcar): T;
  def visit(item: Ecar): T;
  def visit(item: Hcar): T;
}