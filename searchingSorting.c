#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* searchNode(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    insertNode(&head, 7);
    insertNode(&head, 8);
    insertNode(&head, 9);

    printf("Linked List: ");
    printList(head);

    int key;
    printf("Enter a key to search: ");
    scanf("%d", &key);

    Node* found = searchNode(head, key);

    if (found != NULL) {
        printf("Found %d in the list\n", key);
    } else {
        printf("%d not found in the list\n", key);
    }

    return 0;
}

// https://www.useblackbox.io/editor?id=a25db27d-c0bf-47a5-be57-2dfc845d25f2