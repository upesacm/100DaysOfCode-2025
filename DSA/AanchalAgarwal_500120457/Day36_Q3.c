#include <stdio.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Stack functions
void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, int x) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = x;
    }
}

int pop(struct Stack *s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1;
}

void insertAtBottom(struct Stack *s, int x) {
    if (isEmpty(s)) {
        push(s, x);
        return;
    }
    int topElem = pop(s);
    insertAtBottom(s, x);
    push(s, topElem);
}

void printStack(struct Stack *s) {
    printf("Stack (bottom to top): ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initStack(&s);

    // Example 1
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    insertAtBottom(&s, 0); // Output should be [0, 1, 2, 3]
    printStack(&s);

    // Example 2
    initStack(&s);
    push(&s, 5);
    push(&s, 6);
    insertAtBottom(&s, 9); // Output should be [9, 5, 6]
    printStack(&s);

    return 0;
}
