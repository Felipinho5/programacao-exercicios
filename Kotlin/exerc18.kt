fun calcularSalario(horasDia: Int, salarioHora: Double, dias: Int): Double {
    return horasDia * salarioHora * dias
}

fun main() {
    print("Quantidade de horas de trabalho por dia: ")
    val horasDia: Int = readln().toInt()
    print("Salário por hora: ")
    val salarioHora: Double = readln().toDouble()
    print("Dias trabalhados: ")
    val dias: Int = readln().toInt()

    println("Salário total: " + calcularSalario(horasDia, salarioHora, dias))
}