#ifndef _H_LISTA
#define _H_LISTA

#include <stdbool.h>

// Declaração antecipada para permitir o uso de ponteiros nas assinaturas
struct listaDupla;

// Operações básicas
bool ehVazia(struct listaDupla *lista);
void inserir_inicio(struct listaDupla *lista, int elemento);
void inserir_fim(struct listaDupla *lista, int elemento);
void inserir_posicao(struct listaDupla *lista, int valor, int posicao);
void apagar(struct listaDupla *lista, int elemento);
void apagar_inicio(struct listaDupla *lista);
void apagar_fim(struct listaDupla *lista);

// Impressão
void imprimirIncio(struct listaDupla *lista);
void imprimirFim(struct listaDupla *lista);

// Consulta
int obter_primeiro(struct listaDupla *lista);
int obter_ultimo(struct listaDupla *lista);
int buscar_posicao(struct listaDupla *lista, int posicao);

// Remoção por posição
void remover_posicao(struct listaDupla *lista, int posicao);

// Compatibilidade: wrapper para a função usada no main de lista.c
static inline void imprimir(struct listaDupla *lista) {
	// Por padrão, imprime a partir do início
	imprimirIncio(lista);
}

#endif