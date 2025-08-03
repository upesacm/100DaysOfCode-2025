#include <stdio.h>

int main() {
    int n;
    printf("Enter a number to multiply by 2 using bitwise: ");
    scanf("%d", &n);

    int result = n << 1;
    printf("%d\n", result);

    return 0;
}
