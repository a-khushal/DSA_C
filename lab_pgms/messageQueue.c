#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5 // macro
struct queue{
    int front;
    int rear;
    char data[SIZE][20];
};
typedef struct queue Queue;

void enqueue(Queue* q, char msg[20]){
  if(q->front == (q->rear + 1) %  SIZE){
    printf("\nQueue is full");
  }
  else{
    q->rear = (q->rear + 1) % SIZE;
    strcpy(q->data[q->rear], msg);
    if(q->front == -1)
      q->front = 0;
  }
}

char* dequeue(Queue* q){
  char* d;
  if(q->front == -1){
    printf("\nQueue is empty");
    return NULL;
  }
  else{
    d = q->data[q->front];
    if(q->front == q->rear){
      q->front = -1;
      q->rear = -1;
    }
    else
      q->front = (q->front + 1) % SIZE;
    return d;
  }
}

void display(Queue q){
  int i;
  if(q.front == 1){
    printf("\nQueue is empty");
  }
  else{
    printf("\nQueue content are:\n");
    for(i=q.front; i!=q.rear; i = (i+1) % SIZE){
      printf("%s\n", q.data[i]);
    }
    printf("%s\n", q.data[i]);
  }
}

int main(){
  Queue q;
  q.front = -1;
  q.rear = -1;
  int ch;
  char msg[20], *del;
  while(1){
    printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    getchar();
    switch (ch) {
      case 1:{
        printf("\nEnter a message to insert: ");
        gets(msg);
        enqueue(&q, msg);
        break;
      }
      case 2:{
        del = dequeue(&q);
        if(del!=NULL){
          printf("\nMessage deleted is: %s", del);
        }
        break;
      }
      case 3: {
        display(q);  // insertion and deletion is pointer, display non pointer
        break;
      }
      default:{
        exit(0);
      }
    }
  }
  return 0;
}
