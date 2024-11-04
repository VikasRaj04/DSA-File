#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
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

// Function to insert a node at a specific position in the list
void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        insertAtBeginning(head, data);
    } else {
        Node* temp = *head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            if (temp->next->data == data) {
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                free(nodeToDelete);
                return;
            }
            temp = temp->next;
        }
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printf("Linked List: ");
    printList(head);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Linked List after inserting at the end: ");
    printList(head);

    // Insert node at a specific position in the list
    insertAtPosition(&head, 25, 2);

    printf("Linked List after inserting at position 2: ");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 20);

    printf("Linked List after deleting 20: ");
    printList(head);

    return 0;
}




