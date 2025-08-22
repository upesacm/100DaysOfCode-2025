#include <stdio.h>
#include <stdlib.h>

#define MAX 9999

int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n], hash[MAX] = {0};
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        hash[arr[i]] = 1;
    }
    printf("Enter difference value k: ");
    scanf("%d", &k);
    printf("Pairs with difference %d:\n", k);
    for (int i = 0; i < n; i++) {
        if (arr[i] + k < MAX && hash[arr[i] + k])
            printf("(%d, %d)\n", arr[i], arr[i] + k);
        if (arr[i] - k >= 0 && hash[arr[i] - k])
            printf("(%d, %d)\n", arr[i], arr[i] - k);
    }
    return 0;
}
