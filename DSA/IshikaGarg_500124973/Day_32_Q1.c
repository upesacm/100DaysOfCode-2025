
#include <stdio.h>

void swap(int a, int b) {
    printf("Before swap: a = %d, b = %d\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swap: a = %d, b = %d\n\n", a, b);
}

int main() {
    swap(4, 7);
    swap(1, 2);
    return 0;
}
