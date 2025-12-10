#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaprioridade.h"

// Vetor Ordenado
// Mantido em ordem CRESCENTE de idade (menor para maior)
VetorOrdenado* criarVetorOrdenado(int capacidadeInicial) {
    VetorOrdenado* v = (VetorOrdenado*)malloc(sizeof(VetorOrdenado));
    if (v == NULL) {
        fprintf(stderr, "Erro ao alocar VetorOrdenado\n");
        exit(1);
    }
    v->itens = (Jogador*)malloc(capacidadeInicial * sizeof(Jogador));
    if (v->itens == NULL) {
        fprintf(stderr, "Erro ao alocar itens do vetor\n");
        free(v);
        exit(1);
    }
    v->tam = 0;
    v->cap = capacidadeInicial;
    return v;
}

void destruirVetorOrdenado(VetorOrdenado* v) {
    free(v->itens);
    free(v);
}

// Inserção
void inserirVetorOrdenado(VetorOrdenado* v, Jogador j) {
    // Verificar redimensionamento
    if (v->tam == v->cap) {
        v->cap *= 2;
        v->itens = (Jogador*)realloc(v->itens, v->cap * sizeof(Jogador));
        if (v->itens == NULL) {
            fprintf(stderr, "Erro ao realocar itens do vetor\n");
            exit(1);
        }
    }

    // (Percorre do fim para o começo)
    int pos = v->tam - 1;
    while (pos >= 0 && v->itens[pos].prioridade > j.prioridade) {
        v->itens[pos + 1] = v->itens[pos]; // Desloca item para a direita
        pos--;
    }
    
    // Inserir na posição correta
    v->itens[pos + 1] = j;
    v->tam++;
}

// Remoção
// Remove o de maior prioridade (maior idade), que está no FIM
Jogador removerVetorOrdenado(VetorOrdenado* v) {
    if (v->tam == 0) {
        fprintf(stderr, "Erro: Fila (vetor) vazia!\n");
        exit(1);
    }
    v->tam--;
    return v->itens[v->tam]; // Retorna o último elemento
}

// Lista Não Ordenada
ListaNaoOrdenada* criarListaNaoOrdenada() {
    ListaNaoOrdenada* l = (ListaNaoOrdenada*)malloc(sizeof(ListaNaoOrdenada));
    if (l == NULL) {
        fprintf(stderr, "Erro ao alocar ListaNaoOrdenada\n");
        exit(1);
    }
    l->inicio = NULL;
    return l;
}

void destruirListaNaoOrdenada(ListaNaoOrdenada* lista) {
    Node* current = lista->inicio;
    while (current != NULL) {
        Node* temp = current;
        current = current->prox;
        free(temp);
    }
    free(lista);
}

// Insere em qualquer lugar (vamos inserir no começo)
void inserirListaNaoOrdenada(ListaNaoOrdenada* l, Jogador j) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista nao ordenada)\n");
        exit(1);
    }
    newNode->dado = j;
    newNode->prox = l->inicio;
    l->inicio = newNode;
}

// Remoção
// Precisa percorrer a lista toda para achar o de maior prioridade
Jogador removerListaNaoOrdenada(ListaNaoOrdenada* l) {
    if (l->inicio == NULL) {
        fprintf(stderr, "Erro: Fila (lista nao ordenada) vazia!\n");
        exit(1);
    }

    Node* maxNode = l->inicio;
    Node* prevMax = NULL;
    Node* current = l->inicio;
    Node* prev = NULL;

    // 1. Percorre a lista para achar o nó de maior prioridade
    while (current != NULL) {
        if (current->dado.prioridade > maxNode->dado.prioridade) {
            maxNode = current;
            prevMax = prev;
        }
        prev = current;
        current = current->prox;
    }

    // 2. Remove o nó
    if (prevMax == NULL) { // O máximo era o primeiro (inicio)
        l->inicio = maxNode->prox;
    } else {
        prevMax->prox = maxNode->prox;
    }

    Jogador j = maxNode->dado;
    free(maxNode);
    return j;
}

