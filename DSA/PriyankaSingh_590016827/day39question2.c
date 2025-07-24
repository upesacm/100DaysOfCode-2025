
#include <stdio.h>

#define MAX 100

int main() {
    int price[MAX], span[MAX], stack[MAX];
    int n, top = -1;

    printf("Enter number of days: ");
    scanf("%d", &n);
    printf("Enter stock prices:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &price[i]);

    for (int i = 0; i < n; i++) {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;
        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);
        stack[++top] = i;
    }

    printf("Stock spans:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);
    printf("\n");

    return 0;
}
