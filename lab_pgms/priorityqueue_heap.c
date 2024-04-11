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

int main(void){
    int n, a[10], ch;
    while(1){
        printf("\n1. Create heap\n2. Extract max\n3. Exit\n");
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: {
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                printf("Read elements: ");
                for(int i=1; i<=n; i++)
                    scanf("%d", &a[i]);
                heapify(a, n);
                printf("\nElements after heapify: ");
                for(int i=1; i<=n; i++) 
                    printf("%d  ", a[i]);
                printf("\n");
                break;
            }
            case 2: {
                if(n>=1){
                    printf("\nElement deleted is: %d", a[1]);
                    a[1] = a[n];
                    n--;
                    heapify(a, n);
                    if(n>0){
                        printf("\nElements after reconstruction: ");
                        for(int i=1; i<=n; i++) 
                            printf("%d  ", a[i]);
                        printf("\n");
                    }
                } else 
                    printf("No element to delete!");
                break;
            }
            default: exit(0);
        }
    }
    return 0;
}