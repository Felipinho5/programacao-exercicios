fun main() {
    print("Número da conta: ")
    val numeroConta: String = readln()
    print("Saldo: ")
    val saldo: Double = readln().toDouble()
    print("Crédito: ")
    val credito: Double = readln().toDouble()
    print("Débito: ")
    val debito: Double = readln().toDouble()

    val saldoAtual: Double = saldo - debito + credito
    println("Saldo atual: $saldoAtual")

    if (saldoAtual >= 0)
        println("Saldo positivo.")
    else
        println("Saldo negativo.")
}