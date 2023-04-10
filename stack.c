#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int data[MAX_SIZE];
} Stack;

void push(Stack *s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = item;
    } else {
        printf("Stack overflow.\n");
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

void display(Stack *s) {
    if (s->top >= 0) {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->data[i]);
        }
    } else {
        printf("Stack is empty.\n");
    }
}

int main() {
    Stack my_stack;
    my_stack.top = -1;

    // Push some items onto the stack
    push(&my_stack, 10);
    push(&my_stack, 20);
    push(&my_stack, 30);

    // Display the current stack elements
    display(&my_stack);

    // Pop an item off the stack
    printf("Popped item: %d\n", pop(&my_stack));

    // Display the current stack elements again
    display(&my_stack);

    return 0;
}

