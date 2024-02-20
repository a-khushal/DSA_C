#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
  char data;
  struct node* left;
  struct node* right;
};

struct stack{
  int top;
  struct node* data[15];
};

void push(struct stack* s, struct node* node){
  s->data[++(s->top)] = node;
}

struct node* pop(struct stack* s){
  return s->data[(s->top)--];
}

void preorder(struct node* root){
  if(root==NULL){
      return; 
  }
  printf("%c ", root->data);
  preorder(root->left);
  preorder(root->right);
}


void inorder(struct node* root){
  if(root==NULL){
    return; 
  }
  inorder(root->left);
  printf("%c ", root->data);
  inorder(root->right);
}

void postorder(struct node* root){
  if(root==NULL){
    return; 
  }
  postorder(root->left);
  postorder(root->right);
  printf("%c ", root->data);
}

struct node* createNode(char item){
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->data = item;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

int precedence(char ch){
  if(ch == '^'){
    return 3;
  } else if (ch == '*' || ch == '/'){
    return 2;
  } else if (ch == '+' || ch == '-'){
    return 1;
  } else {
    return -1;
  }
}

struct node* expressionTress(char infix[]){
  struct stack* ts = (struct stack*)malloc(sizeof(struct stack));
  struct stack* os = (struct stack*)malloc(sizeof(struct stack));
  struct node* osEle;
  struct node* tsEle1;
  struct node* tsEle2;
  ts->top = -1;
  os->top = -1;
  for(int i=0; infix[i]!='\0'; i++){
    if(isalnum(infix[i])){
      struct node* temp = createNode(infix[i]);
      push(ts, temp);
    } else {
      struct node* temp = createNode(infix[i]);
      if(os->top == -1){
        push(os, temp);
      } 
      else {
        while(os->top!=-1 && (precedence(os->data[os->top]->data) > precedence(temp->data))){
          osEle = pop(os);
          osEle->right = pop(ts);
          osEle->left = pop(ts);
          push(ts, osEle);
        } 
        push(os, temp);
      }
    }
  }
  while(os->top!=-1){
    struct node* temp  = pop(os);
    temp->right=pop(ts);
    temp->left=pop(ts);
    push(ts, temp);
	}
  return pop(ts);
}

int main(void){
  char infix[15];
  printf("Enter the infix expression: ");
  scanf("%s", infix);
  struct node* root = expressionTress(infix);
  inorder(root);
  printf("\n");
  return 0;
}

