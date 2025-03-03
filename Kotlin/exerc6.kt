fun main() {
    print("Horas trabalhadas: ")
    val horas: Int = readln().toInt()
    print("Salário por hora: ")
    val salarioHora: Double = readln().toDouble()

    val salarioTotal: Double

    if (horas > 40)
        salarioTotal = salarioHora * horas + salarioHora * ( (horas - 40) * 0.5 )
    else
        salarioTotal = salarioHora * horas
    
    println("Salário total: $salarioTotal")
}