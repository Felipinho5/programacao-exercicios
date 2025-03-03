fun main() {
    print("Número: ")
    val n: Double = readln().toDouble()

    for (i in 1..10)
        println("$n x $i = " + n * i)
}