#include <stdio.h>

void func(int *x, int *y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    func(&a, &b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
