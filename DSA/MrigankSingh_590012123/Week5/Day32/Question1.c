#include <stdio.h>

void swap(int *a, int *b) {
    if (a == b) return;     
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int a, b;

    printf("Enter two integers (a b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Error: Invalid input. Please enter two integers.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    swap(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}