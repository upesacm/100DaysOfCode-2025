#include <stdio.h>
#include <stdbool.h>

bool haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a1 = 2, b1 = -3;
    int a2 = -4, b2 = -5;

    printf("a = %d, b = %d → Opposite Signs: %s\n", a1, b1, haveOppositeSigns(a1, b1) ? "True" : "False");
    printf("a = %d, b = %d → Opposite Signs: %s\n", a2, b2, haveOppositeSigns(a2, b2) ? "True" : "False");

    return 0;
}
