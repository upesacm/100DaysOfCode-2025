#include <stdio.h>

int toggleBit(int n, int i) {
    int mask = (1 << i); 
    return n ^ mask;
}

int main() {
    int n, i;
    scanf("%d %d", &n, &i);
    printf("%d\n", toggleBit(n, i));
    return 0;
}
