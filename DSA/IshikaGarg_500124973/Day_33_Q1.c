#include <stdio.h>
#include <stdbool.h>

bool haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a1 = 2, b1 = -3;
    int a2 = -4, b2 = -5;

    printf("Output 1: %s\n", haveOppositeSigns(a1, b1) ? "True" : "False");
    printf("Output 2: %s\n", haveOppositeSigns(a2, b2) ? "True" : "False");

    return 0;
}

