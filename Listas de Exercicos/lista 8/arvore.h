#ifndef _H_ARVORE
#define _H_ARVORE

struct node {
    int valor;
    struct node *esquerda, *direita;
};

struct node* novo_no(int item);
struct node* inserir(struct node* node, int valor);
struct node* buscar(struct node* root, int valor);
struct node* remover(struct node* root, int valor);
void tamanhoArvore(struct node* root, int *tamanho);
void inserirVetor(struct node* root, int *vetor, int *pos);
struct node* inserirArvoreBalanceada(struct node *root, int vetor[], int inicio, int fim);
void imprimir_pre_ordem(struct node* root);

#endif // _H_ARVORE