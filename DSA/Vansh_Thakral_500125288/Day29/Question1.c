#include <stdio.h>

void checkEvenOrOdd(int n) {
    if (n & 1) {
        printf("Odd\n");
    } else {
        printf("Even\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    checkEvenOrOdd(n);
    return 0;
}
