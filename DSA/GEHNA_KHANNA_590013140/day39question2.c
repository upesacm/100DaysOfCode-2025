#include <stdio.h>

#define MAX 1000

void calculateSpan(int price[], int n, int span[]) {
    int stack[MAX];
    int top = -1;

    span[0] = 1;
    stack[++top] = 0;

    for (int i = 1; i < n; i++) {
        while (top != -1 && price[i] >= price[stack[top]]) {
            top--;
        }

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }
}

int main() {
    int price[MAX], span[MAX], n;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter stock prices for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    calculateSpan(price, n, span);

    printf("Stock span for each day:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }

    return 0;
}
