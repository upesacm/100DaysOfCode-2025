#include <stdio.h>

int main() {
    int n, i, result = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        result ^= arr[i];  
    }
    printf("XOR of all elements: %d\n", result);
    return 0;
}
