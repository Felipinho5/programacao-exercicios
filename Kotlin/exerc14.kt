fun mostrarMedia(n1: Double, n2: Double) {
    println("Média: " + (n1 + n2) / 2)
}

fun main() {
    print("Nota 1: ")
    val n1 = readln().toDouble()
    print("Nota 2: ")
    val n2 = readln().toDouble()

    mostrarMedia(n1, n2)
}