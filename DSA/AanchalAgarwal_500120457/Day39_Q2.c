#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack for storing indices
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
}

int pop(Stack* s) {
    if (!isEmpty(s))
        return s->items[s->top--];
    return -1;
}

int peek(Stack* s) {
    if (!isEmpty(s))
        return s->items[s->top];
    return -1;
}

// Function to compute stock spans
void calculateSpan(int price[], int n, int span[]) {
    Stack s;
    init(&s);

    // First day's span is always 1
    span[0] = 1;
    push(&s, 0);

    // Loop through price array
    for (int i = 1; i < n; i++) {
        // Pop all indices with smaller or equal prices
        while (!isEmpty(&s) && price[peek(&s)] <= price[i]) {
            pop(&s);
        }

        // If stack is empty, price[i] is highest so far
        span[i] = isEmpty(&s) ? (i + 1) : (i - peek(&s));

        // Push current index onto stack
        push(&s, i);
    }
}

// Display span array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Test
int main() {
    int prices1[] = {100, 80, 60, 70, 60, 75, 85};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    int span1[n1];
    calculateSpan(prices1, n1, span1);
    printf("Span for [100, 80, 60, 70, 60, 75, 85]:\n");
    printArray(span1, n1);  // Output: 1 1 1 2 1 4 6

    int prices2[] = {10, 20, 30};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    int span2[n2];
    calculateSpan(prices2, n2, span2);
    printf("Span for [10, 20, 30]:\n");
    printArray(span2, n2);  // Output: 1 2 3

    return 0;
}
