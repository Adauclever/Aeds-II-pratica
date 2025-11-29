#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int M;  // tamanho da tabela (global para hashing)

/* Cria a tabela hash */
struct Hash* criar_hash(int tamanho) {
    M = tamanho;

    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    hash->tabela = (struct Node**) calloc(tamanho, sizeof(struct Node*));

    return hash;
}

/* Função hash */
int hashing(int chave) {
    return chave % M;
}

/* Insere um item na hash (encadeamento separado) */
void hash_insere(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);

    struct Node* novo = (struct Node*) malloc(sizeof(struct Node));
    novo->item = item;
    novo->proximo = NULL;

    /* Se a posição está vazia */
    if (hash->tabela[pos] == NULL) {
        hash->tabela[pos] = novo;
        return;
    }

    /* Inserção no fim da lista */
    struct Node* atual = hash->tabela[pos];
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo;
}

/* Remove um item da hash */
void hash_remove(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);
    struct Node* atual = hash->tabela[pos];
    struct Node* anterior = NULL;

    while (atual != NULL) {
        if (atual->item.valor == item.valor) {

            if (anterior == NULL)
                hash->tabela[pos] = atual->proximo;
            else
                anterior->proximo = atual->proximo;

            free(atual);
            printf("Item %d removido.\n", item.valor);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("Item %d não encontrado para remoção.\n", item.valor);
}

/* Busca um item dentro da hash */
struct Item busca(struct Hash* hash, struct Item item) {
    int pos = hashing(item.valor);
    struct Node* atual = hash->tabela[pos];

    while (atual != NULL) {
        if (atual->item.valor == item.valor) {
            printf("Item %d encontrado na posição %d\n", item.valor, pos);
            return atual->item;
        }
        atual = atual->proximo;
    }

    printf("Item %d não encontrado.\n", item.valor);

    struct Item item_vazio;
    item_vazio.valor = -1;
    return item_vazio;
}

/* Exibe a tabela hash completa */
void exibir_hash(struct Hash* hash) {
    printf("\n=== TABELA HASH ===\n");

    for (int i = 0; i < M; i++) {
        printf("[%d] -> ", i);

        struct Node* atual = hash->tabela[i];

        while (atual != NULL) {
            printf("%d -> ", atual->item.valor);
            atual = atual->proximo;
        }

        printf("NULL\n");
    }
}

/* Libera toda a memória da hash */
void liberar_hash(struct Hash* hash) {
    for (int i = 0; i < M; i++) {
        struct Node* atual = hash->tabela[i];
        while (atual != NULL) {
            struct Node* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}


int main() {
    int opcao;
    int tamanho;
    struct Item item;

    printf("=== TABELA HASH COM ENCADEAMENTO ===\n");
    printf("Digite o tamanho da tabela hash: ");
    scanf("%d", &tamanho);

    struct Hash* hash = criar_hash(tamanho);

    printf("\nHash criada com %d posicoes.\n", tamanho);
    printf("Funcao hash: h(k) = k mod %d\n", tamanho);

    do {
        printf("\n*************** MENU ****************");
        printf("\n1. Inserir item");
        printf("\n2. Remover item");
        printf("\n3. Buscar item");
        printf("\n4. Exibir tabela hash");
        printf("\n5. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Digite o valor do item para inserir: ");
                scanf("%d", &item.valor);
                hash_insere(hash, item);
                break;

            case 2:
                printf("Digite o valor do item para remover: ");
                scanf("%d", &item.valor);
                hash_remove(hash, item);
                break;

            case 3:
                printf("Digite o valor do item para buscar: ");
                scanf("%d", &item.valor);
                busca(hash, item);
                break;

            case 4:
                exibir_hash(hash);
                break;

            case 5:
                liberar_hash(hash);
                printf("Programa encerrado. Memoria liberada.\n");
                exit(0);

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (1);

    return 0;
}