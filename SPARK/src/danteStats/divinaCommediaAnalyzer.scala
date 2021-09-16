package danteStats

import org.apache.spark._

object DivinaCommediaAnalyzer {
  def main(args: Array[String]) {

    /*
     * Configurazione dell'ambiente Spark
     * 
     * Spark version 3.1.2
     * Spark web UI at http://LUCA-THINKPAD-P1.mshome.net:4041
     * 
     * 
     */
    val conf = new SparkConf().setAppName("Divina Commedia Stats with Spark").setMaster("local[1]")

    /* spark context*/
    val sc = new SparkContext(conf)

    val divinaCommedia = sc.textFile("inputFiles\\divinaCommedia.txt")

    val counts = divinaCommedia.flatMap(line => line.split(" ")).map((x: String) => 1).fold(0)(((sum: Int, x: Int) => sum + x))
    println(counts)

  }
}