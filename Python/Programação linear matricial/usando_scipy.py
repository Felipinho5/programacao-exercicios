from scipy.optimize import linprog

"""
Produto 1 = x
Produto 2 = y

FUNÇÃO OBJETIVO
Max L = 2x + 5y

SUJEITO A
3x + 4y <= 200
9x + 7y <= 300
"""

# Declarar os limites das variáveis de decisão
limites_x = (0, None)
limites_y = (0, None)

# Declarar os coeficientes da função objetivo
c = [-2, -5]

# Declarar a matriz de restrições de desigualdade
A = [
     [3, 4],
     [9, 7]
]

# Declarar o vetor de restrições de desigualdade
b = [200, 300]

# Resolver
resultado = linprog(c=c, A_ub=A, b_ub=b, bounds=[limites_x, limites_y], method='highs-ds')

# Imprimir resultados
if resultado.status == 0:
     print('A solução é ótima.')

print(f'Valor da função objetivo: L = {-resultado.fun}')
print(f'Solução: x = {resultado.x[0]}, y = {resultado.x[1]}')