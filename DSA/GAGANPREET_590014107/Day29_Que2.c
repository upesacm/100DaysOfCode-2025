#include <stdio.h>
int get_ith_bit(int n, int i) {
    return (n >> i) & 1;
}
int main() {
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the bit position (0-indexed): ");
    scanf("%d", &i);
    printf("The %d-th bit of %d is %d\n", i, n, get_ith_bit(n, i));
    return 0;
}
