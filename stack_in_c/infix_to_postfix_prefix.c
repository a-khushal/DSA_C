#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 50

char res[size]; 
char stackarr[size];
int top = -1;

void push(char ch) {
    if(top==size-1){
        printf("stack overflow\n");
        return;
    }
    stackarr[++top] = ch;
    // Using ++top ensures that the value of top is incremented before it is used in the array index, meaning that the new value is already updated in the array. This is the desired behavior for implementing a stack, where you want to first increment the top index and then assign the value to the updated index in the array. If you used top++, the current value of top would be used in the array index, and then top would be incremented.
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int empty() {
    return top<=-1;
}


int precedence(char ch){
	if(ch=='^')
		return 3;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else
		return -1;
}

void infixToPostfix(char st[]){
    int k=0;
    for(int i=0; i<strlen(st); i++){
        if ((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z')){
            res[k] = st[i];
            k++;
        }
        else if(st[i]=='('){
            push(st[i]);
        }
        else if(st[i]==')'){
            while(!empty() &&  stackarr[top]!= '('){
                res[k] = stackarr[top];
                k++;
                pop();
            }
            if(!empty()){
                pop();
            }
        }
        else{
            while(!empty() && (precedence(stackarr[top]))>(precedence(st[i]))){
                res[k] = stackarr[top];
                k++;
                pop();
            }
            push(st[i]);
        }
    }

    while(!empty()){
        res[k] = stackarr[top];
        k++;
        pop();
    }

    res[k] = '\0';
    printf("%s\n", res);
}
// abc/-ak/l-*


void infixToPrefix(char st[]){
    char newSt[size]; int m=0;
    for(int i=strlen(st)-1; i>=0; i--){
        // newSt[m]='\0';
        if(st[i]==')'){
            newSt[m]='(';
        }
        else if(st[i]=='('){
            newSt[m]=')';
        }
        else 
            newSt[m] = st[i];
        m++;
    }
    // printf("%s\n", newSt);
    int k=0;
    for(int i=0; i<strlen(newSt); i++){
        if((newSt[i]>='a' && newSt[i]<='z')||(newSt[i]>='A' && newSt[i]<='Z')){
            res[k] = newSt[i];
            k++;
        }
        else if(newSt[i]=='('){
            push(newSt[i]);
        }
        else if(newSt[i]==')'){
            while(!empty() && stackarr[top]!='('){
                res[k] = stackarr[top];
                k++;
                pop();
            }
            if(!empty()){
                pop();
            }
        }
        else{
            while(!empty() && (precedence(stackarr[top]))>(precedence(newSt[i]))){
                res[k] = stackarr[top];
                k++;
                pop();
            }
            push(newSt[i]);
        }
    }
    while(!empty()){
        res[k] = stackarr[top];
        k++;
        pop();
    }

    int j=0;
    char result[size];
    for(int i=strlen(res)-1; i>=0; i--){
        result[j] = res[i];
        j++;
    }
    result[j] = '\0';
    printf("%s\n", result);
}
// *-a/bc-/akl

int main(void){
    // infixToPostfix("((A+B)-C*(D/E))+F");
    infixToPostfix("(a-b/c)*(a/k-l)");
    infixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}





