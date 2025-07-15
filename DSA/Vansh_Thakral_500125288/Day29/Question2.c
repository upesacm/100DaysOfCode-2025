#include <stdio.h>

int getIthBit(int n, int i) {
    return (n & (1 << i)) ? 1 : 0;
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    printf("%d\n", getIthBit(n, i));
    return 0;
}
