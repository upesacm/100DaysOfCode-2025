#include <stdio.h>

int isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[i] < arr[l]) return 0;
        if (r < n && arr[i] < arr[r]) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (isMaxHeap(arr, n)) printf("true");
    else printf("false");
    return 0;
}
