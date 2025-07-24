#include <stdio.h>

void stockSpan(int price[], int n) {
    int stack[n], top = -1;
    int span[n];

    for (int i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }

    printf("Span: ");
    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");
}


int main() {
    int prices1[] = {100, 80, 60, 70, 60, 75, 85};
    int prices2[] = {10, 20, 30};

    stockSpan(prices1, 7); 
    stockSpan(prices2, 3); 

    return 0;
}

