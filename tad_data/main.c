#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(void)
{
    Data data1;
    Data data2;
    Data data_pascoa;
    int ano;

    printf("Informe duas datas: \n\n");

    le_data(&data1);

    if (!valida_data(data1))
    {
        printf("Data invalida! \n");
        exit(1);
    }

    printf("\n");

    le_data(&data2);

    if (!valida_data(data2))
    {
        printf("Data invalida! \n");
        exit(1);
    }

    printf("\n");

    printf("Existe uma diferenca de %d dias entre as duas datas", calcula_dias(data1, data2));

    printf("\n\n");

    printf("Informe um ano: ");
    scanf("%d", &ano);

    data_pascoa = calcula_pascoa(ano);

    printf("A data da pascoa no ano de %d eh ", ano);
    imprime_data(data_pascoa);

    printf("\n");

    return 0;
}
