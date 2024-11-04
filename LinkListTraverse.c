#include<stdio.h>
#include<string.h>
#include<conio.h>

#define NULL 0

typedef struct nodetype
{
    int info;
    struct nodetype *plink;
    struct nodetype *flink; 
}node;

int main() {
    void create_list(node**, node**);
    void create(node**, node**);
    void trav_forw(node*);
    void trav_back(node*);
    void destroy_list(node**, node**);
    node *head,  *tail;
    create_list(&head, &tail);
    create(&head, &tail);
    printf("Traversing doubly linked list in forward direction\n");
    trav_forw(head);
    printf("\ntraversing doubly linked list in  backward direction\n");
    trav_back(tail);
    printf("\n------End of program------");
    destroy_list(&head, &tail);
}

void create_list(node **head, node **tail){
    *head =* tail = NULL;
}

void create(node **head, node **tail){
    node *ptr;
    char ch = 'y';
    while(ch == 'Y' || ch == 'y'){
        if(*head==NULL){
            *head=(node*)malloc(sizeof(node));
            (*head)->plink=NULL;
            ptr=*head;
        }
        else{
            ptr->flink=(node*)malloc(sizeof(node));
        }
    }

}
