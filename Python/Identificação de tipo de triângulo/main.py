def bubble_sort(lista):

    for i in range(len(lista)):
        trocou = False

        for j in range(len(lista) - 1):
            if lista[j] > lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
                trocou = True

        if not trocou:
            break



def main():
    quant = range(3)
    lados = [0.0 for _ in quant]

    while True:
        for i in quant:
            while True:
                try:
                    lados[i] = float(input(f'Digite o valor do {i+1}º lado: '))

                    if lados[i] <= 0:
                        raise ValueError

                    break

                except ValueError:
                    print('Digite um valor válido.')

        bubble_sort(lados)

        if lados[0] + lados[1] > lados[2]:
            break
        else:
            print('Os valores informados não formam um triângulo.')

    if lados[0] == lados[1] == lados[2]:
        print('Triângulo equilátero.')
    elif lados[0] == lados[1] or lados[1] == lados[2]:
        print('Triângulo isósceles.')
    else:
        print('Triângulo escaleno.')



if __name__ == '__main__':
    main()



'''

TESTES PARA FAZER:
- Inserir letras e números menores ou iguais a zero como medidas de lado.
- Inserir valores que não formam um triângulo.
- Inserir alguns triângulos equiláteros, isósceles e escalenos e checar se o programa os classifica corretamente.

'''