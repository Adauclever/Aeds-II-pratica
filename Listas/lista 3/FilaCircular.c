#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"

struct fila { 
	int frente, traseira, capacidade; 
	int tamanho; 
	int* items; 
}; 

struct fila* criar_fila(int capacidade) { 
    struct fila* f = (struct fila*)malloc(sizeof(struct fila)); 
    f->capacidade = capacidade;
    f->frente = 0;
    f->tamanho = 0;
    f->traseira = capacidade -1;
    f->items = (int*)malloc(capacidade * sizeof(int));
    return f;
} 

bool ehCheia(struct fila* f) { 
    return (f->tamanho  == f->capacidade);
} 

bool ehVazia(struct fila* f) { 
	return(f->tamanho == 0);
} 

void push(struct fila* f, int item) { 
	if(ehCheia(f)){
        printf("\nFila cheia. Impossível inserir elementos");
        return;
    }
    f->traseira = (f->traseira + 1) % f->capacidade; 
    f->items[f->traseira] = item;
    f->tamanho++;
} 


int pop(struct fila* f){ 
	if (ehVazia(f)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1;
    }
    int item = f->items[f->frente];
    f->frente = (f->frente + 1) % f->capacidade;
    f->tamanho--;
    return item;
} 

int frente(struct fila* f){
    if(ehVazia){
        return f->items[f->frente];
    }
}

int traseira(struct fila* f){
    if ((ehVazia)){
        return f->items[f->traseira];
    }
}

int main() {
    int val, n;
    bool aux;
    struct fila* f = criar_fila(5); 

    do {
        printf("\n************************* MENU ************************");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Frente da fila");
        printf("\n4. Traseira da fila");
        printf("\n5. Fila vazia?");
        printf("\n6. Fila cheia?");
        printf("\n7. Sair");
        printf("\nDigite sua escolha: ");
        scanf("%d",&n);

        switch(n) {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d",&val);
                enqueue(f, val);
                break;
            case 2:
                printf("\nElemento removido: %d", dequeue(f));
                break;
            case 3:
                printf("\nFrente: %d", frente(f));
                break;
            case 4:
                printf("\nTraseira: %d", traseira(f));
                break;
            case 5:
                aux = ehVazia(f);
                printf(aux ? "\nFila vazia" : "\nFila não está vazia");
                break;
            case 6:
                aux = ehCheia(f);
                printf(aux ? "\nFila cheia" : "\nFila não está cheia");
                break;
            case 7:
                return 0;
            default:
                printf("\nOpção inválida!");
                break;
        }
    } while(1);

    return 0;
}