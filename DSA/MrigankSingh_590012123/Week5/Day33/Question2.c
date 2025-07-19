#include <stdio.h>

int turn_off_rightmost_bit(int n) {
    return n & (n - 1);
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

    int result = turn_off_rightmost_bit(n);

    printf("%d\n", result);

    return 0;
}