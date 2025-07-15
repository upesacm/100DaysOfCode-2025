#include <stdio.h>
int main() {
    int n;
    printf("enter a number\n");
    scanf("%d", &n);
    if (n & 1)
        printf("Odd\n");
    else
        printf("Even\n");
    return 0;
}
