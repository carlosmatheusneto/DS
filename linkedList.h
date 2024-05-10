#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "components/node.h"

typedef struct{
    node *head;
    node *tail;
    int size;
} linkedList;

void pushFrontLinkedList(linkedList *list, int data);
void pushBackLinkedList(linkedList *list, int data);
void insertLinkedList(linkedList *list, int data, int position);
void printLinkedList(linkedList *list);
void removeLinkedList(linkedList *list, int position);

#endif
