#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components/node.h"

typedef struct{
    node *head;
    int size;
} stack;

void pushStack(stack *stack, int data);
void printStack(stack *stack);
void popStack(stack *stack);
int *topStack(stack *stack);

#endif