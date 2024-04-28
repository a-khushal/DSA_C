// learn top down and bottom up uproach, by default it's bottom up if not specified
#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10], int n){
	int i, k, v, j, flag=0;
	for(i=n/2; i>=1; i--){
		k=i;
		v=a[k];
		while(!flag && 2*k<=n){
			j=2*k;
			if(j<n){
				if(a[j]<a[j+1]){
					j=j+1;
				}
			}
			if(v>a[j]){
				flag=1;
			}
			else {
				a[k]=a[j];
				k=j;
			}
		}
        a[k]=v;
        flag=0;
	}
    return;
}

void heapSort(int a[10], int n){
    int temp;
    for(int i=n; i>=1; i--){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        heapify(a, i-1);
    }
}

int main(void){
    int n, a[10], ch;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Read elements: ");
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    heapify(a, n);
    printf("Elements after heapify: ");
    for(int i=1; i<=n; i++) 
        printf("%d  ", a[i]);
    printf("\n");
    heapSort(a, n);
    printf("Elements after sorting: ");
    for(int i=1; i<=n; i++) 
        printf("%d  ", a[i]);
    printf("\n");
    return 0;
}
