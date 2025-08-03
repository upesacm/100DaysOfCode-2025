#include <stdio.h>

#define MAX 100

void stockSpan(int price[], int n, int span[]) {
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        if (top == -1)
            span[i] = i + 1;
        else
            span[i] = i - stack[top];

        stack[++top] = i;
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[MAX];

    stockSpan(price, n, span);

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");

    return 0;
}
