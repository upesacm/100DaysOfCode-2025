#include <stdio.h>

int subtractOne(int n) {
    int m = 1;
    while ((n & m) == 0) {
        n = n ^ m;  
        m <<= 1;    
    }
    n = n ^ m;      
    return n;
}

int main() {
    printf("5 - 1 = %d\n", subtractOne(5));  
    printf("8 - 1 = %d\n", subtractOne(8));  
    return 0;
}
