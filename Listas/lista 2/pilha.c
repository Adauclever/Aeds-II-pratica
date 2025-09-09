#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "pilha.h"

struct pilha { 
	int indiceTopo; 
	int capacidade; 
	int* dados; 
}; 

struct pilha* criar_pilha(int capacidade) { 
	// Aloca a estrutura de dados pilha
    struct pilha* p = (struct pilha*)malloc(sizeof(struct pilha)); 
	// Armazena a capacidade inicial
    p->capacidade = capacidade; 
    // Define que o topo começa vazio
	p->indiceTopo = -1; 
    // Aloca o vetor de elementos
	p->dados = (int*)malloc(p->capacidade * sizeof(int)); 
    // Retorna a pilha criada
	return p; 
} 

bool estaVazia(struct pilha* p) { 
	// Se o topo == -1, então a pilha é vazia
    if (p->indiceTopo == -1) {
        return true;
    } 
    return false;
} 

void push(struct pilha* p, int elemento) { 
	// Se a pilha encher, dobramos o tamanho dela e realocamos
    if (p->indiceTopo == p->capacidade - 1) {
		p->capacidade *= 2;
        p->dados = (int*) realloc(p->dados, p->capacidade * sizeof(int));
    }
    // Aumenta o topo da pilha
    p->indiceTopo++;
    // Insere o elemento no topo da pilha
	p->dados[p->indiceTopo] = elemento; 
} 

int pop(struct pilha* p) { 
	// Se a pilha estiver vazia, não tem como remover nenhum elemento
    if (estaVazia(p)) {
		printf("\nPilha vazia. Impossível remover elementos");
        return -1; 
    }
    // Remove o elemento no topo da pilha e diminui o topo
	return (p->dados[p->indiceTopo--]); 
} 

int topo(struct pilha* p) { 
	// Se a pilha estiver vazia, não tem como obter nenhum elemento
    if (estaVazia(p)) {
		printf("\nPilha vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    // Retorna o elemento do topo da pilha
	return p->dados[p->indiceTopo]; 
} 

void listar(struct pilha* p){
    // Percorrer e exibe toda a pilha
    for (int i = 0; i <= p->indiceTopo; i++){
        printf("\n%d", p->dados[i]);
    }
}


int main() { 
    int valor, opcao;
    bool flag;
    // Cria pilha com 5 posições
    struct pilha* p = criar_pilha(5); 
    do {
        printf("\n\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Ver topo");
	    printf("\n4. Pilha vazia?");
	    printf("\n5. Listar pilha");
	    printf("\n6. Sair");
	    printf("\nDigite sua escolha: ");
	    scanf("%d",&opcao);
	    switch(opcao) {
            case 1: 
		        printf("\nDigite o valor: ");
                scanf("%d",&valor);
                push(p , valor);
                break;
            case 2: 
                printf("\nElemento retirado: %d", pop(p));
                break;
            case 3: 
                printf("\nElemento do topo: %d", topo(p));
                break;
            case 4: 
                flag = estaVazia(p);
                if (flag) {
                    printf("\nPilha vazia");
                } else {
                    printf("\nPilha não está vazia");
                }
                break;       
            case 5:
                flag = estaVazia(p);
                if (flag) {
                    printf("\nPilha vazia!!");
                } else {
                    listar(p);
                }
                break;
            case 6:
                // Liberar memória ao encerrar o programa
                free(p->dados);
                free(p);
                return 0;                
            default: 
                printf("\nOpção inválida!");
                break;
        }
	} while(1);

    return 0;
}
