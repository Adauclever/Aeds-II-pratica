#ifndef _H_FILADEPRIORIDADES_
#define _H_FILADEPRIORIDADES_

// Estrutura de Dados do Jogador
typedef struct {
    char nome_jogador[50];
    int prioridade; // Prioridade (idade)
} Jogador;

// Estrutura para Nó de Lista Encadeada
typedef struct node {
    Jogador dado;
    struct node* prox;
} Node;

// Vetor Ordenado
// Mantido em ordem CRESCENTE de idade (menor para maior)
typedef struct {
    Jogador* itens;
    int tam;
    int cap;
} VetorOrdenado;

// Lista Não Ordenada
typedef struct {
    Node* inicio;
} ListaNaoOrdenada;

// Lista Encadeada Ordenada
typedef struct {
    Node* inicio;
} ListaEncadeadaOrdenada;

VetorOrdenado* criarVetorOrdenado(int capacidadeInicial);
void destruirVetorOrdenado(VetorOrdenado* v);
void inserirVetorOrdenado(VetorOrdenado* v, Jogador j);
Jogador removerVetorOrdenado(VetorOrdenado* v);
ListaNaoOrdenada* criarListaNaoOrdenada();
void destruirListaNaoOrdenada(ListaNaoOrdenada* lista);
void inserirListaNaoOrdenada(ListaNaoOrdenada* l, Jogador j);
Jogador removerListaNaoOrdenada(ListaNaoOrdenada* l);
ListaEncadeadaOrdenada* criarListaEncadeadaOrdenada();
void destruirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* lista);
void inserirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l, Jogador j);
Jogador removerListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l);

#endif // _H_FILADEPRIORIDADES_