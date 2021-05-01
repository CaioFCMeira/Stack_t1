#include <stdio.h>
#include <stdlib.h>
#include "stack_ctr.h"

/*Local Variable*/
int nodeNbr= -1;

/*Local Functions*/
void storeMin(MyStack ** novo, MyStack ** old);


int isEmpty(MyStack * stack)
{
     if(stack != NULL)
     {
        return 0;
     }
 return 1;
}

void push(MyStack ** stack, float elemento)
{
     MyStack * novo = (MyStack*)malloc(sizeof(MyStack));
     MyStack * aux = *(stack);
     if(novo) // se conseguiu alocar
     {
         nodeNbr++;
         novo->dado = elemento; // Armazena o valor pedido
         novo->prox = aux; // Aponta o proximo elemento para o antigo primeiro
         *(stack) = novo; // Coloca o novo primeiro
         storeMin(&novo, &aux);
     }
 }

 void storeMin(MyStack ** novo, MyStack ** old)
 {
     MyStack * auxNovo = *(novo);
     MyStack * auxOld = *(old);

     if(nodeNbr == 0)
     {
        auxNovo->minValue = &auxNovo->dado;
     }
     else
     {
        if(auxNovo->dado < *auxOld->minValue)
        {
            auxNovo->minValue = &auxNovo->dado;
        }
        else
        {
            auxNovo->minValue = auxOld->minValue;
        }
     }
 }

int pop(MyStack ** stack)
{
    MyStack * aux = *(stack);
    if(!isEmpty(aux)) // Se a stack nao estiver vazia
    {
     *(stack) = aux->prox; // Tira da lista
     free(aux); // Libera na memória
     nodeNbr--;
    }
    if(nodeNbr<0)
    {
        return 0;
    }
    return 1;
}

float top(MyStack * stack, int * hasTop)
{
    * hasTop = 1;
     if(!isEmpty(stack)) // Se a lista não estiver vazia
     {
        return stack->dado; // Retorna o valor do topo
     }
     *hasTop = 0;
}


float min(MyStack ** stack, int * ok)
{
     * ok = 0;
     MyStack * aux = *(stack);
     if(!isEmpty(aux)) // Se a stack nao estiver vazia
     {
        * ok = 1;
        return *aux->minValue;
     }
 }

