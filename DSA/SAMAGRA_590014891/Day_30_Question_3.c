#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n1 = 7;
    printf("Output: %d\n", countSetBits(n1));  

    int n2 = 9;
    printf("Output: %d\n", countSetBits(n2)); 

    return 0;
}
