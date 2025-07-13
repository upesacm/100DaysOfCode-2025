#include <stdio.h>

void getBit(int n, int i) {
    int bit = (n >> i) & 1;
    printf("%d\n", bit);
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    getBit(n, i);
    return 0;
}