// Lista Encadeada Ordenada
ListaEncadeadaOrdenada* criarListaEncadeadaOrdenada() {
    ListaEncadeadaOrdenada* l = (ListaEncadeadaOrdenada*)malloc(sizeof(ListaEncadeadaOrdenada));
    if (l == NULL) {
        fprintf(stderr, "Erro ao alocar ListaEncadeadaOrdenada\n");
        exit(1);
    }
    l->inicio = NULL;
    return l;
}

void destruirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    Node* current = l->inicio;
    while (current != NULL) {
        Node* temp = current;
        current = current->prox;
        free(temp);
    }
    free(l);
}

// Inserção
// Acha a posição correta para manter a ordem (descrescente)
void inserirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l, Jogador j) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista ordenada)\n");
        exit(1);
    }
    newNode->dado = j;

    // Caso 1: Lista vazia ou novo nó é o de maior prioridade
    if (l->inicio == NULL || j.prioridade > l->inicio->dado.prioridade) {
        newNode->prox = l->inicio;
        l->inicio = newNode;
    } else {
    // Caso 2: Percorre a lista para achar a posição
        Node* current = l->inicio;
        while (current->prox != NULL && current->prox->dado.prioridade > j.prioridade) {
            current = current->prox;
        }
        newNode->prox = current->prox;
        current->prox = newNode;
    }
}

// Remoção
// Remove o de maior prioridade (maior idade), que está no COMEÇO
Jogador removerListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    if (l->inicio == NULL) {
        fprintf(stderr, "Erro: Fila (lista ordenada) vazia!\n");
        exit(1);
    }
    
    Node* temp = l->inicio;
    Jogador j = temp->dado;
    l->inicio = l->inicio->prox;
    free(temp);
    return j;
}


int main() {
    // Criar dados fictícios
    const int NUM_JOGADORES = 10;
    Jogador* jogadores_teste = (Jogador*)malloc(NUM_JOGADORES * sizeof(Jogador));
    if (jogadores_teste == NULL) {
        fprintf(stderr, "Erro ao alocar dados de teste\n");
        return 1;
    }

    // Preenche em ordem decrescente (pior caso para inserção ordenada)
    for (int i = 0; i < NUM_JOGADORES; i++) {
        sprintf(jogadores_teste[i].nome_jogador, "Jogador_%d", NUM_JOGADORES - i);
        jogadores_teste[i].prioridade = NUM_JOGADORES - i;
    }

    Jogador ultimoRemovido;

    // Testando Vetor Ordenado
    printf("Testando: Vetor Ordenado:\n");
    VetorOrdenado* filaVetor = criarVetorOrdenado(10);
    
    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirVetorOrdenado(filaVetor, jogadores_teste[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerVetorOrdenado(filaVetor);
    }
    printf("Vetor Ordenado concluido. Ultimo removido: %s (Prioridade: %d)\n\n", ultimoRemovido.nome_jogador, ultimoRemovido.prioridade);
    destruirVetorOrdenado(filaVetor);


    // Testando Lista Encadeada Ordenada
    printf("Testando: Lista Enc. Ordenada:\n");
    ListaEncadeadaOrdenada* filaListaOrd = criarListaEncadeadaOrdenada();

    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirListaEncadeadaOrdenada(filaListaOrd, jogadores_teste[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerListaEncadeadaOrdenada(filaListaOrd);
    }
    printf("Lista Enc. Ordenada concluida. Ultimo removido: %s (Prioridade: %d)\n\n", ultimoRemovido.nome_jogador, ultimoRemovido.prioridade);
    destruirListaEncadeadaOrdenada(filaListaOrd);


    // Testando Lista Não Ordenada
    printf("Testando: Lista Nao Ordenada:\n");
    ListaNaoOrdenada* filaListaNaoOrd = criarListaNaoOrdenada();

    for (int i = 0; i < NUM_JOGADORES; i++) {
        inserirListaNaoOrdenada(filaListaNaoOrd, jogadores_teste[i]);
    }
    for (int i = 0; i < NUM_JOGADORES; i++) {
        ultimoRemovido = removerListaNaoOrdenada(filaListaNaoOrd);
    }
    printf("Lista Nao Ordenada concluida. Ultimo removido: %s (Prioridade: %d)\n\n", ultimoRemovido.nome_jogador, ultimoRemovido.prioridade);
    destruirListaNaoOrdenada(filaListaNaoOrd);


    // Liberar dados de teste
    free(jogadores_teste);

    return 0;
}