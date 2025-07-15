#include<stdio.h>
int clearBit(int n, int i) {
    int mask = ~(1 << i);
    return n & mask;
}
int main() {
    int n1 = 7; 
    int i1 = 1;
    int result1 = clearBit(n1, i1);
    printf("Input: n = %d, i = %d\nOutput: %d\n", n1, i1, result1);
    int n2 = 10; 
    int i2 = 3;
    int result2 = clearBit(n2, i2);
    printf("Input: n = %d, i = %d\nOutput: %d\n", n2, i2, result2);
    return 0;
}
