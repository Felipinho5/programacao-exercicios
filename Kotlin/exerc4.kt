fun main() {
    print("Temperatura em Celsius: ")
    val celsius: Double = readln().toDouble()
    val fahrenheit: Double = celsius * 1.8 + 32

    print("Temperatura em Fahrenheit: $fahrenheit")
}