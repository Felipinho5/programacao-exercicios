from copy import deepcopy
from abc import ABC, abstractmethod
from math import factorial as fatorial


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
    def __init__(self, *, obj, minimizar=False, maximizar=False, restr_esq, restr_dir):
        if minimizar == maximizar:
            raise ValueError("É necessário escolher ou minimizar ou maximizar o objetivo.") 
        
        self.obj = obj
        self.minimizar = minimizar
        self.maximizar = maximizar
        self.restr_esq = self.adicionar_folgas(restr_esq)
        self.restr_dir = restr_dir
        self.variaveis = [i for i in range(len(self.restr_esq[0]))]
        self.combinacoes = self.montar_combinacoes()
        self.solucoes = self.obter_todas_as_solucoes_sugeridas()
        self.solucoes_validas = [solucao for solucao in self.solucoes if not isinstance(solucao, ValueError)]
        self.solucao_otima = self.obter_solucao_otima()

    def adicionar_folgas(self, restr_esq):
        for i, linha in enumerate(restr_esq):
            for j in range(len(restr_esq)):
                folga = 1 if i == j else 0
                linha.append(folga)

        return restr_esq

    def obter_numero_combinacoes(self):
        n = len(self.restr_esq[0])
        p = len(self.restr_dir)
        return fatorial(n) // (fatorial(p) * fatorial(n-p))

    def montar_combinacoes(self):
        numero_combinacoes = self.obter_numero_combinacoes()
        combinacoes = []

        combinacao = [i for i in range(len(self.restr_dir))]
        k = 0

        while True:
            combinacoes.append(combinacao[:])

            if len(combinacoes) == numero_combinacoes:
                break

            combinacao[-1-k] += 1

            while combinacao[-1-k] >= len(self.variaveis) - k:
                k += 1
                combinacao[-1-k] += 1

            if k > 0:
                for i in range(len(combinacao[-k:])):
                    combinacao[-k+i] = combinacao[-1-k] + 1 + i
                k = 0

        return combinacoes

    def montar_matriz_combinacao(self, combinacao):
        matriz = [[0 for _ in range(len(combinacao))] for _ in range(len(self.restr_esq))]

        for i in range(len(self.restr_esq)):
            for j, num_var in enumerate(combinacao):
                matriz[i][j] = self.restr_esq[i][num_var]

        ClasseMatriz = Matriz_2x2 if len(matriz) == 2 else Matriz_3x3
        return ClasseMatriz(self, matriz)

    def obter_resultado_obj(self, vars_e_coefs):
        res = 0
        for var, coef in vars_e_coefs:
            if var < len(self.obj):
                res += coef * self.obj[var]

        return res

    def obter_solucao_sugerida(self, combinacao):
        matriz = self.montar_matriz_combinacao(combinacao)

        try:
            coeficientes = matriz.cramer()
            vars_e_coefs = tuple(zip(combinacao, coeficientes))

            solucao = {
                "variaveis_e_coeficientes": vars_e_coefs,
                "resultado_obj": self.obter_resultado_obj(vars_e_coefs)
            }

        except ValueError as e:
            solucao = e

        return solucao
    
    def obter_todas_as_solucoes_sugeridas(self):
        return [self.obter_solucao_sugerida(combinacao) for combinacao in self.combinacoes]
    
    def obter_solucao_otima(self):
        if not self.solucoes_validas:
            return None

        min_ou_max = None
        if self.maximizar:
            min_ou_max = max
        else:
            min_ou_max = min

        return min_ou_max(solucao["resultado_obj"] for solucao in self.solucoes_validas)


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
        coeficientes = tuple(map(lambda det_var: det_var / det_p, det_variaveis))

        if any(var < 0 for var in coeficientes):
            raise ValueError("Desrespeita a não negatividade.")

        return coeficientes
    
    def __str__(self):
        s = ""
        for i in range(len(self.matriz)):
            s += "["
            for j in range(len(self.matriz[0])):
                s += str(self.matriz[i][j])
                if not j == len(self.matriz[0]) - 1:
                    s += "   "
                else:
                    s += "]"
            s += "\n"
        return s
    

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


p1 = Problema(
    obj = (2, 5),
    maximizar = True,

    restr_esq = [
        [3, 4],
        [9, 7],
    ],
    
    restr_dir = [
        [200],
        [300],
    ],
)

p2 = Problema(
    obj = (3, 2),
    maximizar = True,

    restr_esq = [
        [5, 7],
        [6, 5],
        [1, 0],
    ],
    
    restr_dir = [
        [35],
        [30],
        [3],
    ],
)

print(p1.solucao_otima)
print(p2.solucao_otima)

'''
0 1 2
0 1 3
0 1 4
0 2 3
0 2 4
0 3 4
1 2 3
1 2 4
1 3 4
2 3 4
'''