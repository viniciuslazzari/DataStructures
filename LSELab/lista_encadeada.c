#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

// inicializa a lista
No* inicializa(void){
    return NULL;
}

// insere um produto na lista
No* insere_produto(No* pont_lista, Produto produto){
    No *novo, *anterior = NULL, *pont_aux = pont_lista;

    novo = (No*) malloc(sizeof(No));
    novo->produto = produto;
    novo->proximo = NULL;

    // se a lista estiver vazia, apenas define o ponteiro do produto como
    // o começo e retorna
    if (pont_lista == NULL){
        pont_lista = novo;
        return pont_lista;
    }

    // senão, faz um loop para encontrar a posição em que o produto deve entrar,
    // assim como a posição anterior a essa
    for(pont_aux = pont_lista; pont_aux; pont_aux = pont_aux->proximo){
        if (pont_aux->produto.codigo > novo->produto.codigo){
            break;
        }

        anterior = pont_aux;
    }

    // o proximo item da lista sempre deve ser o que esta na atual posição
    // em que ocorreu o break
    novo->proximo = pont_aux;

    // se o anterior for nulo (produto possui o menor codigo da lista),
    // o começo da lista se torna o endereço do proprio produto
    if (anterior == NULL){
        pont_lista = novo;
        return pont_lista;
    }

    // senão, o produto está no meio da lista e deve apontar para o outro elemento
    // que possui codigo maior que o dele
    anterior->proximo = novo;

    // se esse elemento for nulo, apenas retorna
    if (pont_aux == NULL){
        return pont_lista;
    }

    // senão, aponta para o proximo elemento
    novo->proximo = pont_aux;

    return pont_lista;
}

// imprime todos os produtos da lista
void imprime(No* pont_lista){
    No* pont_aux;

    // trata o caso da lista estar vazia
    if (pont_lista == NULL){
        puts("Lista vazia!");
        return;
    }

    printf("\n");
    printf("----- IMPRIMINDO LISTA -----");
    printf("\n\n");

    // iterações para printar a lista
    for (pont_aux = pont_lista; pont_aux != NULL; pont_aux = pont_aux->proximo){
        printf("Codigo: %d\n", pont_aux->produto.codigo);
        printf("Nome: %s\n", pont_aux->produto.nome);
        printf("Preco: %.2f\n", pont_aux->produto.preco);
        printf("\n");
    }
}
