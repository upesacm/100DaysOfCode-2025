#include <stdio.h>
#include <limits.h>
#define MAX 100

// Stack definition
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

void push(Stack* s, int value) {
    if (s->top < MAX - 1)
        s->items[++s->top] = value;
    else
        printf("Stack Overflow\n");
}

int pop(Stack* s) {
    if (!isEmpty(s))
        return s->items[s->top--];
    else {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
}

int peek(Stack* s) {
    if (!isEmpty(s))
        return s->items[s->top];
    return INT_MIN;
}

// Insert an element at the bottom of stack using recursion
void insertAtBottom(Stack* s, int value) {
    if (isEmpty(s)) {
        push(s, value);
        return;
    }

    int temp = pop(s);
    insertAtBottom(s, value);
    push(s, temp);
}

// Reverse stack using recursion only
void reverseStack(Stack* s) {
    if (isEmpty(s)) return;

    int temp = pop(s);
    reverseStack(s);
    insertAtBottom(s, temp);
}

// Display the stack (bottom to top)
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

    // Test input: [1, 2, 3]
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("Original Stack: ");
    display(&s);

    reverseStack(&s);

    printf("Reversed Stack: ");
    display(&s);

    return 0;
}
