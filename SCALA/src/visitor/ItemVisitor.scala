package visitor
import cars._

/*
 * Classe astratta associata ai metodi visitor
 */
abstract class ItemVisitor[T] extends ItemVisitorIF[T] {
  def visit(item: FFcar): T;
  def visit(item: Ecar): T;
  def visit(item: Hcar): T;
}

/*
 * Classe concreta visitor per ottenere informazioni inerenti le auto
 */
class Information extends ItemVisitor[Double] {

  /*
   * Calcolo autonomia veicolo tradizionale sulla base della
   * capacità del serbatoio e del consumo combinato
   * (arrotondamento a due cifre decimali)
   *
   * (autonomia [Km]) = (cap. serbatoio [l]) * (100/consumo [l/100Km])
   */
  def visit(item: FFcar): Double = {
    (math floor item.capacitaSerbatoio * (100 / item.getConsumi("Combinato")) * 100) / 100
  }

  /*
   * Calcolo autonomia veicolo elettrico sulla base della capacità
   * della batteria e della potenza (ipotizzando un utilizzo medio del
   * 10% della potenza disponibile ed una velocità media di 60 Km/h)
   *
   * (autonomia [Km]) = ((cap. batteria [Kwh]) / (potenza [Kw]) * 0.1) * (vel. media [Km/h])
   */
  def visit(item: Ecar): Double = {
    (math floor (item.capacitaBatteria / (item.getPotenza * 0.1)) * 60 * 100) / 100
  }

  /*
   * Autonomia complessiva dell'auto ibrida calcolata come la somma dei
   * due precedenti contributi
   */
  def visit(item: Hcar): Double = {
    (math floor (item.capacitaSerbatoio * item.consumi("Combinato") +
      (item.capacitaBatteria / (item.getPotenza * 0.1)) * 60) * 100) / 100
  }
}