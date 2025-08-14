#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void replaceRoot(int arr[], int n, int newElement) {
    arr[0] = newElement;
    heapify(arr, n, 0);
}

int main() {
    int n, newElement;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter max-heap elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter new root element: ");
    scanf("%d", &newElement);

    replaceRoot(arr, n, newElement);

    printf("New heap array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
