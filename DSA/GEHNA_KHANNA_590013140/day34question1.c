#include <stdio.h>
int addOne(int x) {
    int m = 1;                    
    while (x & m) {
        x = x ^ m;
        m <<= 1;
    }
    x = x ^ m;
    return x;
}

int main(void) {
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) == 1) {
        printf("%d + 1 = %d\n", n, addOne(n));
    }
    return 0;
}
