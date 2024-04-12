#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 20

struct stack{
	int top;
	int data[SIZE];
};

void push(struct stack* s, int item){
	s->data[++(s->top)]=item;
}

int pop(struct stack* s){
	return s->data[(s->top)--];
}

int operate(int op1, int op2, char symbol){
	switch(symbol){
		case '+':
			return op1+op2;
			break;
		case '-':
			return op1-op2;
			break;
		case '*':
			return op1*op2;
			break;
		case '/':
			return op1/op2;
			break;
		case '^':
			return pow(op1, op2);
			break;
		default: 
			return -1;
	}
}


int eval(struct stack* s, char prefix[SIZE]){
	int i;
	char symbol;
	int res, op1, op2;
	
	for(i=strlen(prefix)-1; i>=0; i--){
		symbol=prefix[i];
		if(isdigit(symbol)){
			push(s, symbol-'0');
		}
		else{
			op1=pop(s);
			op2=pop(s);
			res=operate(op1, op2, symbol);
			if(res == -1){
				printf("Invalid operator found\n");
				return -1;
			}
			push(s, res);
		}
	}
	return pop(s);
}

int main(){
	struct stack* s = (struct stack*) malloc(sizeof(struct stack));
	s->top=-1;
	char prefix[SIZE];
	int ans;
	printf("Enter the prefix expression: ");
	scanf("%s", prefix);
	ans=eval(s, prefix);
	printf("The answer is: %d\n", ans);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
