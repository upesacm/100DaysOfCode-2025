#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n & 1)
        printf("Output: Odd\n");
    else
        printf("Output: Even\n");

    return 0;
}
