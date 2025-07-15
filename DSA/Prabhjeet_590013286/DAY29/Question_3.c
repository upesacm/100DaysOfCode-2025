#include <stdio.h>

int setBit(int n, int i) {
    return n | (1 << i);
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    printf("%d\n", setBit(n, i));
    return 0;
}
