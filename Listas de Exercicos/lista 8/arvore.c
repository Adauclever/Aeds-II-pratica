#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
 
// Cria um novo nó na árvore
struct node* novo_no(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}
 
// Inserir novo nó com determinado
// valor na árvore binária
struct node* inserir(struct node* node, int valor) {
    // Se a árvore é vazia, então cria um novo nó
    if (node == NULL) {
        return novo_no(valor);
    }
 
    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < node->valor) {
        node->esquerda = inserir(node->esquerda, valor);
    } else if (valor > node->valor) {
        node->direita = inserir(node->direita, valor);
    }
    
    // Retorna o ponteiro para o nó
    return node;
}
 
// Procura por um valor na árvore
struct node* buscar(struct node* root, int valor) {
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (root == NULL || root->valor == valor) {
        return root;
    }

    // Valor é maior que a raiz
    if (root->valor < valor) {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

// Remover um determinado nó da árvore
struct node* remover(struct node* root, int valor) {
    if (buscar(root, valor) == NULL) {
        printf("Erro: no com valor %d nao foi encontrado!\n", valor);
        return root;
    }

    // Nó temporário para armazenar o nó a ser removido
    struct node* temp = NULL;

    // Caso base
    if (root == NULL) {
        return root;
    }

    // Caso o valor a ser removido seja menor que a raiz
    if (valor < root->valor) {
        root->esquerda = remover(root->esquerda, valor);
    }
    // Caso o valor a ser removido seja maior que a raiz
    else if (valor > root->valor) {
        root->direita = remover(root->direita, valor);
    }
    // Caso o valor seja igual ao da raiz, então este é o nó a ser removido
    else {
        // Nó com apenas um filho ou nenhum filho
        if (root->esquerda == NULL) {
            temp = root->direita;
            free(root);
            return temp;
        } else if (root->direita == NULL) {
            temp = root->esquerda;
            free(root);
            return temp;
        }

        // Nó com dois filhos: obtém o sucessor em ordem (menor na subárvore direita)
        temp = root->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        // Copia o valor do sucessor em ordem para este nó
        root->valor = temp->valor;

        // Remove o sucessor em ordem
        root->direita = remover(root->direita, temp->valor);
    }
    return root;
}

// Tamanho da árvore em ordem
void tamanhoArvore(struct node* root, int *tamanho) {
    if (root != NULL) {
        tamanhoArvore(root->esquerda, tamanho);
        (*tamanho)++;
        tamanhoArvore(root->direita, tamanho);
    }
}

// Inserção em ordem no vetor
void inserirVetor(struct node* root, int *vetor, int *pos){
    if (root != NULL){
        inserirVetor(root->esquerda, vetor, pos);
        vetor[(*pos)++] = root->valor;
        inserirVetor(root->direita, vetor, pos);
    }
}

// Inserção da árvore balanceada
struct node* inserirArvoreBalanceada(struct node *root, int vetor[], int inicio, int fim){
    if (inicio > fim) return NULL;
    
    int meio = (inicio + fim)/2;
    // Insere o valor na árvore
    root = inserir(root, vetor[meio]);

    // Chamada recursiva para inserir na esquerda
    root->esquerda = inserirArvoreBalanceada(root->esquerda, vetor, inicio, meio-1);

    // Chamada recursiva para inserir na direita
    root->direita = inserirArvoreBalanceada(root->direita, vetor, meio+1, fim);

    return root;
}

// Imprimir a árvore em ordem
void imprimirPreOrdem(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->valor);
        imprimirPreOrdem(root->esquerda);
        imprimirPreOrdem(root->direita);
    }
}

int main() {
    int *vetor;
    int tamanho=0;
    int posicao=0;
    int inicio=0;

    // Define a árvore como uma estrutura vazia
    struct node* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós (Desbalanceando a árvore)
    inserir(root, 40);
    inserir(root, 30);
    inserir(root, 20);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 80);
 
    // Obtém o tamanho da árvore
    tamanhoArvore(root, &tamanho);
    // Cria um vetor dinâmico com o tamanho da arvore
    vetor = (int*) malloc(tamanho * sizeof(int));

    // Inserindo e exibindo o vetor em ordem
    inserirVetor(root, vetor, &posicao);
    printf("Valores do vetor ordenado:");
    for (int i = 0; i < tamanho; i++){
        printf("\nPosicao %d: %d", i+1, vetor[i]);
    }

    // Define a árvore balanceada como uma estrutura vazia
    struct node* arvore = NULL;
    
    // Inserindo na árvore balanceada
    arvore = inserirArvoreBalanceada(arvore, vetor, inicio, tamanho-1);

    // Imprimindo a arvore desbalanceada para comparar
    printf("\n\nImprimindo em pre ordem a arvore desbalanceada:\n");
    imprimirPreOrdem(root);

    // Exibindo o resultado da inserção na arvore balanceada
    printf("\n\nImprimindo em pre ordem a arvore balanceada:\n");
    imprimirPreOrdem(arvore);

    free(vetor);
    return 0;
}