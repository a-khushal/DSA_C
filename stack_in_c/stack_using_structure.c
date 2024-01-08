#include <stdio.h>
#include <stdlib.h>
#define size 5

struct node{
    int top;
    int data[size];
};

void push(struct node* s, int val){
    if((s->top) > size-2){
        printf("Stack overflow!\n");
        return;
    }
    s->top = s->top + 1;
    s->data[s->top] = val;
}

void pop(struct node* s){
    if((s->top) == -1){
        printf("stack underflow!");
        return;
    }
    s->top = s->top - 1;
    printf("popped\n");
}

int main(void){
    struct node* s = (struct node*) malloc(sizeof(struct node));
    s->top = -1;
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    pop(s);
    for(int i=s->top; i>=0; i--){
        printf("%d\n", s->data[i]);
    }
}