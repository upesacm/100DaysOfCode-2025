
#include <stdio.h>

int main() {
    int a = 4, b = 7;

    printf("Before swap: a = %d, b = %d\n", a, b);

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
