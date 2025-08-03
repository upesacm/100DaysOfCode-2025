#include <stdio.h>

int isPowerOfTwo(int n) {
    
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPowerOfTwo(num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
