#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

struct node* createCircularSingly(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void enqueue(struct queue* q, int val){
    struct node* newNode = createCircularSingly(val);
    if (q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
    }
    else
        q->rear->next = newNode;
 
    q->rear = newNode;
    q->rear->next = q->front;
}

void dequeue(struct queue* q){
    if(q->front == NULL){
        return;
    }
    
}
