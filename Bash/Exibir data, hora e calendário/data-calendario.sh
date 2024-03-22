#!/bin/bash

########### Declaração de variáveis ###########

ano=$(date +%Y)
mes=$(date +%m)
dia_mes=$(date +%d)
ultimo_dia_mes=$(date -d "$(date +%Y-%m-01) +1 month -1 day" +%d)
horas=$(date +%H);
minutos=$(date +%M);
segundos=$(date +%S);
dia_semana_num=$(date +%u)
let "dia_semana_num--"
meses=("Janeiro" "Fevereiro" "Março" "Abril" "Maio" "Junho" "Julho" "Agosto" "Setembro" "Outubro" "Novembro" "Dezembro")
dias_semana=("Segunda" "Terça" "Quarta" "Quinta" "Sexta" "Sábado" "Domingo")
dias_semana_abreviados=("Do" "Se" "Te" "Qu" "Qu" "Se" "Sa")
dia_semana=${dias_semana[$dia_semana_num]}

########### Exibir variáveis ###########

echo "Hoje é - $dia_mes/$mes/$ano"
echo "Dia da semana - $dia_semana"
echo "Agora são - $horas e $minutos minutos e $segundos segundos"
echo "Ou seja - $horas:$minutos:$segundos"
echo ""

########### Encontrar informações do calendário ###########

# No final do loop, i será o número do primeiro dia do mês que é o mesmo dia da semana de hoje
for ((i = dia_mes; i > 7; i -= 7)); do :; done

dia_semana_inicio=$dia_semana_num

# Após esse trecho, dia_semana_inicio será um número de 0-6, sendo 0 = domingo e 6 = sábado
for (( ; i > 1; i--))
do
    let "dia_semana_inicio--"
done

if [ $dia_semana_inicio -lt 0 ]; then
    let "dia_semana_inicio = 7 + dia_semana_inicio"
fi

if [ $dia_semana_inicio -eq 6 ]; then
    let "dia_semana_inicio = 0"
else
    let "dia_semana_inicio++"
fi

########### Montar calendário ###########

# Mostrar do mês
echo ${meses[$mes - 1]}

# Mostrar dias da semana
for ((i = 0; i < 7; i++))
do
    echo -n "${dias_semana_abreviados[$i]} "
done

echo ""

for ((i = 1, j = 0; i <= ultimo_dia_mes; i++, j++))
do
    # Pular dias da semana que não contam no início do mês
    for (( ; dia_semana_inicio > 0; dia_semana_inicio--))
    do
        echo -n "   "
        let "j++"
    done

    ## Quebrar linha se chegar no fim da semana
    if [ $j -eq 7 ]; then
        echo ""
        let "j = 0"
    fi

    ## Arrumar o espaçamento de acordo com o tamanho do número do dia
    if [ $i -lt 10 ]; then
        echo -n " $i "
    else
        echo -n "$i "
    fi
done

echo ""

########### Exibir nome do autor ###########

echo ""
echo "Autor: $1"