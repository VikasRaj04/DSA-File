#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  

#define MAX 100 

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initialize(Stack* s) {
    s->top = -1;  
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d to the stack\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return INT_MIN;  
    }
    return s->arr[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return s->arr[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped %d from the stack\n", pop(&s));
    printf("Popped %d from the stack\n", pop(&s));

    display(&s);

    return 0;
}