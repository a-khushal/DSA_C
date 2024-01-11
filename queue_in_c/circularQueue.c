#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define QUEUESIZE  100
struct queue 
 {
     char items[QUEUESIZE] [200 ]    ;
     int front ;
     int rear ;
     int count;
};



void enqueue( struct queue *q, char  msg[ ] )
{
     if( q->count == QUEUESIZE )
     {
             printf("QUEUE OVERFLOW");
             exit(0);
     } 
    q->rear = (q->rear +1)% QUEUESIZE;
    strcpy( q->items[q->rear] , msg);
    q->count++;
}

void  dequeue(struct queue *q, char msg [ ])
{
    if(q->count==0)
     {
             printf("QUEUE UNDERFLOW");
             exit(0);
     } 
    q->front = (q->front +1)%QUEUESIZE;
    strcpy(msg,q->items[q->front]);
     q->count--;
    
}


void display( struct queue  *q)
{
     int i,pos ;
     if(q->count==0)
     {
             printf("QUEUE UNDERFLOW");
             return;
     } 
     printf("Messages in Queue are \n");
     pos = (q->front +1)%QUEUESIZE;
     for(i =1; i<=q->count; i++)
      {     
           printf("   %s",q->items[pos]);
           pos = (pos +1)%QUEUESIZE;
      }
}
    
int main()
{
   
  int choice;
  char  x[200];  
  struct queue mcq ; 

  mcq.front = QUEUESIZE-1;
  mcq.rear = QUEUESIZE-1;
  mcq.count =0;

  printf("Demonstration of Working of data structure MESSAGE QUEUE\n\n");
  while(1)
  {
     
     printf("\n1:Insert\n2:Delete\n3:Display\n4:exit ");
     printf("\nEnter the Choice :");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1:printf("Enter the Message to be sent ");
               scanf("%s",x);
               enqueue(&mcq,x);
               break;
        case 2:dequeue(&mcq,x);
               printf("Removed message  is %s",x);
               break;
        case 3 :display(&mcq);
                break;
        default:exit(0);

     }
  }
}  