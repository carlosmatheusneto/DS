#ifndef STACK_H
#define STACK_H

#include "linkedList.h"
#include <stdbool.h>

typedef struct{
    node *head;
    int size;
} stack;

void pushStack(stack *stack, int data);
void printStack(stack *stack);
void popStack(stack *stack);
int *topStack(stack *stack);

#endif