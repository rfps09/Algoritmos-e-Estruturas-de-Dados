#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int size;
    int top;
    struct Pilha *previous;
    void (*push)(struct Pilha*,int);
    void (*pop)(struct Pilha*);
} Pilha;

Pilha* pilha();

void pilha_push(Pilha *stack,int value){
    Pilha *aux = malloc(sizeof(Pilha));
    memcpy(aux,stack,sizeof(*stack));
    stack->size++;
    stack->top = value;
    stack->previous = aux;
}

void pilha_pop(Pilha *stack){
    Pilha *prev = stack->previous;
    stack->size = prev->size;
    stack->previous = prev->previous;
    stack->top = prev->top;
    free(prev);
}

Pilha* pilha() {
    Pilha* stack = malloc(sizeof(Pilha));
    stack->size = 0;
    stack->top = 0;
    stack->previous = NULL;
    stack->push = pilha_push;
    stack->pop = pilha_pop;
    return stack;
}

int main() {
    Pilha *stack = pilha(); 

    stack->push(stack,10);

    printf("Topo Da Pilha: %d\n", stack->top);

    stack->push(stack,20);

    printf("Topo Da Pilha: %d\n", stack->top);

    stack->push(stack,30);

    printf("Topo Da Pilha: %d\n", stack->top);

    stack->pop(stack);

    printf("Topo Da Pilha: %d\n", stack->top);

    stack->pop(stack);

    printf("Topo Da Pilha: %d\n", stack->top);

    stack->pop(stack);

    printf("Topo Da Pilha: %d\n", stack->top);

    free(stack);

    return 0;
}