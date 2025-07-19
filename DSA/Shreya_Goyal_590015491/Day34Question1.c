#include <stdio.h>

int addone(int n) {
    int m = 1;
    while (n & m) {
        n = n ^ m;  
        m <<= 1;    
    }
    n = n ^ m;      
    return n;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = addone(n);
    printf("Output: %d\n", result);

    return 0;
}
