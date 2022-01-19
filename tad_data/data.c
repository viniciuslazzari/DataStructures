#include <stdio.h>
#include <stdlib.h>
#include "data.h"

// lê uma data
void le_data(Data *data) {
  printf("Dia: ");
  scanf("%d", &data->dia);

  printf("Mes: ");
  scanf("%d", &data->mes);

  printf("Ano: ");
  scanf("%d", &data->ano);
}

// valida uma data
int valida_data(Data data) {
  if ((data.dia > 31) || (data.mes > 12) || (data.ano > 2100))
    return 0;
  else
    return 1;
}

// imprime uma data
void imprime_data(Data data) {
  printf("%d/%d/%d", data.dia, data.mes, data.ano);
}

// calcula quantos dias existem entre duas datas
int calcula_dias(Data data1, Data data2){
    int data_juliana1;
    int data_juliana2;

    data_juliana1 = ((data1.ano * 12) + data1.mes) * 30 + data1.dia;
    data_juliana2 = ((data2.ano * 12) + data2.mes) * 30 + data2.dia;

    return data_juliana2 - data_juliana1;
}

// calcula quantos dias existem entre duas datas
Data calcula_pascoa(int ano){
    int c, n, k, i, j, l, m, d;

    c = ano/100;
    n = ano - (19 * (ano / 19));
    k = (c - 17) / 25;
    i = c - c / 4 - ((c - k) / 3) + (19 * n) + 15;
    i = i - (30 * (i / 30));
    i = i - ((i / 28) * (1 - (i / 28)) * (29 / (i + 1)) * ((21 - n) / 11));
    j = ano + ano / 4 + i + 2 - c + c / 4;
    j = j - (7 * (j / 7));
    l = i - j;
    m = 3 + ((l + 40) / 44);
    d = l + 28 - (31 * (m / 4));

    Data data = { .dia = d, .mes = m, .ano = ano };

    return data;
}
