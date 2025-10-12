#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

struct node {
    int data;
    struct node *next, *prev; //struct principal para andar na lista
}*tmp;

struct listaDupla{
    struct node *inicio, *fim; //struct auxiliar para definir inicio e fim
};

bool ehVazia(struct listaDupla *lista) {
    if (lista->inicio == NULL) {
        return (1);
    } else {
        return (0);
    }
}

void inserir_inicio(struct listaDupla *lista,int elemento) { //passar a struct como parametro 
    tmp = (struct node*) malloc (sizeof(struct node));
	tmp->data=elemento; //salva o valor em elemento que vai para o novo no
    tmp->prev = NULL; //como é no incio o anterior sempre sera nulo
    if(ehVazia(lista)){ //tem nada na lista, o primeiro a ser inserido é o seu
        lista->inicio = tmp;
        lista->fim = tmp;
        tmp->next = NULL;
        return;
    }
    tmp->data = elemento;
	tmp->next = lista->inicio; // faz o novo no virar o inicio
    lista->inicio->prev = tmp; //faz o anterior ao que voce inseriu ser o novo novamente
}

void inserir_fim(struct listaDupla *lista,int elemento) {
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data = elemento;
    tmp->next=NULL;
    if (ehVazia) {
        inserir_inicio(lista, elemento);
    } else {       
        tmp->prev = lista->fim; //troca os ponteiros do inico para o fim 
        lista->fim->next = tmp; //de forma que fique semelhante ao inserir inicio
        lista->fim = tmp;
    }
 }

void inserir_posicao(struct listaDupla *lista,int valor,int posicao){
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data = valor;
    if(!ehVazia(lista)){
        int i = 0;
        struct node *prev, *tmp1 = lista->inicio;
        while(tmp->next != NULL && i < posicao - 1){// aqui ele termina com o prev um atras do tmp com o tmp sendo a posição desejada
            i++;
            prev = tmp1;
            tmp1 = tmp1->next;
        }
        if(posicao == 1){
            printf("O elemento foi inserido no inicio da lista");
            inserir_inicio(lista,valor);
        }else{
            printf("o elemento foi posicionado na posicao %d",posicao);
            tmp->prev = prev;
            prev->next = tmp;
            prev->next = tmp1;
            tmp1->prev = tmp;
        }
    }else inserir_inicio(lista, valor);
};

