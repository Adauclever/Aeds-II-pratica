#include <stdio.h>
#include <stdlib.h>
//#include "arvore.h"
 

struct node {
    int valor;
    struct node *esquerda, *direita;
};

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
    if (root->valor > valor) {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

struct node* remove_raiz(struct node *root){

    struct node *p = root;
    struct node *q = p->esquerda;

    if(root != NULL){
        
        //1° descer uma para a esquerda e tudo para a direita para achar o numero mais proximo para ser raiz
        while(q->direita != NULL){
            p = q;
            q = q->direita;
        }
        //2° passo -> trocar os valores da raiz com o no achado/nova raiz

        root->valor = q->valor;
        
        //feito
        //excluir a antiga raiz
        //p->direita = NULL;
        //p = root; // retorna o pai a raiz para repetir o ciclo
        //q = root->esquerda; //retorna o filho ao local de origem
    }else {
        printf("NAO EXISTE ARVORE");
        return NULL;
    }

    if(p == root){
        // q é filho direto da raiz
        root->esquerda = q->esquerda;
    } else {
        // q não é filho direto da raiz  
        p->direita = q->esquerda;
    }

    free(q); 
    return root;

}

void preOrdem (struct node* raiz) {
    if (raiz == NULL){
        return;
    }
    printf("%d\n", raiz->valor);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
}

void emOrdem (struct node* raiz) {
    if (raiz == NULL){
        return;
    }
    emOrdem(raiz->esquerda);
    printf("%d\n", raiz->valor);
    emOrdem(raiz->direita);
}

void posOrdem (struct node* raiz) {
    if (raiz == NULL){
        return;
    }
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d\n", raiz->valor);
}

 
 
int main() {
    // Define a árvore como uma estrutura vazia
    struct node* root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós
    inserir(root, 30);
    inserir(root, 20);
    inserir(root, 40);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 80);
 
    emOrdem(root);
    printf("\n");

    while(root != NULL){ //se a raiz for diferente de Nulo, remove e reexibe em oredem
        root = remove_raiz(root);
        printf("Nova arvore em ordem apos remover raiz: \n");
        emOrdem(root);   
        printf("\n");
    }

    // Valor a ser buscado
    int valor = 6;
 
    // Buscando na árvore
    if (buscar(root, valor) == NULL) {
        printf("%d nao encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }
 
    // Novo valor a ser buscado
    valor = 60;
 
    // Buscando na árvore
    if (buscar(root, valor) == NULL) {
        printf("%d nao encontrado\n", valor);
    } else {
        printf("%d encontrado\n", valor);
    }

    return 0;
}