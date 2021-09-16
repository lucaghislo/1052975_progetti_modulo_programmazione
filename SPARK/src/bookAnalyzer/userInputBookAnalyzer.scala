package bookAnalyzer

import org.apache.spark._
import org.apache.spark.rdd.RDD
import scala.collection.mutable._
import scala.io.StdIn._

object UserBookAnalyzer {

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

  def mostRecurringWords(words: RDD[String], sc: SparkContext) = {
    val wc = words.flatMap(l => l.split(" ")).map(word => (word, 1)).reduceByKey(_ + _)
    val wc_swap = wc.map(_.swap)
    val hifreq_words = wc_swap.sortByKey(false, 1)
    val top10rdd = sc.parallelize(hifreq_words.take(10))
    top10rdd.collect()
  }

  def printWords(array: Array[(Int, String)], url: String) = {
    println("\n*** BOOK ANALYSIS ***\n\nURL: " + url + "\n\n** 10 Most Recurring Words **\n")
    var i = 1;
    while (i < array.size) {
      println("\"" + array(i)._2 + "\"\trecurring " + array(i)._1 + " times")
      i += 1
    }
  }

  def main(args: Array[String]) {

    print("Please input .txt URL: ")
    val url = readLine()

    val sc = configSpark("Book Stats with Spark", "local[1]")

    val book = readFile(sc, url)
    val words = splitWords(book)
    val wordCount = countWords(words)
    val characterCount = countCharacters(words)
    val firstWords = mostRecurringWords(book, sc)

    printWords(firstWords, url)
    println("\n     Word count: " + wordCount + " words")
    println("Character count: " + characterCount + " characters\n")

  }
}