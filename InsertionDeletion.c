#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *size, int position, int value) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert new element.\n");
        return;
    }
    if (position > *size || position < 0) {
        printf("Invalid position.\n");
        return;
    }
    
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = value;
    (*size)++;
}

void delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position >= *size || position < 0) {
        printf("Invalid position.\n");
        return;
    }
    
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    
    int choice, position, value;
    
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &size, position, value);
                break;
            case 2:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 3:
                printArray(arr, size);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n"); 
        }
    }
    return 0;   
}