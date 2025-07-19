#include <stdio.h>

int haveOppositeSigns(int a, int b) {
    return (a ^ b) < 0;
}

int main() {
    int a = 2, b = -3;

    if (haveOppositeSigns(a, b))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
