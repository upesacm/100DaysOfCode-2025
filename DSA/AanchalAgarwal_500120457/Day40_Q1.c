#include <stdio.h>

#define MAX 100

// Sample matrix for up to MAX people
int M[MAX][MAX];

// Function to check if person a knows person b
int knows(int a, int b) {
    return M[a][b];
}

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

// Main function to find celebrity
int findCelebrity(int n) {
    Stack s;
    s.top = -1;

    // Step 1: Push all people into stack
    for (int i = 0; i < n; i++) {
        push(&s, i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.top >= 1) {
        int a = pop(&s);
        int b = pop(&s);

        if (knows(a, b)) {
            // a cannot be celebrity
            push(&s, b);
        } else {
            // b cannot be celebrity
            push(&s, a);
        }
    }

    // Step 3: Verify the remaining candidate
    int candidate = pop(&s);

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i) || !knows(i, candidate)) {
                return -1;  // Not a celebrity
            }
        }
    }

    return candidate;
}
