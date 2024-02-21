#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 15

struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct stack{
    int top;
    struct node* data[SIZE];
};

void push(struct stack* s, struct node* item){
    s->data[++(s->top)] = item;
}

struct node* pop(struct stack* s){
    return s->data[(s->top)--];
}

void preOrder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

void postOrder(struct node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

int precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else 
        return -1;
}

struct node* ExpressionTree(char infix[]){
    struct stack* ts = (struct stack*)malloc(sizeof(struct stack));
    struct stack* os = (struct stack*)malloc(sizeof(struct stack));
    ts->top = -1;
    os->top = -1;
    for(int i=0; infix[i]!='\0'; i++){
        struct node* temp = (struct node*) malloc(sizeof(struct node));
        temp->data = infix[i];
        temp->right = NULL;
        temp->left = NULL;
        if(isalnum(temp->data)){
            push(ts, temp);
        } else {
            if(os->top == -1){
                push(os, temp);
            } else {
                while(os->top != -1 && (precedence((os->data[os->top])->data) >= precedence(temp->data))){
                    struct node* osEle = pop(os);
                    osEle->right = pop(ts);
                    osEle->left = pop(ts);
                    push(ts, osEle);
                } 
                push(os, temp);    
            }
        }
    }
    while(os->top != -1){
        struct node* osEle = pop(os);
        osEle->right = pop(ts);
        osEle->left = pop(ts);
        push(ts, osEle);
    }
    return pop(ts);
}

int main(void){
    printf("Enter the infix expression: ");
    char infix[15];
    scanf("%s", infix);
    struct node* root = ExpressionTree(infix);
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    return 0;
}
