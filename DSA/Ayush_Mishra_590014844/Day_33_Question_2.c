#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int result = n & (n - 1);
    printf("%d\n", result);
    return 0;
}
