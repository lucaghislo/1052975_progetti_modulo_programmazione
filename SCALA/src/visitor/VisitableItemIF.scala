package visitor

/*
 * Interfaccia oggetto visitable
 */
trait VisitableItemIF {
  def accept[T](visitor: ItemVisitor[T]): T;
}