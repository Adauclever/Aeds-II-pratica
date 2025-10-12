#ifndef PALINDROMO_H
#define PALINDROMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra {
    char letra;
    struct palavra *prox;
    struct palavra *ant;
} no;


void insere (char letra, no * lista, no **fim) {
    no *novoNo = (no*) malloc(sizeof(no));

    if (novoNo == NULL) {
        printf("Erro ao alocar!");
        return;
    }

    novoNo->prox = NULL;
    novoNo->ant = NULL;
    novoNo->letra = letra;

    no *aux = lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novoNo;
    novoNo->ant = aux;
    *fim = novoNo;
}


void limpa(no *lista){
    no *aux = lista->prox;
    while(aux != NULL){
        no *aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }
    free(lista);
}



int conferePalavra(no *ptlista, no *fim){
    no *inicio = ptlista->prox;

    while(inicio != NULL && fim != NULL && inicio != fim && inicio->ant != fim){
        if(inicio->letra != fim->letra){
            return 0 ;
        }
        inicio = inicio->prox;
        fim = fim->ant;
    }
    return 1;
}


#endif