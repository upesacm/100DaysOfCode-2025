#include <stdio.h>

void check(int n) {
    if (n & 1)
        printf("Odd\n");
    else
        printf("Even\n");
}

int main() {
    int n;
    scanf("%d", &n);
    check(n);
    return 0;
}
