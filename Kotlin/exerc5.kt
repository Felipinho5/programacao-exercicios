fun main() {
    print("Nota 1: ")
    val n1: Double = readln().toDouble()
    print("Nota 2: ")
    val n2: Double = readln().toDouble()
    print("Nota 3: ")
    val n3: Double = readln().toDouble()

    val media: Double = (n1 * 2 + n2 * 3 + n3 * 5) / 10
    println("Média: $media")
}