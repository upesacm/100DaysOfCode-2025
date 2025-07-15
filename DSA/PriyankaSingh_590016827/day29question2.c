#include <stdio.h>
int main() {
    int n, i;
    printf("Enter number and bit position: ");
    scanf("%d %d", &n, &i);
    int bit = (n >> i) & 1;
    printf("%d\n", bit);
    return 0;
}
