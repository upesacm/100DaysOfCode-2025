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

void nextGreater(int arr[], int n, int result[]) {
    struct Stack s;
    init(&s);

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&s) && peek(&s) <= arr[i]) {
            pop(&s);
        }

        result[i] = isEmpty(&s) ? -1 : peek(&s);

        push(&s, arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int result1[n1];

    nextGreater(arr1, n1, result1);
    printf("Input: ");
    printArray(arr1, n1);
    printf("Output: ");
    printArray(result1, n1);

    int arr2[] = {13, 7, 6, 12};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2[n2];

    nextGreater(arr2, n2, result2);
    printf("\nInput: ");
    printArray(arr2, n2);
    printf("Output: ");
    printArray(result2, n2);

    return 0;
}
