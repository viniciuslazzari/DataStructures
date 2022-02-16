#include <stdio.h>
#include <stdlib.h>
#include "tad_lista_duplamente_encadeada.h"

int main(void){
    PtNo *no;
    InfoNo produto;
    int i, codigo;

    // inicializa a lista
    no = inicializa();

    // recebe inputs
    for (i = 1; i <= 3; ++i)
    {
        printf("Codigo: ");
        scanf("%d", &produto.codigo);

        printf("Nome: ");
        scanf(" %[^\n]%*c", produto.nome);

        printf("Preco: ");
        scanf("%f", &produto.preco);

        no = insere_produto_final(no, produto);

        printf("\n");
    }

    // imprime a lista
    imprime(no);

    for (i = 1; i <= 3; ++i)
    {
        printf("Digite um codigo para remover: ");
        scanf("%d", &codigo);

        no = remove_produto(no, codigo);

        // imprime a lista
        imprime(no);

        printf("\n");
    }

    system("pause");

    return 0;
}
