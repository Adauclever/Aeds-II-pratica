#include <stdio.h> 
#include <stdlib.h> 
#include "heap.h"

struct Heap* heap_inicializa(int max) {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->max = max;
    heap->pos = 0;
    heap->prioridade = (int *)malloc(max * sizeof(int));
    return heap;
}

int ehVazia(struct Heap* heap) {
    return heap->pos == 0;
}

int ehCheia(struct Heap* heap) {
    return heap->pos == heap->max;
}

void troca(int a, int b, int* v) {
    int f = v[a];
    v[a] = v[b];
    v[b] = f;
}

void corrige_acima(struct Heap* heap, int pos) {
    int pai;
    while (pos > 0) {
        pai = (pos - 1) / 2;
        if (heap->prioridade[pai] < heap->prioridade[pos]) {
            troca(pos, pai, heap->prioridade);
        } else { 
            break;
        }
        pos = pai;
    }
}

void heap_insere(struct Heap* heap, int prioridade) {
    if (!ehCheia(heap)) {
        heap->prioridade[heap->pos] = prioridade;
        corrige_acima(heap, heap->pos);
        heap->pos++;
    } else {
        printf("Heap CHEIO!\n"); 
    }
}

void corrige_abaixo(int *prios, int atual, int tam) {
    int pai = atual;
    int filho_esq, filho_dir, filho;
    while (2 * pai + 1 < tam) {
        filho_esq = 2 * pai + 1;
        filho_dir = 2 * pai + 2;
        if (filho_dir >= tam) {
            filho_dir = filho_esq;
        }
        if (prios[filho_esq] > prios[filho_dir]) {
            filho = filho_esq;
        } else {
            filho = filho_dir;
        }
        if (prios[pai] < prios[filho]) {
            troca(pai, filho, prios);
        } else {
            break;
        }
        pai = filho;
    }
}

int heap_remove(struct Heap* heap) {
    if (!ehVazia(heap)) {
        int topo = heap->prioridade[0];
        heap->prioridade[0] = heap->prioridade[heap->pos - 1];
        heap->pos--;
        corrige_abaixo(heap->prioridade, 0, heap->pos);
        return topo;
    }
    printf("Heap VAZIO!");
    return -1;
}

// Função auxiliar para imprimir a heap (não está no header, mas é útil para testes)
void heap_imprime(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->pos; i++) {
        printf("%d ", heap->prioridade[i]);
    }
    printf("\n");
}

// Função para liberar memória (não está no header, mas é essencial)
void heap_libera(struct Heap* heap) {
    free(heap->prioridade);
    free(heap);
}

int main() {
    struct Heap* heap = heap_inicializa(10);
    
    // Testando as funções ehVazia e ehCheia
    printf("Heap vazia? %s\n", ehVazia(heap) ? "Sim" : "Nao");
    printf("Heap cheia? %s\n", ehCheia(heap) ? "Sim" : "Nao");
    
    // Testando a max-heap
    printf("\nInserindo elementos: 10, 5, 20, 15, 30\n");
    heap_insere(heap, 10);
    heap_insere(heap, 5);
    heap_insere(heap, 20);
    heap_insere(heap, 15);
    heap_insere(heap, 30);
    
    heap_imprime(heap);
    
    printf("\nRemovendo elementos (deve ser em ordem decrescente - max-heap):\n");
    while (!ehVazia(heap)) {
        int removido = heap_remove(heap);
        printf("Elemento removido: %d\n", removido);
        heap_imprime(heap);
    }
    
    printf("Heap vazia? %s\n", ehVazia(heap) ? "Sim" : "Nao");
    
    heap_libera(heap);
    
    return 0;
}