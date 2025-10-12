#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

struct node {
    int data;
    struct node *next;
}*p,*tmp,*tmp1;

void inserir_fim(int elemento) {
    tmp = p;
    tmp1 = (struct node*) malloc (sizeof(struct node));
    tmp1->data=elemento;
    tmp1->next=NULL;
    if (p == NULL) {
        p = tmp1;
    } else {
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
 }

void inserir_inicio(int elemento) {
	 tmp = p;
	 tmp1 = (struct node*) malloc (sizeof(struct node));
	 tmp1->data=elemento;
	 tmp1->next = p;
	 p=tmp1;
}

void apagar(int ele) {
    tmp = p;
	struct node *pre=tmp;
	while (tmp != NULL) {
		if (tmp->data==ele) {
            if (tmp == p) {
                p = tmp->next;
			    free(tmp);
			    return;
			} else {
                pre->next=tmp->next;
			    free(tmp);
			    return;
			}
		} else {
            pre = tmp;
		    tmp = tmp->next;
		}
	}
	printf("\n Valor não encontrado! ");
 }
 
void apagar_inicio() {	
	tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", p->data);
		p = p->next;
	}
 }
 
void apagar_fim() {	
	tmp=p;
	struct node* pre;
	if(p == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else if (p->next == NULL) {
		printf("\nElemento deletado - %d", p->data);
		p = NULL;
	} else {
		while (tmp->next != NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
		printf("\nElemento deletado - %d", tmp->data);
	}
}

bool ehVazia() {
    if (p == NULL) {
        return (1);
    } else {
        return (0);
    }
}
void imprimir() {
	tmp = p;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

int obter_primeiro(void) {
    tmp = p;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (p->data);
	}
}

int obter_ultimo(void) {
    tmp = p;
	struct node* pre;
	if (p == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return (0);
    } else if (p->next==NULL) {
		return(p->data);
	} else {
		while (tmp->next!=NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
		return(tmp->data);
	}
}

// Insere valor em uma posição específica (0 = início)
void inserirPosicao(int valor, int posicao) {
    struct node *novo = (struct node*) malloc(sizeof(struct node));
    novo->data = valor;
    novo->next = NULL;

    if (posicao == 0) { // Inserir no início
        novo->next = p;
        p = novo;
        return;
    }

    tmp = p;
    int i = 0;
    while (tmp != NULL && i < posicao - 1) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        printf("\nPosição inválida!");
        free(novo);
    } else {
        novo->next = tmp->next;
        tmp->next = novo;
    }
}

// Remove nó de uma posição específica
void removerPosicao(int posicao) {
    if (p == NULL) {
        printf("\nLista vazia!");
        return;
    }

    tmp = p;
    if (posicao == 0) { // Remover do início
        p = p->next;
        free(tmp);
        return;
    }

    int i = 0;
    struct node *pre = NULL;
    while (tmp != NULL && i < posicao) {
        pre = tmp;
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        printf("\nPosição inválida!");
    } else {
        pre->next = tmp->next;
        free(tmp);
    }
}

// Retorna valor de uma posição específica
int obterPosicao(int posicao) {
    tmp = p;
    int i = 0;
    while (tmp != NULL && i < posicao) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        printf("\nPosição inválida!");
        return -1; // valor de erro
    }
    return tmp->data;
}


void main() { 
  int val, n;
  p = NULL;
  do {
    printf("\n************************* MENU ************************");
	printf("\n1.Inserir no fim");
	printf("\n2.Inserir no início");
	printf("\n3.Apagar um elemento em particular");
	printf("\n4.Apagar do início");
	printf("\n5.Apagar do fim");
	printf("\n6.Imprimir lista");
	printf("\n7.É vazia?");
    printf("\n8.Obter primeiro");
    printf("\n9.Obter último");
    printf("\n10. Inserir em posição");
    printf("\n11. Remover posição");
    printf("\n12. Obter posição");

     printf("\n0.Sair");
	 printf("\nEntre sua opção : ");
	 scanf("%d",&n);
	 switch(n) {
        case 1: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_fim(val);
			    break;
		 case 2: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    inserir_inicio(val);
			    break;
		 case 3: printf("\nDigite o valor ");
			    scanf("%d",&val);
			    apagar(val);
			    break;
		 case 4: 
			    apagar_inicio();
			    break;
		 case 5: 
			    apagar_fim();
			    break;
		 case 6: imprimir();
		 	    break;
		 case 7: if (ehVazia() == 1) {
                    printf("\nLista vazia");
                } else {
                    printf("\nLista não vazia");
                }
                break;
        case 8: val = obter_primeiro();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;
        case 9: val = obter_ultimo();
                if (val != 0) {
                    printf("%d", val);
                }
		 	    break;

        case 10: printf("\nDigite o valor e a posição: ");
         scanf("%d %d", &val, &n);
         inserirPosicao(val, n);
         break;

        case 11: printf("\nDigite a posição: ");
         scanf("%d", &n);
         removerPosicao(n);
         break;

        case 12: printf("\nDigite a posição: ");
         scanf("%d", &n);
         val = obterPosicao(n);
         if (val != -1) printf("Valor na posição %d = %d", n, val);
         break;
        
        case 0: exit(0);
		 	    break;
		default: printf("\n Opção errada!");
		 	    break;
		}
	} while(1);

 }