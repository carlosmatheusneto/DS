#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "components/node.h"

typedef struct{
    node *head;
    node *tail;
    int size;
} queue;

void enQueue(queue *queue, int data);

void deQueue();

int *front();

bool isEmpty();

void printQueue(queue *queue);

#endif