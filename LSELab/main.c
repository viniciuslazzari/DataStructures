#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

int main(void){
    No *no;
    Produto produto;
    int i;

    // inicializa a lista
    no = inicializa();

    // recebe inputs
    for (i = 1; i <= 4; ++i)
    {
        printf("Codigo: ");
        scanf("%d", &produto.codigo);

        printf("Nome: ");
        scanf(" %[^\n]%*c", produto.nome);

        printf("Preco: ");
        scanf("%f", &produto.preco);

        no = insere_produto(no, produto);

        printf("\n");
    }

    // imprime a lista
    imprime(no);

    system("pause");

    return 0;
}
