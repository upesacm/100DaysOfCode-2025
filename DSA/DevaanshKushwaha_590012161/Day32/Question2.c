#include <stdio.h>

int main() {
    int n, x, result = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    while (n--) {
        scanf("%d", &x);
        result ^= x;
    }
    printf("Unique element: %d\n", result);
    return 0;
}
