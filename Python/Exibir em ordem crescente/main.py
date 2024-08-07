quant = None

while True:
    # Permanecer pedindo uma quantidade válida até que ela seja dada
    try:
        quant = int(input('Quantidade de números a serem digitados (mínimo 2, máximo 1000): '))

        if quant < 2 or quant > 1000:
            raise ValueError

        break

    except ValueError:
        print('Quantidade inválida.')


nums = []

# Ler cada um dos números do vetor
for i in range(quant):
    # Permanecer pedindo um número válido até que ele seja dado
    while True:
        try:
            num = float(input(f'Digite o {i + 1}º número: '))
            break
        except ValueError:
            print('Número inválido.')

    nums.append(num)


# Ordenar o vetor
for i in range(quant - 1):
    for j in range(quant - i - 1):
        if nums[j] > nums[j+1]:
            aux = nums[j]
            nums[j] = nums[j+1]
            nums[j+1] = aux


# Imprimir a sequência
print(f'Sequência crescente: {nums}')


'''
Para testar o código:
- Tentar inserir valores inválidos como a quantidade de números a serem digitados (ex.: letras ou números negativos).
- Verificar se a quantidade de números lidos condiz com a quantidade que o usuário digitou.
- Tentar inserir valores inválidos como números da sequência (ex.: letras).
- Inserir várias sequências de números diferentes para checar se o programa ordena todas corretamente.
'''
