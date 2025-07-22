#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Stack functions
void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return s->items[s->top--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        return INT_MIN;
    }
    return s->items[s->top];
}

// Sorting function
void sortStack(Stack* input) {
    Stack temp;
    init(&temp);

    while (!isEmpty(input)) {
        int tempVal = pop(input);

        // Move larger elements back to input stack
        while (!isEmpty(&temp) && peek(&temp) > tempVal) {
            push(input, pop(&temp));
        }

        push(&temp, tempVal);
    }

    // Move back to input to have sorted in ascending order
    while (!isEmpty(&temp)) {
        push(input, pop(&temp));
    }
}

// Display stack from bottom to top
void display(Stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Test
int main() {
    Stack s;
    init(&s);

    // Example input
    push(&s, 3);
    push(&s, 1);
    push(&s, 4);
    push(&s, 2);

    printf("Original Stack (bottom to top): ");
    display(&s);

    sortStack(&s);

    printf("Sorted Stack (bottom to top): ");
    display(&s);

    return 0;
}

