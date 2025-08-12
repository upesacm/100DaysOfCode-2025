#include <stdio.h>
void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
        heapify(arr, n, smallest);
    }
}
int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapify(arr, *n, 0);
    return root;
}
int main() {
    int n, k;
    printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("enter value of k\n");
    scanf("%d", &k);
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = 1; i < k; i++) extractMin(arr, &n);
    printf("output-%d", extractMin(arr, &n));
}
