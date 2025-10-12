#ifndef _H_FILA
#define _H_FILA

struct fila* criar_fila(int capacidade);
bool ehCheia(struct fila* f);
bool ehVazia(struct fila* f);
void push(struct fila* f, int item);
int pop(struct fila* f);
int frente(struct fila* f);
int traseira(struct fila* f);

#endif // _H_FILA