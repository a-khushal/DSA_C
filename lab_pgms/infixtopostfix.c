#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20

struct stack {
	int top;
	char data[SIZE];
};

void push(struct stack* s, char item){
	s->data[++(s->top)]=item;
}

char pop(struct stack* s){
	return s->data[(s->top)--];
}

int precedence(char ch){
	if(ch == '^')
		return 3;
	else if(ch == '*' || ch == '/')
		return 2;
	else if(ch == '+' || ch == '-')
		return 1;
	else 
		return -1;
}

void infixToPostfix(struct stack* s, char infix[SIZE]){
	int j=0;
	char postfix[SIZE];
	for(int i=0; infix[i] != '\0'; i++){
		if(isalnum(infix[i])){
			postfix[j++] = infix[i];
		}
		else if(infix[i]=='('){
            push(s, infix[i]);
        }
        else if(infix[i]==')'){
            while(s->top != -1 &&  s->data[s->top] != '('){
				postfix[j++] = pop(s);
            }
			if(s->top != -1) // this is to pop the opening bracket
				pop(s);
        }
        else{
            while(s->top != -1 && s->data[s->top]!='(' && (precedence(s->data[s->top]))>(precedence(infix[i]))){
				postfix[j++] = pop(s);
            }
            push(s, infix[i]); // push the current character into the stack which had the lesser precedence than the top element of the stack
        }
	}
	while(s->top!=-1){
		postfix[j++] = pop(s);
	}
	postfix[j] = '\0';
	printf("The postfix expression is: %s\n", postfix);
}

int main(){
	/* 	
		without dynamic memory allocation: 
		struct stack s;
		s.top = -1;
		infixToPostfix(&s, infix) pass the address of the stack
		everything else remains the same.
	*/
	struct stack* s = (struct stack*) malloc(sizeof(struct stack));
	s->top = -1;
	char infix[SIZE];
	//	intput: ((A+B)-C*(D/E))+F
	//	output: AB+CDE/*-F+  
	printf("Read the infix expression: ");
	scanf("%s", infix);
	infixToPostfix(s, infix);
	return 0;
}