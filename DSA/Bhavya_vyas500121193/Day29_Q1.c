#include <stdio.h>

void checkEvenOrOdd(int n) {
    if (n & 1)
        printf("Odd\n");
    else
        printf("Even\n");
}

int main() {
    int n = 7;
    printf("Input: %d\nOutput: ", n);
    checkEvenOrOdd(n);

    n = 4;
    printf("Input: %d\nOutput: ", n);
    checkEvenOrOdd(n);

    return 0;
}
