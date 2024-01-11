#include <stdio.h>
#include <stdlib.h>

int queue[100];
int n;

int front = -1;
int rear = -1;

void enqueue(int val){
    if(rear >= n-1){
        printf("queue overflow!\n");
        return;
    }
    rear++;
    queue[rear] = val;
    if(front == -1){
        front++;
    }
}

void dequeue(){
    if(front==-1||front>rear){
        printf("No elements to pop!\n");
        return;
    }
    printf("%d popped from the queue", queue[front]);
    front++;
}

void peek(){
    if(front==-1||front>rear){
        printf("No elements in the queue!\n");
        return;
    }
    printf("peek element of the queue: %d", queue[front]);
}

void isEmpty(){
    if(front==-1||front>rear){
        printf("queue is empty!\n");
        return;
    }
    printf("queue isn't empty\n");
}

void display(){
    if (front == -1 || front > rear){
        printf("No elements in the queue!\n");
        return;
    }

    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(void){
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
}