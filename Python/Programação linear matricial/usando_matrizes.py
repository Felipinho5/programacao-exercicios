from copy import deepcopy
from abc import ABC, abstractmethod


"""
Produto 1 = x
Produto 2 = y

FUNÇÃO OBJETIVO
Max L = 2x + 5y

SUJEITO A
3x + 4y <= 200
9x + 7y <= 300
"""


class Problema:
    def __init__(self, restricoes, resultante):
        self.restricoes = restricoes
        self.adicionar_folgas_nas_restricoes()
        self.resultante = resultante

    def adicionar_folgas_nas_restricoes(self):
        for i, linha in enumerate(self.restricoes):
            for j in range(len(self.restricoes)):
                folga = 1 if i == j else 0
                linha.append(folga)

    def matriz_3x3(self, vars):
        pass


class MatrizQuadrada(ABC):
    def __init__(self, problema, matriz, tamanho):
        if any(len(linha) != tamanho for linha in matriz):
            raise ValueError(f"A matriz deve ser quadrada ({tamanho}x{tamanho}).")

        self.problema = problema
        self.matriz = matriz

    def substituir_coluna_com_resultante(self, num_coluna):
        matriz_subst = deepcopy(self.matriz)

        for i in range(len(self.matriz)):
            matriz_subst[i][num_coluna] = self.problema.resultante[i][0]

        return self.__class__(self.problema, matriz_subst)
    
    @abstractmethod
    def determinante(self):
        raise NotImplementedError("Este método deve ser implementado nas subclasses.")

    def cramer(self):
        det_p = self.determinante()

        if det_p == 0:
            raise ValueError("A determinante da matriz principal é zero.")

        det_vars = [self.substituir_coluna_com_resultante(i).determinante() for i in range(len(self.matriz))]
        vars = tuple(map(lambda det_var: det_var / det_p, det_vars))

        if any(var < 0 for var in vars):
            raise ValueError("Desrespeita a não negatividade.")

        return vars
    

class Matriz_2x2(MatrizQuadrada):
    def __init__(self, problema, matriz):
        super().__init__(problema, matriz, 2)

    def determinante(self):
        return self.matriz[0][0] * self.matriz[1][1] - self.matriz[0][1] * self.matriz[1][0]
    

class Matriz_3x3:
    def __init__(self, problema, matriz):
        super().__init__(problema, matriz, 3)

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


p1 = Problema([
    [2, 3],
    [2, 3],
    [2, 3],
], [
    [10],
    [10],
    [10],
])

m1 = Matriz_3x3(p1, [
    [1, 0, 0],
    [0, 1, 0],
    [0, 0, 1],
])

print(m1.cramer())
print(p1.restricoes)
