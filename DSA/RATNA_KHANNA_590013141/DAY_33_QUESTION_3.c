#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int result = n & (-n);
    printf("Output: %d\n", result);

    return 0;
}
