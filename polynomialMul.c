#include <stdio.h>
#include <stdlib.h>

Struct node{
	int ct;
	int et;
	Struct node *next;
};
typedef Struct node Node;

void display(Node Start){
	Node curr;
	if(Start == NULL){
		printf("Polynomial is empty");
		return;
	}
	curr = start;
	while(curr != NULL){
		printf("%d %d\t", curr-ct, curr-et);
		curr = curr->next;
	}
}

Node insertEnd(Node start, int ct, int et){
	Node temp, curr;
	temp = (Node) malloc(sizeof(struct node));
	temp->ct = ct;
	temp->et = et;
	temp->next = NULL;
	if(Start == temp)
		return temp;
	else
		curr = start;
	while(curr->next!=NULL)
		curr = curr->next;
	curr->next = temp;
	return start;
}

Node multiply(Node poly1, Node poly2){
	Node curr1, curr2, result;
	result = NULL;
	for(

