#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int val) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = val;
    }
}

int pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1;
}

int peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void calculateSpan(int price[], int n, int span[]) {
    struct Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        while (!isEmpty(&s) && price[peek(&s)] <= price[i]) {
            pop(&s);
        }

        span[i] = isEmpty(&s) ? (i + 1) : (i - peek(&s));

        push(&s, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int price1[] = {100, 80, 60, 70, 60, 75, 85};
    int n1 = sizeof(price1) / sizeof(price1[0]);
    int span1[n1];

    calculateSpan(price1, n1, span1);
    printf("Input: ");
    printArray(price1, n1);
    printf("Output: ");
    printArray(span1, n1);

    int price2[] = {10, 20, 30};
    int n2 = sizeof(price2) / sizeof(price2[0]);
    int span2[n2];

    calculateSpan(price2, n2, span2);
    printf("\nInput: ");
    printArray(price2, n2);
    printf("Output: ");
    printArray(span2, n2);

    return 0;
}
