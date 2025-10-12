#ifndef LISTA_H
#define LISTA_H

void inserir_fim(int elemento);
void inserir_inicio(int elemento);
void apagar(int ele);
void apagar_inicio();
void apagar_fim();
bool ehVazia();
void imprimir();
int obter_primeiro(void);
int obter_ultimo(void);
void inserirPosicao(int valor, int posicao);
void removerPosicao(int posicao);
int obterPosicao(int posicao);

#endif