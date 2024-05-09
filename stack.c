#include "stack.h"

void pushStack(stack *stack, int data){
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;
    }
    temp->link = NULL;
    temp->data = data;
    if(stack->head == NULL){
        stack->head = temp;
        stack->size++;
        return;
    }
    temp->link = stack->head;
    stack->head = temp;
    stack->size++;
}

void popStack(stack *stack){
    if (stack->head == NULL) {
        fprintf(stderr, "Lista esta vazia\n");
        fprintf(stderr, "Prevenindo que de free em um NULL\n");
        return;
    }
    node* temp = stack->head->link;
    free(stack->head);
    stack->head = temp;
    stack->size--;
    return;
}

int *topStack(stack *stack){
    if (stack->head == NULL) {
        return NULL;
    }
    return &(stack->head->data);
}

bool stackIsEmpty(stack *stack){
    return stack->head == NULL;
}

void printStack(stack *stack){
    node *temp = stack->head; 
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
