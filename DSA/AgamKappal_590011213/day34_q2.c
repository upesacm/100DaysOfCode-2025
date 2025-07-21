
#include <stdio.h>

int subtractOne(int n) {
    int mask = 1;
    while ((n & mask) == 0) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}

int main() {
    int n1 = 5, n2 = 8;
    printf("Input: %d, Output: %d\n", n1, subtractOne(n1));
    printf("Input: %d, Output: %d\n", n2, subtractOne(n2));
    return 0;
}
