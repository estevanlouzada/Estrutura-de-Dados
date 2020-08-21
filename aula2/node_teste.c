#include<stdio.h>
#include<stdlib.h>

//definindo estrutura no -> valor  e *proximo
typedef struct no {
int valor;
struct no *proximo;
} no;

int main(void)
{

    no *e1, *e2, *e3 ;
    e1 = (no *)malloc(sizeof(no));
    e2 = (no *)malloc(sizeof(no));
    e3 = (no *)malloc(sizeof(no));

    e1->valor = 2;
    e2->valor = 3;
    e3->valor = 4;

    e1->proximo = e2;
    e2->proximo = e3;
    e3->proximo = NULL;

    no *interador  = e1;

    while(interador->proximo == NULL){
        printf("%i ,\n ",interador->valor);
        interador = interador->proximo;
    }
    


}