#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, b;
    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    bool oppositeSigns = (a ^ b) < 0;

    if (oppositeSigns)
        printf("Output: True\n");
    else
        printf("Output: False\n");

    return 0;
}
