#include <stdio.h>

int divideByTwo(int n) {
    return n >> 1;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Output: %d\n", divideByTwo(n));

    return 0;
}
