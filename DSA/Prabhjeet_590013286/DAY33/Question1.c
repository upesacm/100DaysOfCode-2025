#include <stdio.h>

int func(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf(func(a, b) ? "True\n" : "False\n");
    return 0;
}
