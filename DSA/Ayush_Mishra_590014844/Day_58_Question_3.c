#include <stdio.h>
void maxHeapify(int arr[], int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, largest, n);
    }
}

void replaceRoot(int arr[], int n, int newElement) {
    arr[0] = newElement;
    maxHeapify(arr, 0, n);
}

int main() {
    int n, newElement;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &newElement);

    replaceRoot(arr, n, newElement);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
