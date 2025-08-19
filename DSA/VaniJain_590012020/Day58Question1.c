#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(int arr[], int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) 
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void buildMinHeap(int arr[], int n) 
{
    for (int i = (n / 2) - 1; i >= 0; i--) 
    {
        minHeapify(arr, n, i);
    }
}
int extractMin(int arr[], int *n) 
{
    if (*n <= 0) return __INT_MAX__;
    if (*n == 1) {
        (*n)--;
        return arr[0];
    }
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return root;
}
int kthSmallest(int arr[], int n, int k) 
{
    buildMinHeap(arr, n);
    for (int i = 0; i < k - 1; i++) 
    {
        extractMin(arr, &n);
    }
    return arr[0];
}
int main() 
{
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    if (k > 0 && k <= n) 
    {
        int result = kthSmallest(arr, n, k);
        printf("The %d-th smallest element is %d\n", k, result);
    } 
    else 
    {
        printf("Invalid value of k.\n");
    }
    return 0;
}
