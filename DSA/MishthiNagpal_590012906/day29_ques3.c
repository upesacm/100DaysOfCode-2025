#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number (n) and bit position (i): ");
    scanf("%d %d", &n, &i);

    int result = n | (1 << i);
    printf("%d\n", result);

    return 0;
}
