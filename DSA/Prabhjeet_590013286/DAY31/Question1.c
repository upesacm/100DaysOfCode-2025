#include <stdio.h>

int func(int x) {
    return (x > 0) && ((x & (x - 1)) == 0);
}

int main() {
    int x;
    scanf("%d", &x);
    printf(func(x) ? "Yes\n" : "No\n");
    return 0;
}
