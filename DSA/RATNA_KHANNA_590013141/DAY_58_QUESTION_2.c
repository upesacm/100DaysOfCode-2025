#include <stdio.h>
void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
        heapify(arr, n, largest);
    }
}
int main() {
    int n;
     printf("enter number of elements\n");
    scanf("%d", &n);
    int arr[n];
     printf("enter elements\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    printf("A valid max-heap array");
}
