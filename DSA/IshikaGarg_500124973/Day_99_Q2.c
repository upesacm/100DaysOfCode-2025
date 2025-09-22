#include <stdio.h>

#define MAX 100

// Stack implementation
typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
void push(Stack *s, int val) { s->data[++s->top] = val; }
int pop(Stack *s) { return s->data[s->top--]; }
int peek(Stack *s) { return s->data[s->top]; }

// Function to find max in sliding window using two stacks
void slidingWindowMax(int arr[], int n, int k) {
    Stack left, right;
    init(&left); init(&right);

    int leftMax[MAX], rightMax[MAX];

    // Preprocess leftMax
    for (int i = 0; i < n; i++) {
        if (i % k == 0) init(&left);
        if (isEmpty(&left)) push(&left, arr[i]);
        else push(&left, arr[i] > peek(&left) ? arr[i] : peek(&left));
        leftMax[i] = peek(&left);
    }

    // Preprocess rightMax
    for (int i = n - 1; i >= 0; i--) {
        if ((i + 1) % k == 0) init(&right);
        if (isEmpty(&right)) push(&right, arr[i]);
        else push(&right, arr[i] > peek(&right) ? arr[i] : peek(&right));
        rightMax[i] = peek(&right);
    }

    // Compute sliding window maximum
    for (int i = 0; i <= n - k; i++) {
        int maxVal = leftMax[i + k - 1];
        if (rightMax[i] > maxVal) maxVal = rightMax[i];
        printf("%d ", maxVal);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    slidingWindowMax(arr, n, k); // Output: 3 3 5 5 6 7
    return 0;
}

