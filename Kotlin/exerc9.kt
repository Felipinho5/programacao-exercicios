fun main() {
    print("Ano de nascimento: ")
    val anoNasc: Int = readln().toInt()

    print("Ano atual: ")
    val anoAtual: Int = readln().toInt()

    if (anoNasc < anoAtual) {
        val idadeAnos: Int = anoAtual - anoNasc
        val idadeMeses: Int = idadeAnos * 12
        val idadeDias: Int = idadeAnos * 365
        val idadeSemanas: Int = idadeAnos * 52
        println("Idade em anos: $idadeAnos")
        println("Idade em meses: $idadeMeses")
        println("Idade em dias: $idadeDias")
        println("Idade em semanas: $idadeSemanas")
    }
    else
        println("Anos inválidos.")
}