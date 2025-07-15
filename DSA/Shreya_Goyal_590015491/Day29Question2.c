#include <stdio.h>

int main() {
    int n, i;
    
    printf("n: ");
    scanf("%d", &n);
    
    printf("i: ");
    scanf("%d", &i);

    int bit = (n >> i) & 1;

    printf("The bit at position %d is: %d\n", i, bit);

    return 0;
}
