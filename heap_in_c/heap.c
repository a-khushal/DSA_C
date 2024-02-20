// #include <stdio.h>

// void insert(int val, int size){
//     int arr[100];
//     size++;
//     int index = size;
//     arr[index] = val;
//     while(index>1){
//         int parent = index / 2;
//         if(arr[parent]<arr[index]){
//             int temp = arr[index];
//             arr[index]=val;
//             val = temp;
//             index = parent;
//         } else {
//             return; 
//         }
//     }
//     for(int i=1; i<=size; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int main(void){
//     insert(60,0);
//     insert(50,0);
//     insert(40,0);
//     insert(30,0);
//     insert(55,0);
// }   


#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void insert(int val) {
    if (size >= MAX_SIZE - 1) {
        printf("Heap is full\n");
        return;
    }

    size++;
    int index = size;
    arr[index] = val;
    while (index > 1 && arr[index / 2] < arr[index]) {
        int temp = arr[index];
        arr[index] = arr[index / 2];
        arr[index / 2] = temp;
        index = index / 2;
    }
}

void deleteFromHeap(){
    if(size == 0){
        printf("No element to delete\n");
        return;
    }
    arr[1] = arr[size];
    int index = size/2;
    size--;
    while(index>1 && arr[index/2]<arr[index]){
        int temp = arr[index];
        arr[index] = arr[index/2];
        arr[index/2] = temp;
        index = index/2;
    }
}

// O(log n)
void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= size && arr[left] > arr[largest]){
        largest = left;
    } 
    if(right <= size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr2[], int size){
    int t = size;
    // for(int i=size/2; i>0; i--)
    //     heapify(arr2, size, i);
    while(t>1){
        int temp = arr2[1];
        arr2[1] = arr2[t];
        arr2[t] = temp;
        t--;
        heapify(arr2, t, 1); // we only swapped the first index so hepify using the first index only vro..
    }
}   

void printFn(){
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    // insert(50);
    // insert(55);
    // insert(53);
    // insert(52);
    // insert(54);

    // printFn();

    // // deleteFromHeap();
    // // printFn();
    // int arr1[6] = {-1, 54, 55, 53, 52, 50};
    // int n=5;

    // // O(n)
    // for(int i=n/2; i>0; i--){
    //     heapify(arr1, n, i);
    // }
    // for(int i=1; i<6; i++){
    //     printf("%d ", arr1[i]);
    // }
    // printf("\n");

    int arr2[] = {-1, 70, 60, 55, 45, 50};
    heapSort(arr2, 5);
    for(int i=1; i<=5; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}
