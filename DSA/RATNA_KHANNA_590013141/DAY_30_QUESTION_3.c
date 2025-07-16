#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter the number (n): ");
    scanf("%d", &n);

    while (n > 0) {
        n = n & (n - 1);
        count++;
    }

    printf("Output: %d\n", count);

    return 0;
}
