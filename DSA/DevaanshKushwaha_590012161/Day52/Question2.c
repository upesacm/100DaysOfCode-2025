#include <stdio.h>
int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter difference value: ");
    scanf("%d", &k);
    printf("[");
    int first = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] - arr[i] == k) {
                if (!first) printf(", ");
                printf("(%d, %d)", arr[i], arr[j]);
                first = 0;
            }
        }
    }
    printf("]");
}
