package visitor

trait VisitableItemIF {
  def accept[T](visitor: ItemVisitor[T]): T;
}