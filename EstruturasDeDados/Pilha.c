#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *previous;
} Node;

Node* node() {
    Node *node = malloc(sizeof(Node));
    node->value = 0;
    node->previous = NULL;
    return node;
}

typedef struct Pilha {
    Node *topo;
    int size;
    void (*push)(struct Pilha*,int);
    void (*pop)(struct Pilha*);
    int (*top)(struct Pilha*);
    short int (*empty)(struct Pilha*); 
} Pilha;

void pilha_push(Pilha* pilha,int value) {
    Node *top = node();
    top->value = value;
    top->previous = pilha->topo;
    pilha->topo = top;
    pilha->size++;
}

void pilha_pop(Pilha *pilha) {
    Node *prev = pilha->topo->previous;
    free(pilha->topo);
    pilha->topo = prev;
    if(pilha->size > 0)pilha->size--;
}

int pilha_top(Pilha *pilha) {
    return pilha->topo->value;
}

short int pilha_empty(Pilha *pilha) {
    return pilha->size == 0;
}

Pilha* pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->size = 0;
    pilha->push = pilha_push;
    pilha->pop = pilha_pop;
    pilha->top = pilha_top;
    pilha->empty = pilha_empty;

    return pilha;
}

int main() {
    Pilha *stack = pilha(); 

    stack->push(stack,10);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->push(stack,20);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->push(stack,30);

    while(!stack->empty(stack)) {
        printf("Topo Da stack: %d\n", stack->top(stack));

        stack->pop(stack);
    }

    free(stack);

    return 0;
}