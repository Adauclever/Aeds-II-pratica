#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindromo.h"


int main(void) {
    FILE *arq = fopen("palavras.txt", "r"); 
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char palavra[100];
    no *ptlista = (no*)malloc(sizeof(no)); 
    ptlista->prox = NULL;
    ptlista->ant = NULL;


    while (fgets(palavra, sizeof(palavra), arq)) {
        palavra[strcspn(palavra, "\r\n")] = '\0';
        no *fim = NULL;
        for(int i = 0; palavra[i] != '\0'; i++){
            insere( palavra[i], ptlista, &fim); 
        }

        printf("%d\n", conferePalavra(ptlista, fim));
        limpa(ptlista);
        ptlista = (no*)malloc(sizeof(no)); 
        ptlista->prox = NULL;
        ptlista->ant = NULL;
    }
    fclose(arq);
    return 0;
}