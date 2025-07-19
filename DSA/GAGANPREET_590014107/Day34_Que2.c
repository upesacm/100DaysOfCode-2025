#include <stdio.h>

int subtractOne(int n) {
    int m = 1;
    while (m != 0) {
        int borrow = (~n) & m;   
        n = n ^ m;              
        m = borrow << 1;         
    }
    return n;
}

int main() {
    int n;

    n = 5;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));  

    n = 0;
    printf("Input: n = %d\n", n);
    printf("Output: %d\n", subtractOne(n));  

    return 0;
}
