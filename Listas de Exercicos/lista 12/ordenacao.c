#include <stdio.h> 
#include <stdlib.h> 
#include "ordenacao.h"
  
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

void mergeSortRec(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSortRec(vetor, inicio, meio);
        mergeSortRec(vetor, meio + 1, fim);

        int n1 = meio - inicio + 1;
        int n2 = fim - meio;

        int esquerda[n1], direita[n2];

        for (int i = 0; i < n1; i++)
            esquerda[i] = vetor[inicio + i];
        for (int j = 0; j < n2; j++)
            direita[j] = vetor[meio + 1 + j];

        int i = 0, j = 0, k = inicio;

        while (i < n1 && j < n2) {
            if (esquerda[i] <= direita[j]) {
                vetor[k] = esquerda[i];
                i++;
            } else {
                vetor[k] = direita[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            vetor[k] = esquerda[i];
            i++;
            k++;
        }

        while (j < n2) {
            vetor[k] = direita[j];
            j++;
            k++;
        }
    }
}

void merge(int *vetor) {
    
    mergeSortRec(vetor, 0, 49);
    imprimir(vetor);
    return;

}

int particiona(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];  
    int i = inicio - 1;     
    for (int j = inicio; j < fim; j++) {
        if (vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return (i + 1);  
}

void quickSortRec(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particiona(vetor, inicio, fim);

        quickSortRec(vetor, inicio, pi - 1);
        quickSortRec(vetor, pi + 1, fim);
    }
}


void quick(int *vetor) {
    
    quickSortRec(vetor, 0, 49);
    imprimir(vetor);
    return;

}

int main() { 
  // Vetor aleatório de 50 posições
  
  int n;
  do {
    int vetor[50] = {40, 32, 24, 25,  1, 48, 38,  7, 17,  8, 42,  4, 44, 45, 27, 49, 30, 18,  6, 23,  5, 41, 33, 26, 28,  3, 37, 19, 11, 43, 39, 16, 36, 21,  9,  2, 47, 12, 50, 20, 14, 29, 35, 46, 13, 34, 31, 15, 10, 2};
    printf("\n\n\n******************** Escolha seu algoritmo *******************");
	printf("\n1.Bubble sort");
	 printf("\n2.Selection sort");
	 printf("\n3.Insertion sort");
     printf("\n4.Merge sort");
     printf("\n5.Quick sort");
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
        case 4: merge(vetor);
			    break;
        case 5: quick(vetor);
			    break;
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

  return 0; 
} 