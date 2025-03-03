fun ordenar() {
    var vet: IntArray = IntArray(10)

    for (i in 0..vet.size - 1) {
        print("Vet[$i]: ")
        vet[i] = readln().toInt()
    }

    for (i in 0..vet.size - 2) {

        var trocou: Boolean = false

        for (j in 0..vet.size - i - 2) {

            if (vet[j] > vet[j+1]) {
                val temp = vet[j]
                vet[j] = vet[j+1]
                vet[j+1] = temp
                trocou = true
            }
        }

        if (!trocou)
            break
    }

    println(vet.joinToString())
}

fun main() {
    ordenar()
}