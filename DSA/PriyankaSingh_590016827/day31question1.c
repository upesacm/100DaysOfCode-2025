#include <stdio.h>

int main() {
    int n;
    printf("Enter number to check power of 2: ");
    scanf("%d", &n);

    if (n > 0 && (n & (n - 1)) == 0)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
