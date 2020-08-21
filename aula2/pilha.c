#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct element {
    int value;
    struct element *prox;
}Element;

typedef struct pilha {
    Element *topo;
}Pilha;

Pilha *InicializaPilha()
{
    Pilha *p;
    p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void Push(Pilha *p, int valor)
{
    if(p != NULL){
    Element *node;
    node = (Element *)malloc(sizeof(Element));
    node->value = valor;
    node->prox = p->topo;
    p->topo = node;
    }
}
int Pop(Pilha *p)
{
    if(p != NULL && p->topo != NULL){
    Element *aux;
    aux = p->topo;
    p->topo = p->topo->prox;
    int valor;
    aux->value = valor;
    free(aux);
    aux = NULL;
    return valor;
    }
}

int PushCondicional(Pilha *p, int valor)
{

    // pilha de pares e impares
     if( p->topo == NULL)
    {
     Push( p , valor);
     return 0;
    }else if(p->topo->value%2 == 0 && valor%2 == 0 && p != NULL )
    {
       Push( p , valor);
       return 0;
    }else if(p->topo->value%2 != 0 && valor%2 != 0 && p != NULL )
    {
       Push( p , valor);
       return 0;
    }else {
        return 1;
    }
    
}


int main (void)
{
  
 char *str = "12+"; 


     /*
    Pilha *p;
   p = InicializaPilha();
   printf("%i",PushCondicional(p, 0) );
     printf("%i",PushCondicional(p, 2));
      printf("%i",PushCondicional(p, 3));

*/
}


