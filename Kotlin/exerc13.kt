fun main() {
    var anterior: Int = 0
    var posterior: Int = 1

    print("1, ")

    for (i in 1..20) {
        val soma: Int = anterior + posterior
        print("$soma, ")
        anterior = posterior
        posterior = soma
    }
}