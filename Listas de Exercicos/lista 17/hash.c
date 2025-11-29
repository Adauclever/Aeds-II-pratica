#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int hashing(int chave) {
    return chave % 10007;  // ignorado, usaremos posição % hash->tamanho
}

struct Hash* criar_hash(int tamanho) {
    struct Hash* hash = malloc(sizeof(struct Hash));
    hash->tamanho = tamanho;
    hash->ocupados = 0;

    hash->tabela = malloc(sizeof(struct Item) * tamanho);

    for (int i = 0; i < tamanho; i++) {
        hash->tabela[i].estado = VAZIO;
    }

    return hash;
}

void hash_insere(struct Hash* hash, int valor) {
    if (hash->ocupados == hash->tamanho) {
        printf("Tabela cheia! Nao e possivel inserir %d\n", valor);
        return;
    }

    int pos = valor % hash->tamanho;

    for (int i = 0; i < hash->tamanho; i++) {
        int p = (pos + i) % hash->tamanho;

        if (hash->tabela[p].estado == VAZIO || hash->tabela[p].estado == REMOVIDO) {
            hash->tabela[p].valor = valor;
            hash->tabela[p].estado = OCUPADO;
            hash->ocupados++;
            printf("Inserido %d na posicao %d\n", valor, p);
            return;
        }
    }
}

int hash_busca(struct Hash* hash, int valor) {
    int pos = valor % hash->tamanho;

    for (int i = 0; i < hash->tamanho; i++) {
        int p = (pos + i) % hash->tamanho;

        if (hash->tabela[p].estado == VAZIO) {
            return -1;
        }

        if (hash->tabela[p].estado == OCUPADO && hash->tabela[p].valor == valor) {
            return p;
        }
    }

    return -1;
}

void hash_remove(struct Hash* hash, int valor) {
    int pos = hash_busca(hash, valor);

    if (pos == -1) {
        printf("Valor %d nao encontrado.\n", valor);
        return;
    }

    hash->tabela[pos].estado = REMOVIDO;
    hash->ocupados--;

    printf("Valor %d removido da posicao %d.\n", valor, pos);
}

void exibir_hash(struct Hash* hash) {
    printf("\n==== TABELA HASH ====\n");

    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%02d] ", i);

        if (hash->tabela[i].estado == VAZIO)
            printf("VAZIO\n");

        else if (hash->tabela[i].estado == REMOVIDO)
            printf("REMOVIDO\n");

        else
            printf("%d\n", hash->tabela[i].valor);
    }
}

void liberar_hash(struct Hash* hash) {
    free(hash->tabela);
    free(hash);
}


int main() {
    int tamanho;
    int opcao;
    int valor;

    printf("=== HASH COM ENDEREÇAMENTO ABERTO ===\n");
    printf("Digite o tamanho da tabela: ");
    scanf("%d", &tamanho);

    struct Hash* hash = criar_hash(tamanho);

    do {
        printf("\n1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Exibir tabela\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Valor para inserir: ");
                scanf("%d", &valor);
                hash_insere(hash, valor);
                break;

            case 2:
                printf("Valor para remover: ");
                scanf("%d", &valor);
                hash_remove(hash, valor);
                break;

            case 3:
                printf("Valor para buscar: ");
                scanf("%d", &valor);
                int r = hash_busca(hash, valor);
                if (r == -1) printf("Valor nao encontrado.\n");
                else printf("Encontrado na posicao %d.\n", r);
                break;

            case 4:
                exibir_hash(hash);
                break;

            case 5:
                liberar_hash(hash);
                return 0;

            default:
                printf("Opcao invalida!\n");
        }

    } while (1);

    return 0;
}