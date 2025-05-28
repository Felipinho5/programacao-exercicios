from copy import deepcopy


class Problema:
    matriz_restricoes = [
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
        [1, 2, 3, 4, 5],
    ]
    resultante = [
        [63],
        [55],
        [4],
    ]

    def matriz_3x3(self, vars):
        pass


class Matriz:
    def __init__(self, matriz):
        if len(matriz) != 3 or any(len(linha) != 3 for linha in matriz):
            raise ValueError("A matriz deve ser 3x3.")

        self.matriz = matriz

    def substituir_coluna_com_resultante(self, num_coluna):
        matriz_subst = deepcopy(self.matriz)

        for i in range(3):
            matriz_subst[i][num_coluna] = Problema.resultante[i][0]

        return self.__class__(matriz_subst)

    def sarrus(self):
        matriz_sarrus = deepcopy(self.matriz)

        for linha in matriz_sarrus:
            linha.append(linha[0])
            linha.append(linha[1])

        return matriz_sarrus

    def determinante(self):
        soma_diagonais = 0

        matriz_sarrus = self.sarrus()

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

    def cramer(self):
        det_p = self.determinante()

        if det_p == 0:
            raise ValueError("A determinante da matriz principal é zero.")

        det_vars = [self.substituir_coluna_com_resultante(i).determinante() for i in range(3)]
        vars = tuple(map(lambda det_var: det_var / det_p, det_vars))

        if any(var < 0 for var in vars):
            raise ValueError("Desrespeita a não negatividade.")

        return vars


m1 = Matriz([
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1],
])

print(m1.cramer())
