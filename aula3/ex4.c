#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct pilha {
    Elemento *topo;
} Pilha;

Pilha *inicializaPilha() {
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
	p->topo = NULL;
    return p;
}

void push(Pilha *p , int d) {
    if (p != NULL) 
    {
        Elemento *novoDado;
        novoDado = (Elemento *)malloc(sizeof(Elemento));
        novoDado->dado = d;
        novoDado->proximo = p->topo;
        p->topo = novoDado;
    }    
}

int pop(Pilha *p) {
    if (p != NULL && p->topo != NULL)
    {
        int saida = p->topo->dado;
	    Elemento *aux = p->topo;
        p->topo = p->topo->proximo;
	    free(aux);
	    aux = NULL;
        return saida;
    }
}
void imprimePilha(Pilha *p) {
    Elemento *iterador;
    iterador = p->topo;
    while (iterador != NULL) {
        printf("%i",iterador->dado);
        iterador = iterador->proximo;
    }
	printf("\n");
}

Pilha *pilhatiraOsPrimos(Pilha *p)
{
    Pilha *psaida = inicializaPilha();
   
    while(p->topo)
    {
        int saida = pop(p);
        if(saida % 2 == 0){
            push(psaida, saida);
        }
    }
    return psaida;
}

int main(void){
    Pilha *p = inicializaPilha();
    push(p, 8);
    push(p, 3);
    push(p, 5);
    push(p, 2);
    push(p, 1);
    push(p, 4);

    imprimePilha(pilhatiraOsPrimos(p));
}