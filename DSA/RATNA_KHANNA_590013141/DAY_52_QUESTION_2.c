#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, k;
    printf("enter number of array elements\n");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("enter the elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("enter value of k\n");
    scanf("%d", &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && abs(arr[i] - arr[j]) == k)
                printf("(%d, %d)\n", arr[i], arr[j]);
        }
    }
    free(arr);
    return 0;
}
