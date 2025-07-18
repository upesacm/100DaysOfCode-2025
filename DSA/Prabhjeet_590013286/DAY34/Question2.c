#include <stdio.h>

int func(int x) {
    int m = 1;
    while ((x & m) == 0) {
        x ^= m;
        m <<= 1;
    }
    x ^= m;
    return x;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", func(x));
    return 0;
}
