//int stackSize = 0;

typedef struct stack {
     float dado;
     float * minValue;
     struct stack * prox;
}MyStack;

int isEmpty(MyStack * stack);
void push(MyStack ** stack, float elemento);
int pop(MyStack ** stack);
float top(MyStack * stack, int * hasTop);
float min(MyStack ** stack, int * ok);
