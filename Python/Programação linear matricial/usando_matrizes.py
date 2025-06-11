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
    def __init__(self, restr_esq, restr_dir):
        self.restr_esq = self.adicionar_folgas(restr_esq)
        self.restr_dir = restr_dir
        self.combinacoes_variaveis = self.montar_combinacoes_variaveis()
        self.solucoes = []

    def adicionar_folgas(self, restr_esq):
        for i, linha in enumerate(restr_esq):
            for j in range(len(restr_esq)):
                folga = 1 if i == j else 0
                linha.append(folga)

        return restr_esq

    def montar_combinacoes_variaveis(self):
        combinacoes = set()
        for i in range(len(self.restr_esq[0])):
            for j in range(len(self.restr_esq[0])):
                if not (i == j):
                    combinacao = tuple(sorted([i, j]))
                    combinacoes.add(combinacao)
    
    def montar_matriz_combinacao(self, combinacao):
        matriz = [[0 for _ in range(len(combinacao))] for _ in range(len(self.restr_esq))]

        for i in range(len(self.restr_esq)):
            for j, num_var in enumerate(combinacao):
                matriz[i][j] = self.restr_esq[i][num_var]

        return Matriz_2x2(self, matriz)

    def obter_solucao_sugerida(self, combinacao):
        matriz = self.montar_matriz_combinacao(combinacao)
        resultados = matriz.cramer()
        solucao = zip(combinacao, resultados)
        return solucao


class MatrizQuadrada(ABC):
    tamanho = None

    def __init__(self, problema, matriz):
        if not self.tamanho:
            raise NotImplementedError('Subclasses devem implementar o atributo de classe "tamanho".')

        if any(len(linha) != self.tamanho for linha in matriz):
            raise ValueError(f"A matriz deve ser quadrada ({self.tamanho}x{self.tamanho}).")

        self.problema = problema
        self.matriz = matriz

    def substituir_coluna_com_restr_dir(self, num_coluna):
        matriz_subst = deepcopy(self.matriz)

        for i in range(self.tamanho):
            matriz_subst[i][num_coluna] = self.problema.restr_dir[i][0]

        return self.__class__(self.problema, matriz_subst)
    
    @abstractmethod
    def determinante(self):
        raise NotImplementedError("Este método deve ser implementado nas subclasses.")

    def cramer(self):
        det_p = self.determinante()

        if det_p == 0:
            raise ValueError("A determinante da matriz principal é zero.")

        det_variaveis = [self.substituir_coluna_com_restr_dir(i).determinante() for i in range(self.tamanho)]
        variaveis = tuple(map(lambda det_var: det_var / det_p, det_variaveis))

        if any(var < 0 for var in variaveis):
            raise ValueError("Desrespeita a não negatividade.")

        return variaveis
    

class Matriz_2x2(MatrizQuadrada):
    tamanho = 2

    def __init__(self, problema, matriz):
        super().__init__(problema, matriz)

    def determinante(self):
        return self.matriz[0][0] * self.matriz[1][1] - self.matriz[0][1] * self.matriz[1][0]
    

class Matriz_3x3(MatrizQuadrada):
    tamanho = 3

    def __init__(self, problema, matriz):
        super().__init__(problema, matriz)

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
        for i in range(self.tamanho):
            diagonal = 1

            for j in range(self.tamanho):
                diagonal *= matriz_sarrus[j][j+i]

            soma_diagonais += diagonal

        # Secundárias
        for i in range(self.tamanho):
            diagonal = 1

            for j in range(self.tamanho):
                diagonal *= matriz_sarrus[j][-j-i-1]

            soma_diagonais -= diagonal

        return soma_diagonais


p1 = Problema([
    [3, 4],
    [9, 7],
], [
    [200],
    [300],
])

m1 = Matriz_2x2(p1, [
    [1, 0],
    [0, 1],
])

mat = p1.montar_matriz_combinacao((0, 3))
print(m1.cramer())
