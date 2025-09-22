#include <stdio.h>

#define MAX 1000

// Stack structure to store indices
typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack *s) {
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void maxSlidingWindow(int arr[], int n, int k) {
    Stack s;
    s.top = -1;

    int result[MAX];
    int resIndex = 0;

    for (int i = 0; i < n; i++) {
        // Remove indices out of the current window
        while (!isEmpty(&s) && peek(&s) <= i - k) {
            pop(&s);
        }

        // Maintain decreasing order in stack
        while (!isEmpty(&s) && arr[peek(&s)] < arr[i]) {
            pop(&s);
        }

        push(&s, i);

        // Record max for current window
        if (i >= k - 1) {
            result[resIndex++] = arr[peek(&s)];
        }
    }

    // Print result
    printf("Maximums in each sliding window of size %d:\n[", k);
    for (int i = 0; i < resIndex; i++) {
        printf("%d", result[i]);
        if (i < resIndex - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n, k;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter window size k: ");
    scanf("%d", &k);

    if (k > n || k <= 0) {
        printf("Invalid window size. It must be between 1 and %d.\n", n);
        return 1;
    }

    maxSlidingWindow(arr, n, k);

    return 0;
}
