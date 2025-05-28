class Matriz:
    resultante = [
        [10],
        [10],
        [10],
    ]

    def __init__(self, matriz):
        if len(matriz) != 3 or any(len(linha) != 3 for linha in matriz):
            raise ValueError("A matriz deve ser 3x3.")

        self.matriz = matriz

    def substituir_coluna_com_resultante(self, coluna):
        matriz_subst = self.matriz

        for i in range(3):
            matriz_subst[i][coluna] = self.resultante[i][0]

        return matriz_subst

    def sarrus(self):
        matriz_sarrus = self.matriz

        for linha in matriz_sarrus:
            linha.append(linha[0])
            linha.append(linha[1])

        return matriz_sarrus

    def determinante(self):
        soma_diagonais = 0

        matriz_sarrus = self.sarrus()
        print(matriz_sarrus)

        # Principais
        for i in range(3):
            diagonal = 1

            for j in range(3):
                diagonal *= matriz_sarrus[j][j+i]

            soma_diagonais += diagonal

        # Secundárias
        for i in range(3):
            diagonal = 1

            for j in range(3):
                diagonal *= matriz_sarrus[j][-j-i-1]

            soma_diagonais -= diagonal

        return soma_diagonais


m1 = Matriz([
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1],
])

print(m1.determinante())
