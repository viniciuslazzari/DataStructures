#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_lista_duplamente_encadeada.h"

// inicializa a lista
PtNo* inicializa(void){
    return NULL;
}

// insere um produto na lista
PtNo* insere_produto_final(PtNo* pont_lista, InfoNo produto){
    PtNo *novo, *pont_aux;

    novo = (PtNo*) malloc(sizeof(PtNo));
    novo->info = produto;
    novo->proximo = NULL;

    // se a lista estiver vazia, apenas define o ponteiro do produto como
    // o começo e retorna
    if (pont_lista == NULL){
        pont_lista = novo;
        novo->anterior = NULL;
        return pont_lista;
    }

    pont_aux = pont_lista;

    for (pont_aux = pont_lista; pont_aux->proximo; pont_aux = pont_aux->proximo);

    pont_aux->proximo = novo;
    novo->anterior = pont_aux;

    return pont_lista;
}

// remove um produto de uma lista pelo código
PtNo* remove_produto(PtNo* pont_lista, int codigo){
    PtNo *pont_aux;

    // encontra o ponteiro com o codigo especificado
    for(pont_aux = pont_lista; pont_aux; pont_aux = pont_aux->proximo){
        if (pont_aux->info.codigo == codigo)
            break;
    };

    // trata o caso de nao encontrar
    if (pont_aux == NULL){
        puts("Nao encontrei o codigo!");
        return pont_lista;
    }

    // caso a lista so tenha um elemento
    if (pont_aux->proximo == NULL && pont_aux->anterior == NULL){
        pont_lista = NULL;
    }

    // caso seja o primeiro elemento
    if (pont_aux->anterior == NULL && pont_aux->proximo != NULL ){
        pont_lista = pont_aux->proximo;
        pont_aux->proximo->anterior = NULL;
    }

    // caso seja o ultimo elemento
    if (pont_aux->proximo == NULL && pont_aux->anterior != NULL){
        pont_aux->anterior->proximo = NULL;
    }

    // caso esteja no meio
    if (pont_aux->anterior != NULL && pont_aux->proximo != NULL){
        pont_aux->anterior->proximo = pont_aux->proximo;
        pont_aux->proximo->anterior = pont_aux->anterior;
    }

    // limpa o espaco
    free(pont_aux);

    return pont_lista;
}

// imprime todos os produtos da lista
void imprime(PtNo* pont_lista){
    PtNo* pont_aux;

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
        printf("Codigo: %d\n", pont_aux->info.codigo);
        printf("Nome: %s\n", pont_aux->info.nome);
        printf("Preco: %.2f\n", pont_aux->info.preco);
        printf("\n");
    }
}
