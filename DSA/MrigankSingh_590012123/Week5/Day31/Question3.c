#include <stdio.h>

int divide_by_2(int n) {
    return n >> 1;
}

int main() {
    int n;

    printf("Enter an integer n: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    int result = divide_by_2(n);

    printf("%d\n", result);

    return 0;
}