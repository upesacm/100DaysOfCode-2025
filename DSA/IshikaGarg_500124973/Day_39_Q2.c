#include <stdio.h>

void calculateSpan(int price[], int n, int span[]) {
    int stack[n];
    int top = -1;

    stack[++top] = 0;
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (top >= 0 && price[stack[top]] <= price[i])
            top--;

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[n];

    calculateSpan(price, n, span);

    printf("Stock Spans: ");
    printArray(span, n);

    return 0;
}
