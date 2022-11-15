#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha {
    int size;
    int value;
    struct Pilha *previous;
} Pilha;

Pilha* pilha() {
    Pilha* stack = malloc(sizeof(Pilha));
    stack->size = 0;
    stack->value = 0;
    stack->previous = NULL;
    return stack;
}

void pilha_push(Pilha *stack,int value){
    Pilha *aux = new(pilha);
    aux->size = stack->size;
    aux->value = stack->value;
    aux->previous = stack->previous;
    stack->size++;
    stack->value = value;
    stack->previous = aux;
}

void pilha_pop(Pilha *stack){
    Pilha *prev = stack->previous;
    stack->size = prev->size;
    stack->previous = prev->previous;
    stack->value = prev->value;
    free(prev);
}

int pilha_top(Pilha *stack) {
    return stack->value;
}

int main() {
    Pilha *stack = pilha(); 

    pilha_push(stack,10);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    pilha_push(stack,20);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    pilha_push(stack,30);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    pilha_pop(stack);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    pilha_pop(stack);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    pilha_pop(stack);

    printf("Topo Da Pilha: %d\n", pilha_top(stack));

    free(stack);

    return 0;
}