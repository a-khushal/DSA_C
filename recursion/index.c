#include <stdio.h>
int count = 1;
int sum = 0;

int gcd(int a, int b){
    if(a==b)
        return a;
    else if(a>b)
        return gcd(a-b,b);
    else 
        return gcd(a,b-a);
}

int multiply(int a, int b){
    if(a==0 || b==0)
        return 0;
    sum += a;
    b--;
    multiply(a,b);
    return sum;
}

int arrSum(int arr[], int n){
    if(n==0)
        return 0;
    else if(n==1)
        return arr[0];
    return arrSum(arr, n-1) + arr[n-1];
}

void towerOfHanoi(int n, char s, char t, char d){
    if(n==0){
        // printf("Move disk %d from %c to %c\n", n, s, d);  // if(n==1) do this
        return;
    }
    towerOfHanoi(n-1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    towerOfHanoi(n-1, t, s, d);
}

int main(void){
    // printf("%d\n",gcd(20,5));
    // printf("%d\n",gcd(3,5));
    // printf("%d\n",gcd(100,1000));
    // printf("%d\n",multiply(10,5));
    // int arr[] = {1,2,3,4,5,6,7,8,9,10};
    // printf("%d\n",arrSum(arr, 10));
    towerOfHanoi(4, 'A', 'B', 'C');
    return 0;
}

// 4, 13, 38, 30, 42, 