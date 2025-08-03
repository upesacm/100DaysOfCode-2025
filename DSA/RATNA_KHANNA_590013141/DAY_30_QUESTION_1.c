#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter the number (n): ");
    scanf("%d", &n);
    
    printf("Enter the bit position to clear (i): ");
    scanf("%d", &i);
    
    int result = n & ~(1 << i);
    
    printf("Output: %d\n", result);
    
    return 0;
}
