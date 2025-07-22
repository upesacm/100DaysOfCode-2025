#include <stdio.h>

int addOne(int n) {
    int m = 1;
    while (n & m) {
        n = n ^ m;  
        m <<= 1;    
    }
    n = n ^ m;     
    return n;
}

int main() {
    printf("4 + 1 = %d\n", addOne(4));  
    printf("7 + 1 = %d\n", addOne(7));  
    return 0;
}
