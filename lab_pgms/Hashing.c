#include <stdio.h>
#include <stdlib.h>

int tsize, hash[100], count;

int Cal_Hash(int key) {
    return key % tsize;
}

int Cal_ReHash(int key) {
    return (key + 1) % tsize;
}

void insert(int key) {
    int index;
    if (count != tsize){
        index = Cal_Hash(key);
        while (hash[index] != -1){
            index = Cal_ReHash(index);
        }
        hash[index] = key;
        count++;
    }
    else
        printf("\nTable is full");
}

int search(int key) {
    int i, index, loc = -1;
    index = Cal_Hash(key);
    for (i = 0; i < tsize; i++){
        loc = (index + i) % tsize;
        if (hash[loc] == key){
            return loc;
        }
    }
    return -1;
}

void delete(int key) {
    int loc;
    if (count == 0)
        printf("\nHash table empty,can't delete");
    else{
        loc = search(key);
        if (loc != -1){
            hash[loc] = -1;
            count--;
            printf("\nKey deleted");
        }
        else
            printf("\nKey not found");
    }
}

void display() {
    printf("\nThe elements in the hashtable are: ");
    for (int i = 0; i < tsize; i++){
        printf("\nElement at position %d: %d", i, hash[i]);
    }
}

int main() {
    int key, ch;
    printf("Enter the size of the hash table: ");
    scanf("%d", &tsize);
    for (int i = 0; i < tsize; i++)
        hash[i] = -1;
    for (;;){
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nRead Choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter the key to be inserted: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("\nenter search key: ");
            scanf("%d", &key);
            int loc = search(key);
            if (loc != -1)
                printf("\nkey is found at index %d", loc);
            else
                printf("\nKey not found");
            break;
        case 3:
            printf("\nEnter key to be deleted\n");
            scanf("%d", &key);
            delete (key);
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
