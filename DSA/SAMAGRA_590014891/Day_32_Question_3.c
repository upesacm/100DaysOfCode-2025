#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], xorResult = 0;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        xorResult ^= arr[i];
    }

    printf("XOR of all elements: %d\n", xorResult);
    return 0;
}
