fun calcularImc(peso: Double, altura: Double): Double {
    return peso / (altura * altura)
}

fun main() {
    print("Peso: ")
    val peso: Double = readln().toDouble()
    print("Altura: ")
    val altura: Double = readln().toDouble()

    println("IMC: " + calcularImc(peso, altura))
}