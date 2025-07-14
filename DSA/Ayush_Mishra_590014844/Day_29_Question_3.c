#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number (n): ");
    scanf("%d", &n);
    printf("Enter the bit position to set (i): ");
    scanf("%d", &i);
    int result = n | (1 << i);
    printf("Number after setting %d-th bit: %d\n", i, result);
    return 0;
}
