#include <stdio.h>

#define MAX 1000

int main() {
    int n, k, i, j;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    for(i = 0; i <= n - k; i++) {
        int max = arr[i];
        for(j = i + 1; j < i + k; j++) {
            if(arr[j] > max) max = arr[j];
        }
        printf("%d ", max);
    }
    printf("\n");
    return 0;
}
