#include <stdio.h>

int main() {
    int n, i;
    printf("Enter a number (n): ");
    scanf("%d", &n);
    printf("Enter bit position (i): ");
    scanf("%d", &i);

    int bit = (n >> i) & 1;
    printf("Output: %d\n", bit);

    return 0;
}
