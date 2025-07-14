#include <stdio.h>

int setIthBit(int n, int i) {
    return n | (1 << i);
}

int main() {
    int n, i;
    printf("Enter number and bit position (i) to set: ");
    scanf("%d %d", &n, &i);
    int result = setIthBit(n, i);
    printf("New number after setting %d-th bit: %d\n", i, result);
    return 0;
}
