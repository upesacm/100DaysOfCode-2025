#include <stdio.h>

int Bits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1); 
        count++;
    }
    return count;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = Bits(n);
    printf("Number of set bits: %d\n", result);

    return 0;
}
