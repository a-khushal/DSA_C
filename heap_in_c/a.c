#include <stdio.h>

int main(void){
    int arr[] = {1,2,3,4}; int count = 0;
    for(int i=1; arr[i]!='\0'; i++){
        count++;
    }
    printf("%d\n", count);
}