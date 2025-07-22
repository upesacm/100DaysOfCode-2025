
#include <stdio.h>

int addOne(int n) {
    int mask = 1;
    while (n & mask) {
        n = n ^ mask;
        mask <<= 1;
    }
    n = n ^ mask;
    return n;
}

int main() {
    int n1 = 4, n2 = 7;
    printf("Input: %d, Output: %d\n", n1, addOne(n1));
    printf("Input: %d, Output: %d\n", n2, addOne(n2));
    return 0;
}