void apagar(struct listaDupla *lista,int ele) {
	tmp = lista->inicio;
    struct node *pre = tmp;
	while (tmp != NULL) {
		if (tmp->data == ele) {
            if (tmp == lista->inicio) {
                lista->inicio = lista->inicio->next;
                lista->inicio->prev = NULL;
			    free(tmp);
			    return;
			} else {
                pre->next = tmp->next;
                if(tmp->next != NULL){
                    tmp->next->prev = pre;
                }
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

void apagar_inicio(struct listaDupla *lista) {	
	tmp = lista->inicio;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", lista->inicio->data);
        lista->inicio = lista->inicio->next;
        free(tmp);
	}
 }

void apagar_fim(struct listaDupla *lista) {	
	tmp = lista->fim;
	struct node* pre;
	if( lista->fim == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else if (lista->inicio->next == NULL) {
		printf("\nElemento deletado - %d", lista->inicio->data);
		lista->inicio = NULL;
	} else {
		while (tmp->next != NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
        free(pre);
		printf("\nElemento deletado - %d", tmp->data);
	}
}

void imprimirIncio(struct listaDupla *lista) {
	tmp = lista->inicio;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

void imprimirFim(struct listaDupla *lista) {
	tmp = lista->fim;
 	while (tmp->prev != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->prev;
	}
}

int obter_primeiro(struct listaDupla *lista) {
    tmp = lista->inicio;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (lista->inicio->data);
	}
}

int obter_ultimo(struct listaDupla *lista) {
    tmp = lista->inicio;
	struct node* pre;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return 0;
	} else return(lista->fim->data);
	}

void remover_posicao(struct listaDupla *lista,int posicao){
    if(!ehVazia(lista)){
        int i = 0;
        tmp = lista->inicio;
        struct node *pre;
        while(tmp->next != NULL && i < posicao - 1){
            i = i + 1;
            pre = tmp;
            tmp = tmp->next;
        }
        if(posicao == 1) apagar_inicio(lista); 
            else{
            pre->next = tmp->next;
            tmp->next->prev = pre;
            tmp->next = NULL;
            free(tmp);
            }   
    }else printf("A lista esta vazia");
}

int buscar_posicao(struct listaDupla *lista, int posicao){
    tmp = lista->inicio;
    if(tmp != NULL){
        int i = 1;
        while(tmp->next != NULL && i < posicao){
            i++;
            tmp = tmp->next;
        }
        if(i == posicao){
            return tmp->data;
        }else if(posicao > i) return 0;
    }else return 0;
}

int main() { 
    int val, n;
    
    struct listaDupla *lista = malloc(sizeof(struct listaDupla));
    
    lista->fim = NULL;
    lista->inicio = NULL;
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
        printf("\n10.Inserir na posicao");
        printf("\n11.Remover na posicao");
        printf("\n12.Buscar o valor na posicao");
        printf("\n0.Sair");
        printf("\nEntre sua opção : ");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    inserir_fim(lista,val);
                    break;
            case 2: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    inserir_inicio(lista,val);
                    break;
            case 3: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    apagar(lista,val);
                    break;
            case 4: 
                    apagar_inicio(lista);
                    break;
            case 5: 
                    apagar_fim(lista);
                    break;
            case 6: imprimirIncio(lista);
                    break;
            case 13:imprimirFim(lista);
                break;
            case 7: if (ehVazia(lista) == 1) {
                        printf("\nLista vazia");
                    } else {
                        printf("\nLista não vazia");
                    }
                    break;
            case 8: val = obter_primeiro(lista);
                    if (val != 0) {
                        printf("%d", val);
                    }
                    break;
            case 9: val = obter_ultimo(lista);
                    if (val != 0) {
                        printf("%d", val);
                    }
                    break;
            case 10:{
                    int valor, posicao;
                    printf("Digite um valor para ser incerido na posicao desejada:");
                    scanf("%d",&valor);
                    printf("Digite a posicao desejada: ");
                    scanf("%d", &posicao);
                    inserir_posicao(lista,valor,posicao);
                    }
                    break;
            case 11:{
                    int posicao;
                    printf("Digite a posicao que deve ser removida: ");
                    scanf("%d", &posicao);
                    remover_posicao(lista,posicao);
            }
            break; 
            case 12:{
                    int posicao, valor;
                    printf("Digite a posicao que deve ser buscada");
                    scanf("%d", &posicao);
                    valor = buscar_posicao(lista,posicao);
                    if(valor != 0) printf("%d",valor);
                    else printf("nao foi encontrado nenhum valor nessa posicao");
            }
            break;
            case 0: exit(0);
                    break;
            default: printf("\n Opção errada!");
                    break;
            }
        } while(1);

 }#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "lista.h" 

struct node {
    int data;
    struct node *next, *prev; //struct principal para andar na lista
}*tmp;

struct listaDupla{
    struct node *inicio, *fim; //struct auxiliar para definir inicio e fim
};

bool ehVazia(struct listaDupla *lista) {
    if (lista->inicio == NULL) {
        return (1);
    } else {
        return (0);
    }
}

void inserir_inicio(struct listaDupla *lista,int elemento) { //passar a struct como parametro 
    tmp = (struct node*) malloc (sizeof(struct node));
	tmp->data=elemento; //salva o valor em elemento que vai para o novo no
    tmp->prev = NULL; //como é no incio o anterior sempre sera nulo
    if(ehVazia(lista)){ //tem nada na lista, o primeiro a ser inserido é o seu
        lista->inicio = tmp;
        lista->fim = tmp;
        tmp->next = NULL;
        return;
    }
    tmp->data = elemento;
	tmp->next = lista->inicio; // faz o novo no virar o inicio
    lista->inicio->prev = tmp; //faz o anterior ao que voce inseriu ser o novo novamente
}

void inserir_fim(struct listaDupla *lista,int elemento) {
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data = elemento;
    tmp->next=NULL;
    if (ehVazia) {
        inserir_inicio(lista, elemento);
    } else {       
        tmp->prev = lista->fim; //troca os ponteiros do inico para o fim 
        lista->fim->next = tmp; //de forma que fique semelhante ao inserir inicio
        lista->fim = tmp;
    }
 }

void inserir_posicao(struct listaDupla *lista,int valor,int posicao){
    tmp = (struct node*) malloc (sizeof(struct node));
    tmp->data = valor;
    if(!ehVazia(lista)){
        int i = 0;
        struct node *prev, *tmp1 = lista->inicio;
        while(tmp->next != NULL && i < posicao - 1){// aqui ele termina com o prev um atras do tmp com o tmp sendo a posição desejada
            i++;
            prev = tmp1;
            tmp1 = tmp1->next;
        }
        if(posicao == 1){
            printf("O elemento foi inserido no inicio da lista");
            inserir_inicio(lista,valor);
        }else{
            printf("o elemento foi posicionado na posicao %d",posicao);
            tmp->prev = prev;
            prev->next = tmp;
            prev->next = tmp1;
            tmp1->prev = tmp;
        }
    }else inserir_inicio(lista, valor);
};

void apagar(struct listaDupla *lista,int ele) {
	tmp = lista->inicio;
    struct node *pre = tmp;
	while (tmp != NULL) {
		if (tmp->data == ele) {
            if (tmp == lista->inicio) {
                lista->inicio = lista->inicio->next;
                lista->inicio->prev = NULL;
			    free(tmp);
			    return;
			} else {
                pre->next = tmp->next;
                if(tmp->next != NULL){
                    tmp->next->prev = pre;
                }
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

void apagar_inicio(struct listaDupla *lista) {	
	tmp = lista->inicio;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else {
		printf("\nElemento deletado - %d", lista->inicio->data);
        lista->inicio = lista->inicio->next;
        free(tmp);
	}
 }

void apagar_fim(struct listaDupla *lista) {	
	tmp = lista->fim;
	struct node* pre;
	if( lista->fim == NULL) {
		printf("\n Nenhum elemento deletado ");
    } else if (lista->inicio->next == NULL) {
		printf("\nElemento deletado - %d", lista->inicio->data);
		lista->inicio = NULL;
	} else {
		while (tmp->next != NULL) {
			pre=tmp;
			tmp=tmp->next;
		}
		pre->next=NULL;
        free(pre);
		printf("\nElemento deletado - %d", tmp->data);
	}
}

void imprimirIncio(struct listaDupla *lista) {
	tmp = lista->inicio;
 	while (tmp != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->next;
	}
}

void imprimirFim(struct listaDupla *lista) {
	tmp = lista->fim;
 	while (tmp->prev != NULL) {
        printf("\n %d",tmp->data);
	 	tmp = tmp->prev;
	}
}

int obter_primeiro(struct listaDupla *lista) {
    tmp = lista->inicio;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
    } else {
		return (lista->inicio->data);
	}
}

int obter_ultimo(struct listaDupla *lista) {
    tmp = lista->inicio;
	struct node* pre;
	if (lista->inicio == NULL) {
		printf("\n Nenhum elemento encontrado ");
        return 0;
	} else return(lista->fim->data);
	}

void remover_posicao(struct listaDupla *lista,int posicao){
    if(!ehVazia(lista)){
        int i = 0;
        tmp = lista->inicio;
        struct node *pre;
        while(tmp->next != NULL && i < posicao - 1){
            i = i + 1;
            pre = tmp;
            tmp = tmp->next;
        }
        if(posicao == 1) apagar_inicio(lista); 
            else{
            pre->next = tmp->next;
            tmp->next->prev = pre;
            tmp->next = NULL;
            free(tmp);
            }   
    }else printf("A lista esta vazia");
}

int buscar_posicao(struct listaDupla *lista, int posicao){
    tmp = lista->inicio;
    if(tmp != NULL){
        int i = 1;
        while(tmp->next != NULL && i < posicao){
            i++;
            tmp = tmp->next;
        }
        if(i == posicao){
            return tmp->data;
        }else if(posicao > i) return 0;
    }else return 0;
}

int main() { 
    int val, n;
    
    struct listaDupla *lista = malloc(sizeof(struct listaDupla));
    
    lista->fim = NULL;
    lista->inicio = NULL;
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
        printf("\n10.Inserir na posicao");
        printf("\n11.Remover na posicao");
        printf("\n12.Buscar o valor na posicao");
        printf("\n0.Sair");
        printf("\nEntre sua opção : ");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    inserir_fim(lista,val);
                    break;
            case 2: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    inserir_inicio(lista,val);
                    break;
            case 3: printf("\nDigite o valor ");
                    scanf("%d",&val);
                    apagar(lista,val);
                    break;
            case 4: 
                    apagar_inicio(lista);
                    break;
            case 5: 
                    apagar_fim(lista);
                    break;
            case 6: imprimirIncio(lista);
                    break;
            case 13:imprimirFim(lista);
                break;
            case 7: if (ehVazia(lista) == 1) {
                        printf("\nLista vazia");
                    } else {
                        printf("\nLista não vazia");
                    }
                    break;
            case 8: val = obter_primeiro(lista);
                    if (val != 0) {
                        printf("%d", val);
                    }
                    break;
            case 9: val = obter_ultimo(lista);
                    if (val != 0) {
                        printf("%d", val);
                    }
                    break;
            case 10:{
                    int valor, posicao;
                    printf("Digite um valor para ser incerido na posicao desejada:");
                    scanf("%d",&valor);
                    printf("Digite a posicao desejada: ");
                    scanf("%d", &posicao);
                    inserir_posicao(lista,valor,posicao);
                    }
                    break;
            case 11:{
                    int posicao;
                    printf("Digite a posicao que deve ser removida: ");
                    scanf("%d", &posicao);
                    remover_posicao(lista,posicao);
            }
            break; 
            case 12:{
                    int posicao, valor;
                    printf("Digite a posicao que deve ser buscada");
                    scanf("%d", &posicao);
                    valor = buscar_posicao(lista,posicao);
                    if(valor != 0) printf("%d",valor);
                    else printf("nao foi encontrado nenhum valor nessa posicao");
            }
            break;
            case 0: exit(0);
                    break;
            default: printf("\n Opção errada!");
                    break;
            }
        } while(1);

 }