#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int item;
    struct node* next;
} node;

node* createNode(){
    node* newNode = (struct node*)malloc(sizeof(node));
    return newNode;
}

void insertAtHead(node** head,int data){
    node* newNode = createNode();
    newNode ->item = data;
    newNode ->next = *head;
    *head = newNode;
}

void insertAtTail(node** head, int data){
    node* newNode = createNode();
    newNode -> item = data;
    newNode -> next = NULL;
    printf("%d",newNode->item);
    if(*head ==NULL){
        *head = newNode;
        return;
    }
    struct node* temp= *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
}

void displayList(node* head){
    node* temp = head;
    if(head != NULL){
    printf("\n");
    while(temp->next != NULL){
        printf("%d\t",temp->item);
    }
    }
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head,25);
    displayList(head);
    return 0;
}
