import kotlin.math.pow

open class ContaBancaria(val cliente: String, val numConta: Int, var saldo: Float) {

    open fun sacar(qtd: Float) {
        if (this.saldo - qtd >= 0)
            this.saldo -= qtd
        else
            println("Não há saldo suficiente.")
    }

    fun depositar(qtd: Float) {
        this.saldo += qtd
    }

    override fun toString(): String {
        return "cliente: ${this.cliente}, numConta: ${this.numConta}, saldo: ${this.saldo}"
    }
}

class ContaPoupanca(
    cliente: String,
    numConta: Int,
    saldo: Float,
    var diasRendimento: Int
): ContaBancaria(cliente, numConta, saldo) {

    fun calcularNovoSaldo(taxaRendimento: Float) {
        this.saldo += this.saldo * (1 - taxaRendimento).pow(diasRendimento)
    }

    override fun toString(): String {
        return super.toString() + ", diasRendimento: ${this.diasRendimento}"
    }
}

class ContaEspecial(
    cliente: String,
    numConta: Int,
    saldo: Float,
    var limite: Float
): ContaBancaria(cliente, numConta, saldo) {

    override fun sacar(qtd: Float) {
        if (this.saldo - qtd >= -limite)
            this.saldo -= qtd
        else
            println("Não há saldo ou limite suficientes.")
    }

    override fun toString(): String {
        return super.toString() + ", limite: ${this.limite}"
    }
}

fun main() {
    val cb: ContaBancaria = ContaBancaria("Fulano", 111, 100.0f)
    println(cb.toString())
    cb.sacar(150.0f)
    cb.sacar(90.0f)
    cb.depositar(10.0f)
    println(cb.saldo)

    val ce: ContaEspecial = ContaEspecial("Sicrano", 222, 100.0f, 100.0f)
    println(ce.toString())
    ce.sacar(201.0f)
    ce.sacar(200.0f)
    ce.depositar(10.0f)
    println(ce.saldo)

    val cp: ContaPoupanca = ContaPoupanca("Sicrano", 222, 100.0f, 3)
    println(cp.toString())
    cp.sacar(100.0f)
    cp.depositar(10.0f)
    println(cp.saldo)
    cp.calcularNovoSaldo(0.01f)
    println(cp.saldo)
}