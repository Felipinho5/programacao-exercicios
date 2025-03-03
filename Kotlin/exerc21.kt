fun celsius(fahrenheit: Double): Double {
    return (fahrenheit - 32) / 1.8
}

fun main() {
    print("Temperatura em Fahrenheit: ")
    val fahrenheit: Double = readln().toDouble()

    println("Temperatura em Celsius: " + celsius(fahrenheit))
}