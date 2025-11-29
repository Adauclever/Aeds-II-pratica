#ifndef _H_HASH_
#define _H_HASH_

struct Item {
    int valor;
};

struct Node {
    struct Item item;
    struct Node* proximo;
};

struct Hash {
    struct Node** tabela;   /* vetor de listas (encadeamento) */
};

/* Cria uma hash*/
struct Hash* criar_hash(int tamanho);

/* Insere um novo elemento na hash */
void hash_insere(struct Hash* hash, struct Item item);

/* Remove um elemento da hash de acordo com sua chave */
void hash_remove(struct Hash* hash, struct Item item);

/* Obtém um item da hash */
struct Item busca(struct Hash* hash, struct Item item);

/* Exibe a hash */
void exibir_hash(struct Hash* hash);

/* Função de hashing */
int hashing(int chave);

/* Libera memória */
void liberar_hash(struct Hash* hash);

#endif // _H_HASH_
