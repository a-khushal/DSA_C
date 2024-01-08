#include <stdio.h>
#include <stdlib.h>

int arr[100], n, top = -1;

void push() {
    if (top > n - 2) {
        printf("stack overflow\n");
        return;
    }
    int element;
    printf("Enter the number to push: ");
    scanf("%d", &element);
    top++;
    arr[top] = element;
    printf("Number pushed to the stack\n");
}

void pop() {
    if (top <= -1) {
        printf("stack underflow\n");
        return;
    }
    printf("%d popped out of the stack\n", arr[top]);
    top--;
}

void empty() {
    if (top <= -1) {
        printf("stack is empty\n");
    }
}

void display() {
    if (top <= -1) {
        printf("stack is empty\n");
        return;
    }

    printf("The elements of the stack are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Enter the size of the stack: ");
    scanf("%d", &n);
    int ch;

    do {
        printf("\n1.push\n2.pop\n3.isEmpty\n4.display\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                empty();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("wrong choice!\n");
        }
    } while (1);

    return 0;
}

