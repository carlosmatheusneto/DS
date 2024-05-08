#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
} node;

typedef struct{
    node *head;
    node *tail;
    int size;
} linkedList;

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

void deleteLinkedList(linkedList *list, int position){

}

void printLinkedList(linkedList *list){
    node *temp = list->head; 
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}


int main(){
    linkedList testList = { 
        .head = NULL,
        .tail = NULL,
        .size = 0
    };
    pushFrontLinkedList(&testList, 1);
    pushFrontLinkedList(&testList, 2);
    pushFrontLinkedList(&testList, 3);
    pushFrontLinkedList(&testList, 4);
    pushFrontLinkedList(&testList, 5);
    insertLinkedList(&testList, 15, 2);
    printLinkedList(&testList);
    printf("size : %d\n", testList.size);
    return 0;
}