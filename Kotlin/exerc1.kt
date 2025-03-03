fun main() {
    print("Altura: ")
    val altura: Double = readln().toDouble()

    print("Digite M para masculino ou F para feminino: ")
    val genero: Char = readln().first().lowercaseChar()

    var peso: Double? = null

    if (genero == 'm')
        peso = (72.7 * altura) - 58
    else if (genero == 'f')
        peso = (62.1 * altura) - 44.7
    else
        println("Inválido.")

    if (peso != null)
        print(peso)
}