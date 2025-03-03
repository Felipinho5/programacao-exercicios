fun adicionar(v1: Double, v2: Double): Double {
    return v1 + v2
}

fun subtrair(v1: Double, v2: Double): Double {
    return v1 - v2
}

fun multiplicar(v1: Double, v2: Double): Double {
    return v1 * v2
}

fun dividir(v1: Double, v2: Double): Double {
    return v1 / v2
}

fun main() {
    print("Valor 1: ")
    val v1: Double = readln().toDouble()
    print("Valor 2: ")
    val v2: Double = readln().toDouble()

    println("A - Adicionar")
    println("S - Subtrair")
    println("M - Multiplicar")
    println("D - Dividir")
    print("Escolha uma operação (A/S/M/D): ")
    val escolha: Char = readln().first().lowercaseChar()

    when (escolha) {
        'a' -> println(adicionar(v1, v2))
        's' -> println(subtrair(v1, v2))
        'm' -> println(multiplicar(v1, v2))
        'd' -> println(dividir(v1, v2))
        else -> println("Operação inválida.")
    }
}