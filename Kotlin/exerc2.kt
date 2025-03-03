fun main() {
    print("n = ")
    val n = readln().toInt()
    print("a = ")
    val a = readln().toInt()
    print("b = ")
    val b = readln().toInt()
    print("c = ")
    val c = readln().toInt()

    val vet = intArrayOf(a, b, c)

    if (n == 1)
        println(vet.sortedArray().joinToString())
    else if (n == 2)
        println(vet.sortedArrayDescending().joinToString())
    else if (n == 3) {
        val maior = vet.maxOrNull()

        when (maior) {
            a -> println("$b, $maior, $c")
            b -> println("$a, $maior, $c")
            c -> println("$a, $maior, $b")
        }
    }
    else
        println("Valor inválido para n.")
}