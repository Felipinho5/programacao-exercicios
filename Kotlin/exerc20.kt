fun calcularMedia(n1: Double, n2: Double): Double {
    return (n1 + n2) / 2
}

fun main() {
    print("Nota 1: ")
    val n1: Double = readln().toDouble()
    print("Nota 2: ")
    val n2: Double = readln().toDouble()

    val media: Double = calcularMedia(n1, n2)
    println("Média: $media")
}