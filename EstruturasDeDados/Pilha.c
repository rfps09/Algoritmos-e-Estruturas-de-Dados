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
    void (*push)(struct Pilha*,int);
    void (*pop)(struct Pilha*);
    int (*top)(struct Pilha*);
} Pilha;

void pilha_push(Pilha* pilha,int value) {
    Node *top = node();
    top->value = value;
    top->previous = pilha->topo;
    pilha->topo = top;
}

void pilha_pop(Pilha *pilha) {
    Node *prev = pilha->topo->previous;
    free(pilha->topo);
    pilha->topo = prev;
}

int pilha_top(Pilha *pilha) {
    return pilha->topo->value;
}

Pilha* pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->push = pilha_push;
    pilha->pop = pilha_pop;
    pilha->top = pilha_top;
}

int main() {
    Pilha *stack = pilha(); 

    stack->push(stack,10);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->push(stack,20);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->push(stack,30);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->pop(stack);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->pop(stack);

    printf("Topo Da stack: %d\n", stack->top(stack));

    stack->pop(stack);

    free(stack);

    return 0;
}