#include <stdio.h>

int multiplyByTwo(int n) {
    return n << 1;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Output: %d\n", multiplyByTwo(n));

    return 0;
}
