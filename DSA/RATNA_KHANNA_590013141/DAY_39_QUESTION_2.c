#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
void calculateSpan(int price[], int n, int span[]) {
    int stack[MAX];
    int top = -1;

    span[0] = 1;
    stack[++top] = 0;

    for (int i = 1; i < n; i++) {
        while (top != -1 && price[i] >= price[stack[top]]) {
            top--;
        }

        span[i] = (top == -1) ? (i + 1) : (i - stack[top]);

        stack[++top] = i;
    }
}

int parseInput(char *input, int arr[]) {
    int num = 0, index = 0;
    int in_number = 0;

    for (int i = 0; input[i]; i++) {
        if (isdigit(input[i])) {
            num = num * 10 + (input[i] - '0');
            in_number = 1;
        } else if (in_number) {
            arr[index++] = num;
            num = 0;
            in_number = 0;
        }
    }
    if (in_number)
        arr[index++] = num;

    return index; 
}

int main() {
    char input[256];
    int price[MAX], span[MAX];

    printf("Enter stock prices in format [100, 80, 60, 70, 60, 75, 85]:\n");
    fgets(input, sizeof(input), stdin);

    int n = parseInput(input, price);

    calculateSpan(price, n, span);

    printf("Span for each day:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");

    return 0;
}
