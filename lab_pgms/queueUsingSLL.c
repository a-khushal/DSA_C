#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count=0;

struct node{
    int data;
    struct node* next;
};

struct node* insertEnd(struct node* last, int val){
    if(count >= SIZE){
        printf("\nQueue's full!");
        return NULL;
    }
    count++;
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = val;
    if(last == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = last->next;
        last->next = temp;
        return temp;
    }
}

struct node* deleteBegin(struct node* last){
    struct node* temp;
    if(last == NULL){
        printf("\nQueue's empty!");
        return NULL;
    }
    count--;
    if(last->next == last){
        printf("\nNode deleted is: %d", last->data);
        free(last);
        last = NULL; // to prevent dangling pointer
        return last;
    }
    temp = last->next;
    printf("\nNode deleted is: %d", temp->data);
    last->next = temp->next;
    free(temp);
    return last;
}

void display(struct node* last){
    struct node* temp;
    if(last == NULL){
        printf("\nQueue's empty");
    }
    else{
        printf("\nQueue content are: \n");
        temp = last->next;
        while(temp != last){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data); // to print the last node
    }
}

int main(void){
    struct node* last = NULL;
    int val, ch;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:{
                printf("\nRead item to be inserted: ");
                scanf("%d", &val);
                last = insertEnd(last, val);
                break;
            }
            case 2:{
                last = deleteBegin(last);
                break;
            }
            case 3:{
                display(last);
                break;
            }
            default: {
                exit(0);
            }
        }
    }
    return 0;
}