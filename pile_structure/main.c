#include <stdio.h>
#include <stdlib.h>
#include "stack_ctr.h"

void pushItem(float item);
void popItem(void);
float getTop(void);
float getMin(void);
void releaseMem(void);

MyStack * stack = NULL;

int main(){

     float value;
     int opc;

     do {
     printf("\n==================================\n");
     printf("Choose an option:\n");
     printf("1.- Add item\n");
     printf("2.- Remove item\n");
     printf("3.- Show top\n");
     printf("4.- Show smallest item\n");
     printf("5.- Exit\n");
     scanf("%d", &opc);

     switch(opc)
     {
         case 1:
             printf("Type a value: ");
             scanf("%f", &value);
             pushItem(value);
         break;
         case 2:
            popItem();
         break;
         case 3:
            getTop();
         break;
         case 4:
            getMin();
         break;
         case 5:
            releaseMem();
         break;
     }

     }while(opc !=5);

     return 0;
}

void pushItem(float item)
{
    push(&stack, item);
}

void popItem(void)
{
    int dummy;
    if(pop(&stack))
    {
     printf("New value on top is %f\n", top(stack,&dummy));
    }else
    {
     printf("Stack is empty\n");
    }
}

float getTop(void)
{
    int good;
    float stackTop;
    stackTop = top(stack, &good);
    if(good)
    {
        printf("Stack top is %f\n", stackTop);
    }else
    {
        printf("Stack is empty\n");
        return;
    }
    return stackTop;
}

float getMin(void)
{
    int good;
    float sItem;
    sItem = min(&stack, &good);
    if(good)
    {
        printf("Lower item is = %f\n", sItem);
    }else
    {
        printf("Stack is empty\n");
        return;
    }
    return sItem;
}

 void releaseMem(void)
 {
    while(pop(&stack));
    printf("Memory released\n");
 }
