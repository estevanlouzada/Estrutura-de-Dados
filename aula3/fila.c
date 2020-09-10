#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int dado;
    struct elemento *proximo;
} Elemento;

typedef struct fila
{
    Elemento *inicio;
    Elemento *fim;
} Fila;

Fila *inicializaFila()
{
    Fila *f;
    f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void inserir(Fila *f ,int d )
{
    if (f != NULL)
    {
        Elemento *novoDado;
        novoDado = (Elemento *)malloc(sizeof(Elemento));
        novoDado->dado = d;
        novoDado->proximo = NULL;
        if (f->inicio == NULL && f->fim == NULL)
        {
            f->fim = f->inicio = novoDado;
        }
        else
        {
            f->fim->proximo = novoDado;
            f->fim = novoDado;
        }
    }
}

int remover(Fila *f)
{
    if (f != NULL || f->inicio == NULL)
    {
        int saida = f->inicio->dado;
        Elemento *retirado;
        retirado = (Elemento *)malloc(sizeof(Elemento));
        retirado = f->inicio;
        if (f->fim != f->inicio)
        {
            f->inicio = f->inicio->proximo;
        }
        else
        {
            f->fim = f->inicio = NULL;
        }
        free(retirado);
        retirado = NULL;
        return saida;
    }
}


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

int main(void)
{

Fila *fila = inicializaFila();
Pilha *pilha = inicializaPilha();
push(pilha, 10);
inserir(fila, 20);
push(pilha, 30);
inserir(fila, 40);
inserir(fila, pop(pilha));
push(pilha, remover(fila));
inserir(fila, remover(fila));
push(pilha, pop(pilha));

printf("%d; %d; %d; %d;", remover(fila), pop(pilha), pop(pilha), remover(fila));
    return 0;
}
