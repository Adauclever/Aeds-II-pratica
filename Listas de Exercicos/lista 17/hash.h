#ifndef _H_HASH_
#define _H_HASH_

#define VAZIO 0
#define OCUPADO 1
#define REMOVIDO 2

struct Item {
    int valor;
    int estado;   // 0 = vazio, 1 = ocupado, 2 = removido
};

struct Hash {
    struct Item* tabela;
    int tamanho;
    int ocupados;
};

struct Hash* criar_hash(int tamanho);
void hash_insere(struct Hash* hash, int valor);
void hash_remove(struct Hash* hash, int valor);
int hash_busca(struct Hash* hash, int valor);
void exibir_hash(struct Hash* hash);
void liberar_hash(struct Hash* hash);

int hashing(int chave);

#endif
