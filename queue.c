#include "queue.h"


void enQueue(queue *queue, int data){
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;
    }
    temp->link = NULL;
    temp->data = data;
    if(queue->head == NULL){
        queue->head = temp;
        queue->tail = temp;
        queue->size++;
        return;
    }
    temp->link = queue->tail;
    queue->tail = temp;
    queue->size++;
}


void deQueue(){

}

int *front(){

    return NULL;
}

bool isEmpty(){

    return false;
}

void printQueue(queue *queue){
    node *temp = queue->head; 
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}