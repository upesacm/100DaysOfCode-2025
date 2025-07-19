
#include <stdio.h>

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    int result = n & (n - 1);
    printf("Result after turning off rightmost set bit: %d\n", result);

    return 0;
}
