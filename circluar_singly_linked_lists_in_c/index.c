#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createCircularSingly(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node* insertBegin(struct node* head, int val) {
    struct node* newNode = createCircularSingly(val);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    struct node* curr = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = newNode;
    return newNode;
}

struct node* insertEnd(struct node* head, int val) {
    if (head == NULL) {
        return insertBegin(head, val);
    }
    struct node* newNode = createCircularSingly(val);
    struct node* curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head;
    return head;
}

struct node* insertInBetweenTheList(struct node* head, int val, int prevIdx){
    if(head == NULL){
        return NULL;
    }
    struct node* newNode = createCircularSingly(val);
    struct node* curr = head;
    int count = 0;
    while(count != prevIdx){
        curr = curr->next;
        count++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

struct node* deleteBegin(struct node* head){
    struct node* curr = head;
    struct node* temp = head;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteEnd(struct node* head){
    struct node* curr = head;
    while(curr->next->next != head){
        curr=curr->next;
    }
    curr->next = head;
    return head;
}

void display(struct node* head) {
    struct node* curr = head;
    if (head == NULL) return;
    do {
        printf("%d->", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("%d->", curr->data);
    printf("\n");
}

int main(void) {
    struct node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);
    head = insertInBetweenTheList(head, 10, 4);
    display(head);
    // head = deleteBegin(head);
    // head = deleteEnd(head);
    // head = insertBegin(head, 1);
    // display(head);
    return 0;
}
