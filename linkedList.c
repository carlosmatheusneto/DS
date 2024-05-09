#include "linkedList.h"

void pushFrontLinkedList(linkedList *list, int data){
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;  
    }  
    temp->link = list->head;
    temp->data = data;
    if(list->head == NULL){
        list->tail = temp;
    }
    list->head = temp;
    list->size++;
}

void pushBackLinkedList(linkedList *list, int data){
    node *temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;  
    }
    temp->link = NULL;
    temp->data = data;
    if(list->tail == NULL){
        list->head = temp;
    }
    list->tail->link = temp;
    list->size++;

}

void insertLinkedList(linkedList *list, int data, int position){
    if((position > list->size) | (position <= 0)){
        return;
    }
    node *temp = (node*)malloc(sizeof(node*));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;  
    }
    temp->data = data;
    node *temp2 = list->head;
    int i = 0;
    if(position == 1){
        temp->link = temp2;
        list->head = temp;
        list->size++;
        return;
    }
    while(i < position - 2){
        temp2 = temp2->link;
        i++;
    }
    temp->link = temp2->link;
    temp2->link = temp;
    list->size++;
};

void removeLinkedList(linkedList *list, int position){
    if((position > list->size) | (position <= 0)){
        return;
    }
    node *temp = list->head;
    int i = 0;
    if(position == 1){
        list->head = list->head->link;
        free(temp);
        list->size--;
        return;
    }
    node *temp2;
    while(i < position - 2){
        temp2 = temp->link;
        i++;
    }
    temp->link = temp2->link;
    free(temp2);
    list->size--; 
}

void printLinkedList(linkedList *list){
    node *temp = list->head; 
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}