#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

char stackarr[MAX_SIZE];
int top=-1;

int push(char ch){
    if(top>=MAX_SIZE-1){
        printf("Stack overflow!\n");
        return 0;
    }
    stackarr[++top] = ch;
}

void pop(){
    if(top==-1){
        printf("Stack underflow!\n");
        return;
    }
    top--;
}

int isEmpty(){
    return top<=-1;
}

void validParanthesis(char st[]){
    for(int i=0; st[i]!='\0'; i++){
        if(st[i]=='{' || st[i]=='(' || st[i]=='['){
            push(st[i]);
        }
        else{
            if((stackarr[top]=='(' && st[i]==')') || (stackarr[top]=='{' && st[i]=='}') || (stackarr[top]=='[' && st[i]==']')){
                pop();
                continue;
            }
            else
                printf("Invalid Paranthesis");
                return;
        }
    }
    printf("Valid Paranthesis");
    return;
}


int main(void){
    validParanthesis("{()[{()}]}");
    return 0;
}