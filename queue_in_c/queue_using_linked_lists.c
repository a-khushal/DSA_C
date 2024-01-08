#include <stdio.h>
#include <stdlib.h>

#define size 10

struct node{
    int f;
    int r;
    int data[size];
};

void enqueue(struct node* q, int val){
    if(q->r == size-1){
        printf("queue's full\n");
        return;
    }
    q->data[++(q->r)] = val;
    if(q->f==-1){
        (q->f)++;
    }
}

void dequeue(struct node* q){
    if((q->f) == -1 || (q->f) > (q->r)){
        printf("queue's empty\n");
        return;
    }
    q->f++;
}

void display(struct node* q){
    for(int i=q->f; i<=q->r; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void peek(struct node* q){
    printf("peek of the queue: %d\n", q->data[q->f]);
}

int main(void){
    struct node* queue = (struct node*) malloc(sizeof(struct node));
    queue->f = -1;
    queue->r = -1;
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    dequeue(queue);
    peek(queue);
    display(queue);
}