#include <stdio.h>

#define SIZE 5
int count = 0;
int arr[SIZE];

void insertion(int item) {
    if (count >= SIZE) {
        printf("Heap is full\n");
        return;
    }
    count++;
    int index = count;
    arr[index] = item;
    while (index > 1 && arr[index] > arr[index / 2]) {
        int temp = arr[index];
        arr[index] = arr[index / 2];
        arr[index / 2] = temp;
        index = index / 2;
    }
}

void deleteFromHeap() {
    if (count == 0) {
        printf("No element to delete\n");
        return;
    }
    arr[1] = arr[count];
    count--;

    int i = 1;
    while (i < count) {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex < count && arr[leftIndex] > arr[i]) {
            int temp = arr[leftIndex];
            arr[leftIndex] = arr[i];
            arr[i] = temp;
            i = leftIndex;
        } else if (rightIndex < count && arr[rightIndex] > arr[i]) {
            int temp = arr[rightIndex];
            arr[rightIndex] = arr[i];
            arr[i] = temp;
            i = rightIndex;
        } else {
            return;
        }
    }
}

void display() {
    for (int i = 1; i <= count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    insertion(50);
    insertion(55);
    insertion(53);
    insertion(52);
    insertion(54);
    display();
    deleteFromHeap();
    display();
    return 0;
}
