#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

#define MAX 10

int main(void){
    int inicio, fim, cod;
    TProduto t[MAX];

    // Inicializa o array
    inicializa(t, &inicio, &fim);

    // Insere um item no array
    insere(t, &inicio, &fim, 1);

    // Consulta esse item no array
    cod = consulta(t, inicio, fim, 1);
    printf("O codigo do item na posicao 1 eh: %d\n", cod);

    // Remove o item do array
    remover(t, &inicio, &fim, 1);
    cod = consulta(t, inicio, fim, 1);
    if (cod == -1)
        printf("O item foi excluido com sucesso\n", cod);
    else
        printf("Ocorreu um erro ao excluir o item\n", cod);

    // Destroi o array
    destroi(&inicio, &fim);
}
