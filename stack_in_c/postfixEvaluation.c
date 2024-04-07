#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

int top = -1;
int stackarr[MAX_SIZE];

void push(int c) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow");
    }
    stackarr[++top] = c;
}

int pop() {
    if (top <= -1) {
        return -1;
    }
    return stackarr[top--];
}

int isempty() { 
    return top <= -1;    
}

int operation(char c, int num1, int num2) {
    switch (c) {
        case '$': {
            return num1 * num2;
            break;
        }
        case '*': {
            return num1 * num2;
            break;
        }
        case '+': {
            return num1 + num2;
            break;
        }
        case '-': {
            return num1 - num2;
            break;
        }
        case '/': {
            return num1 / num2;
            break;
        }
        default:{
            return -1;
        }
    }
}

void postfixEvaluation(char st[]) {
    for (int i = 0; i < strlen(st); i++) {
        if (st[i] >= '0' && st[i] <= '9') {
            push(st[i]-'0');
        } else {
            int num2 = pop();
            int num1 = pop();
            int result = operation(st[i], num1, num2);
            if (result == -1) {
                printf("Invalid operation");
                return;
            }
            push(result);
        }
    }
    printf("result: %d", stackarr[top]);
    printf("\n");
}

int main(void) {
    postfixEvaluation("632-5*+1$7+");
    return 0;
}