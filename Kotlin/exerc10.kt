fun main() {
    print("Comprimento: ")
    val comprimento: Double = readln().toDouble()
    print("Altura: ")
    val altura: Double = readln().toDouble()
    print("Largura: ")
    val largura: Double = readln().toDouble()

    val volume: Double = comprimento * altura * largura
    println("Volume: $volume")
}