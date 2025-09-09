#ifndef _H_PILHA
#define _H_PILHA

struct pilha* criar_pilha(int tamanho);
bool ehVazia(struct pilha* pilha);
void push(struct pilha* pilha, int item);
int pop(struct pilha* pilha);
int obtem_elemento(struct pilha* pilha);
void listar_pilha (struct pilha* p);

#endif // _H_PILHA