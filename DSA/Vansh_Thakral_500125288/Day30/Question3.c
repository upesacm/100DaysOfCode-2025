#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n != 0) {
        n = n & (n - 1); 
        count++;
    }
    return count;
}

int main() {
    int n1 = 7;
    int n2 = 9;

    printf("countSetBits(%d) = %d\n", n1, countSetBits(n1)); 
    printf("countSetBits(%d) = %d\n", n2, countSetBits(n2)); 

    return 0;
}
