#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct fila {
    No *frente;
    No *fundo;
    int tamanho_atual;
} Fila;

Fila* criar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = NULL;
    fila->fundo = NULL;
    fila->tamanho_atual = 0;
    return fila;
}

bool ehVazia(Fila *fila) {
    return (fila->tamanho_atual == 0);
}

void push(Fila *fila, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (ehVazia(fila)) {
        fila->frente = fila->fundo = novoNo;
    } else {
        fila->fundo->prox = novoNo;
        fila->fundo = novoNo;
    }
    fila->tamanho_atual++;
}


int pop(Fila *fila) {
    if (ehVazia(fila)) {
        printf("\nFila vazia. Impossível remover elementos");
        return -1; // Valor indicando erro
    }

    No *temp = fila->frente;
    int valor_removido = temp->valor;
    
    fila->frente = fila->frente->prox;
    fila->tamanho_atual--;
    
    // Se a fila ficou vazia após a remoção
    if (fila->frente == NULL) {
        fila->fundo = NULL;
    }
    
    free(temp);
    return valor_removido;
}

// função para obter o elemento da frente
int obtem_elemento(Fila *fila) {
    if (ehVazia(fila)) {
        printf("\nFila vazia");
        return -1; // Valor indicando erro
    }
    return fila->frente->valor;
}

// Função para liberar a memória da fila
void liberar_fila(Fila *fila) {
    while (!ehVazia(fila)) {
        pop(fila);
    }
    free(fila);
}

// Exemplo de uso
int main() {
    Fila *minha_fila = criar_fila();
    
    push(minha_fila, 10);
    push(minha_fila, 20);
    push(minha_fila, 30);
    
    printf("Elemento da frente: %d\n", obtem_elemento(minha_fila));
    printf("Removido: %d\n", pop(minha_fila));
    printf("Novo elemento da frente: %d\n", obtem_elemento(minha_fila));
    
    liberar_fila(minha_fila);
    return 0;
}