#include <stdio.h>

int subtractone(int n) {
    int m = 1;
    while ((n & m) == 0) {
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

    int result = subtractone(n);
    printf("Output: %d\n", result);

    return 0;
}
