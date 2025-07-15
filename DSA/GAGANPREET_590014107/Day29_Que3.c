#include<stdio.h>
int set_ith_bit(int n, int i) {
    return n | (1 << i);
}
int main() {
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter the bit position to set (0-indexed): ");
    scanf("%d", &i);
    printf("New number after setting the %d-th bit is %d\n", i, set_ith_bit(n, i));
    return 0;
}
