#include <stdio.h>

void calculateSpan(int price[], int n, int span[]) {
    int stack[n], top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }
}

int main() {
    int n;
    printf("Enter number of days: ");
    scanf("%d", &n);

    int price[n], span[n];
    printf("Enter stock prices for %d days:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    calculateSpan(price, n, span);

    printf("Stock Spans:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");

    return 0;
}
