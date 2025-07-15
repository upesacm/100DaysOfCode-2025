#include <stdio.h>

int main() {
    int n, i;
    scanf("%d %d", &n, &i);

    int bit = (n >> i) & 1;
    printf("%d\n", bit);

    return 0;
}
