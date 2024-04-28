#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node* next;
  int co, po;
};

struct node* insertEnd(struct node* head, int co, int po){
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  struct node* curr;
  newNode->co = co;
  newNode->po = po;
  newNode->next = NULL;
  if(head == NULL){ // if the list is initially empty
    return newNode;
  }
  curr = head;
  while(curr->next != NULL){
    curr = curr->next;
  }
  curr->next = newNode;
  return head;
}

struct node* addTerm(struct node* result, int co, int po){
  struct node* temp = (struct node*) malloc(sizeof(struct node));
  temp->co = co;
  temp->po = po;
  temp->next = NULL;
  if(result == NULL){
    return temp;
  }
  struct node* curr;
  curr = result;
  while(curr != NULL){
    if(temp->po == curr->po){
      curr->co = curr->co + temp->co;
      return result;
    }
    else 
      curr = curr->next;
  }
  if(curr == NULL){
    result = insertEnd(result, co, po);  // if at all the "if" conditions fail we need to add to the result 
  }
  return result;
}

struct node* multiply(struct node* poly1, struct node* poly2){
  struct node* t1 = NULL;
  struct node* t2 = NULL;
  struct node* result = NULL;
  for(t1 = poly1; t1 != NULL; t1 = t1->next){
    for(t2 = poly2; t2 != NULL; t2 = t2->next){
      result = addTerm(result, t1->co*t2->co, t1->po+t2->po);
    }
  }
  return result;
}

void display(struct node* head){
  struct node* temp = head;
  if(head == NULL){
    printf("The list is empty\n");
    return;
  }
  while(temp->next != NULL){
    printf("%d*x^%d+", temp->co, temp->po);
    temp = temp->next;
  }
  printf("%d*x^%d", temp->co, temp->po);
}

int main(void){
  struct node* poly1 = NULL;
  struct node* poly2 = NULL;
  struct node* poly = NULL;

  int n, m, co, po;
  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    printf("Enter the co and po of %d term: ", i+1);
    scanf("%d %d", &co, &po);
    poly1 = insertEnd(poly1, co, po);
  }
  printf("first polynomial: ");
  display(poly1);
  printf("\n");

  printf("\nEnter the number of terms in the second polynomial: ");
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    printf("Enter the co and po of %d term: ", i+1);
    scanf("%d %d", &co, &po);
    poly2 = insertEnd(poly2, co, po);
  }
  printf("second polynomial: ");
  display(poly2);
  printf("\n");

  poly = multiply(poly1, poly2);
  printf("\nThe resultant polynomail: ");
  display(poly);
  printf("\n");

  return 0;
}
