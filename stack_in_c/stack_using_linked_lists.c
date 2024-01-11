#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* push(struct node* head, int val){
	struct node* n = (struct node*) malloc(sizeof(struct node));
	n->data = val;
	n->next = head;
	head = n;
	return head;
}

struct node* pop(struct node* head){
	if(head==NULL){
		printf("Stack underflow\n");
		return NULL;
	}
	struct node* temp = head;
	head = head->next;
	free(temp);
	return head;
}

void peek(struct node* head){
	if(head==NULL){
		printf("Stack underflow\n");
        return;
    }
	printf("Top element of the stack is: %d\n", head->data);
}

void display(struct node* head){
	struct node* temp = head;
	while(temp != NULL){
		printf("%d\n", temp->data);
		temp=temp->next;
	}
}

void empty(struct node* head){
	if(head == NULL)
		printf("stack is empty\n");
	else
		printf("stack isn't empty\n");
}

int main(void){
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head = NULL;
	
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 4);
	head = push(head, 5);
	head = pop(head);
	display(head);
	peek(head);
	empty(head);
	return 0;
}
