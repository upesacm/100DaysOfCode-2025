#include <stdio.h>

int main() {
    int n, i;
    printf("Enter a number (n): ");
    scanf("%d", &n);
    printf("Enter bit position (i): ");
    scanf("%d", &i);

    int result = n | (1 << i);
    printf("Output: %d\n", result);

    return 0;
}
