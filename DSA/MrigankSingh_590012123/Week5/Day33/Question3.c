#include <stdio.h>

int Isolate(int n) {
    return n & -n;
}

int main() {
    int n;

    printf("Enter an integer n: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: Invalid integer input.\n");
        return 1;
    }

    int c;
    while (getchar() != '\n');

    int result = Isolate(n);

    printf("%d\n", result);

    return 0;
}