#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// criando uma pilha char 
typedef struct node {
    char value;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
}Stack;

// inicializador 
Stack *inicializacao(){
Stack *p;
p = (Stack *)malloc(sizeof(Stack));
p->top = NULL;
return p;
}
//inserir
void Push(Stack *p, char c ){
    if(p != NULL){
    Node *no;
    no = (Node *)malloc(sizeof(Node));
    no->next = p->top;
    no->value = c;
    p->top = no;
    }else {
        printf("erro :ponteiro de pilha NULL para push\n");
    }
}
// retirada 
char Pop(Stack *p)
{
    char saida;
    if( p->top != NULL && p != NULL ){
    Node *aux = p->top;
    saida = p->top->value;
    p->top = p->top->next;
    free(aux);
    aux = NULL;
    }else {
        saida = '0';
        printf("erro: a pilha estava vazia nao tinha elelmentos ou p era null\n");
    }
    return saida;

}

int lenStack(Stack *p)
{
    int count = 1;
    Node *aux = p->top->next;
  while(aux)
  {
    count ++;
    aux = aux->next;
  }
  return count;
}

void ope(float c1, float c2, char op, float *saida){
    
    if(op == '+'){
          *saida =  c1 + c2 ;
    }else if(op == '-'){
            *saida =  c1 - c2 ;
    }else if(op == '*'){
            *saida =  c1 * c2 ;
    }else if(op == '/'){
            *saida =  c1 / c2 ;
    }else {
        printf("\n operacao invalida ");
        
    }
    
}

float calculadora(char *str)
{
    Stack *p = inicializacao();
    float result;
for(int i = 0; i < strlen(str); i++)
{
    if((int)str[i] - '0' >= 0 && (int)str[i] - '0' <= 9)
    {
        printf("\n é numero");
        Push(p,str[i]);
    }else {
        printf("\n nao é numero");
        if(lenStack(p) >= 2)
        {
            float p1 = (float)Pop(p) - '0';
            float p2 = (float)Pop(p) - '0';
           
            ope(p1, p2, str[i], &result);           
            Push(p, (char)result);
        }
    }
}
return result;

}

int main (void)
{
    Stack *p = inicializacao();
    Push(p, '7');
    Push(p, '4');
    Push(p, '1');
    printf("%i, o tamanho da pilha \n", lenStack(p));
    Pop(p);
    Pop(p);
    Pop(p);
    char *calcula = "14+3";
    printf("\n O valor calculado foi , %f \n", calculadora(calcula));
  
}