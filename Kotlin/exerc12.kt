data class Pessoa(val salario: Double, val filhos: Int)

fun main() {
    var pessoas: MutableList<Pessoa> = mutableListOf()

    while (true) {
        print("Inserir nova pessoa? (S/N): ")
        val escolha: Char = readln().first().lowercaseChar()

        if (escolha != 's')
            break

        print("Salário: ")
        val salario: Double = readln().toDouble()
        print("Número de filhos: ")
        val filhos: Int = readln().toInt()

        pessoas.add(Pessoa(salario, filhos))
    }

    var somaSalario: Double = 0.0
    var somaFilhos: Int = 0
    var maiorSalario: Double = 0.0

    for (pessoa in pessoas) {
        somaSalario += pessoa.salario
        somaFilhos += pessoa.filhos

        if (maiorSalario < pessoa.salario)
            maiorSalario = pessoa.salario
    }

    val mediaSalario: Double = somaSalario / pessoas.size
    val mediaFilhos: Double = somaFilhos.toDouble() / pessoas.size

    println("Média de salário: $mediaSalario")
    println("Média de filhos: $mediaFilhos")
    println("Maior salário: $maiorSalario")
}