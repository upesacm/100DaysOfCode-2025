#include <stdio.h>

void calculateStockSpan(int prices[], int n, int span[]) {
    int stack[n]; // stack of indices
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && prices[stack[top]] <= prices[i])
            top--;

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}

int main() {
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateStockSpan(prices, n, span);

    printf("Stock spans: ");
    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");

    return 0;
}
