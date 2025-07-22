#include <stdio.h>
int subtractOne(int x) {
    int m = 1;
    while (!(x & m)) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) == 1) {
        printf("%d - 1 = %d\n", n, subtractOne(n));
    }
    return 0;
}
