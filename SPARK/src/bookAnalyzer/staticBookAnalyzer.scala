package bookAnalyzer

import org.apache.spark._
import org.apache.spark.rdd.RDD
import scala.collection.mutable._
import scala.io.StdIn._

object bookAnalyzer {

  /*
   * Configurazione ed istanziazione ambiente Spark
   */
  def configSpark(name: String, masterName: String) = {

    /*
     * Configurazione dell'ambiente Spark
     *
     * Spark version 3.1.2
     * Spark web UI at http://LUCA-THINKPAD-P1.mshome.net:4041
     */
    val conf = new SparkConf().setAppName(name).setMaster(masterName)

    /*
     * Creazione dello Spark Context sulla base della configurazione e return
     */
    new SparkContext(conf)
  }

  /*
   * Lettura da file
   */
  def readFile(sc: SparkContext, path: String) = {
    sc.textFile(path)
  }

  /*
   * Dato in input un RDD[String] effettua il return di un
   * RDD[String] contenente le stringhe splittate in parole
   */
  def splitWords(file: RDD[String]) = {
    file.flatMap(line => line.split(" "))
  }

  /*
   * Conteggio complessivo delle parole
   */
  def countWords(words: RDD[String]) = {
    words.map((x: String) => 1).fold(0)(((sum: Int, x: Int) => sum + x))
  }

  /*
   * Conteggio complessivo dei caratteri (a meno degli spazi )
   */
  def countCharacters(words: RDD[String]) = {
    words.map((x: String) => x.length()).fold(0)(((sum: Int, x: Int) => sum + x))
  }

  def mostRecurringWord(words: RDD[String], sc: SparkContext) = {
    val wc = words.flatMap(l => l.split(" ")).map(word => (word, 1)).reduceByKey(_ + _)
    val wc_swap = wc.map(_.swap)
    val hifreq_words = wc_swap.sortByKey(false, 1)
    val top100rdd = sc.parallelize(hifreq_words.take(100))
    top100rdd.collect()(1).swap
  }

  def main(args: Array[String]) {
    val sc = configSpark("Book Stats with Spark", "local[1]")

    val divinaCommedia = readFile(sc, "inputFiles\\divinaCommedia.txt")
    val wordsDC = splitWords(divinaCommedia)
    val wordCountDC = countWords(wordsDC)
    val characterCountDC = countCharacters(wordsDC)
    val firstWordDC = mostRecurringWord(divinaCommedia, sc)

    val pridePrejudice = readFile(sc, "inputFiles\\prideAndPrejudice.txt")
    val wordsPP = splitWords(pridePrejudice)
    val wordCountPP = countWords(wordsPP)
    val characterCountPP = countCharacters(wordsPP)
    val firstWordPP = mostRecurringWord(pridePrejudice, sc)

    println("\n*** DIVINA COMMEDIA BY DANTE STATS ***")
    println("            #Parole: " + wordCountDC)
    println("         #Caratteri: " + characterCountDC)
    println("Most recurring word: \"" + firstWordDC._1 + "\" recurring " + firstWordDC._2 + " times")

    println("\n*** PRIDE AND PREJUDICE BY JANE AUSTEN STATS ***")
    println("            #Parole: " + wordCountPP)
    println("         #Caratteri: " + characterCountPP)
    println("Most recurring word: \"" + firstWordPP._1 + "\" recurring " + firstWordPP._2 + " times\n")

  }
}