fun calcularArea(raio: Double): Double {
    return 3.14 * (raio * raio)
}

fun main() {
    print("Raio: ")
    val raio: Double = readln().toDouble()

    println("Área: " + calcularArea(raio))
}