#include <stdio.h>

int opposite(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a, b;

    printf("Enter two integers (a b): ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Error: Invalid input. Please enter two integers.\n");
        return 1;
    }

    int c;
    while (getchar() != '\n');

    int result = opposite(a, b);

    printf("%s\n", result ? "True" : "False");

    return 0;
}