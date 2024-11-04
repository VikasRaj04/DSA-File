#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head, *prev = NULL;

    if (temp->data == key)
    {
        if (temp->next == *head)
        {
            free(temp);
            *head = NULL;
            return;
        }

        prev = *head;
        while (prev->next != *head)
        {
            prev = prev->next;
        }
        prev->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    prev = temp;
    temp = temp->next;
    while (temp != *head && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        printf("Node with data %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Circular Linked List: ");
    displayList(head);

    deleteNode(&head, 3);

    printf("After deleting node with data 3: ");
    displayList(head);

    deleteNode(&head, 1);
    deleteNode(&head, 2);
    deleteNode(&head, 4);
    deleteNode(&head, 5);

    return 0;
}
                                                                                                                                                                                                                                                                                                                