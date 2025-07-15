#include <stdio.h>

int main() {
    int n;
    printf("Enter number to divide by 2: ");
    scanf("%d", &n);

    int result = n >> 1;
    printf("%d\n", result);

    return 0;
}
