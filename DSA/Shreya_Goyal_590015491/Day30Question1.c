#include <stdio.h>

int main() {
    int n, i;

    printf("n: ");
    scanf("%d", &n);

    printf("i: ");
    scanf("%d", &i);

    int cl= n & ~(1 << i);

    printf("The number after clearing the %d-th bit is: %d\n", i, cl);

    return 0;
}
