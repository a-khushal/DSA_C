#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insertAtHead(struct node* head, int val){
    struct node* newHead = (struct node*) malloc(sizeof(struct node));
    newHead->data = val;
    newHead->next = head;
    return newHead;
}

struct node* insertAtEnd(struct node* head, int val){

    if(head==NULL){
        return insertAtHead(head, val);
    }

    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    
    // to find the last node of the list
    struct node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;

    return head;
}

struct node* deleteAtEnd(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;

    while(curr->next != NULL){
        prev = curr;
        curr=curr->next;
    }
    prev->next = NULL;
    return head;
}

struct node* deleteAtStart(struct node* head){
    struct node* temp = head->next;
    head = temp;
    return head;
}

struct node* deleteUsingValue(struct node* head, int val){
    struct node* prev = NULL;
    struct node* curr = head;

    while(curr->data!=val){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    return head;
}

void display(struct node* head){
    printf("\n");
    while(head!=NULL){
        printf("%d->", head->data);
        head=head->next;
    }
    printf("NULL");
}

int main(void){

    struct node* head = (struct node*) malloc(sizeof(struct node));
    head = NULL;

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 8);
    display(head);
    head = insertAtHead(head, 10);
    display(head);
    head = deleteAtEnd(head);
    head = deleteAtEnd(head);
    display(head);
    head = deleteAtStart(head);
    display(head);
    head = deleteUsingValue(head, 2);
    display(head);
    
}
