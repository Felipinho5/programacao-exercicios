fun main() {
    print("Digite A para álcool e G para gasolina: ")
    val combustivel: Char = readln().first().lowercaseChar()
    print("Litros: ")
    val litros: Double = readln().toDouble()

    var preco: Double? = null

    if (combustivel == 'a') {
        if (litros <= 20)
            preco = 3.39 * litros * (1 - 0.03)
        else
            preco = 3.39 * litros * (1 - 0.05)
    }
    else if (combustivel == 'g') {
        if (litros <= 20)
            preco = 5.39 * litros * (1 - 0.04)
        else
            preco = 5.39 * litros * (1 - 0.06)
    }
    else
        println("Combustível inválido.")

    if (preco != null)
        print(preco)
}