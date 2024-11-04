#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(Node **head_ref, int data)
{
    Node *newNode = createNode(data);
    Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

void printListForward(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void printListBackward(Node *node)
{
    Node *last = NULL;
    while (node != NULL)
    {
        last = node;
        node = node->next;
    }
    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("List in forward direction: ");
    printListForward(head);

    printf("List in backward direction: ");
    printListBackward(head);

    freeList(head);

    return 0;
}
