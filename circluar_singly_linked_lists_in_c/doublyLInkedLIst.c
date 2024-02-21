// two ptrs for each node: prev and next;
// head->prev = NULL;
// lastnode->next = NULL;

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct node* insertBegin(struct node* head, int val){
    struct node* newNode = createNode(val);
    newNode->next = head;
    if(head!=NULL)
        head->prev = newNode;
    head = newNode;
    return newNode;
}

struct node* insertEnd(struct node* head, int val){
    if(head == NULL){
        head = insertBegin(head, val);
        return head;
    }
    struct node* newNode = createNode(val);
    struct node* curr = head;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}

struct node* deleteBegin(struct node* head){
    struct node* temp = head;
    if(temp->next == NULL){
        free(temp);
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

struct node* deletion(struct node* head, int val){
    if(head->prev == NULL){
        head = deleteBegin(head);
        return head;
    }
    struct node* temp = head;
    while(temp->data != val){
        temp = temp->next;
    }
    if(temp->next == NULL){
        temp->prev->next = NULL;
        free(temp);
        return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void){
    struct node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    head = insertBegin(head, 10);
    display(head);
    head = deletion(head, 10);
    display(head);
    return 0;
}