
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if ((a ^ b) < 0)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
