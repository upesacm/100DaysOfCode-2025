#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = n >> 1;  
    printf("Result: %d\n", result);

    return 0;
}
