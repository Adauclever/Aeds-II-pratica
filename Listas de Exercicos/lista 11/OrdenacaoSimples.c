#include<stdio.h> 
#include<stdlib.h> 
#include "ordenacaosimples.h"
  
// Imprime um vetor de inteiros
void imprimir(int *vetor) {
    int i;
    for (i = 0; i < 50; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubble(int *vetor) {
    for(int i = 50 - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j + 1]){
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    imprimir(vetor);
    return;
}

void selection(int *vetor) {
    for(int i = 0; i < 50; i++){
        int menor = i;
        for(int j = i + 1; j < 50; j++){
            if(vetor[j] < vetor[menor] ){
                menor = j;
            }
        }
        if(menor != i){
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
        }
    }
       
    
    imprimir(vetor);
    return;
}

void insertion(int *vetor) {
    for(int i = 1; i < 50; i++){
        int chave = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
    imprimir(vetor);
    return;
}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10};
    printf("\n\n\n******************** Escolha seu algoritmo *******************");
	printf("\n1.Bubble sort");
	 printf("\n2.Selection sort");
	 printf("\n3.Insertion sort");
     printf("\n0.Sair");
	 printf("\nEntre sua opcao : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: bubble(vetor);
			    break;
		 case 2: selection(vetor);
			    break;
		 case 3: insertion(vetor);
			    break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

  return 0; 
} 