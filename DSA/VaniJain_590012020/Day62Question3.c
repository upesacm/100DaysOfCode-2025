#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyDown(int heap[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}
void heapifyUp(int heap[], int i) 
{
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] < heap[parent]) 
    {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
void insertHeap(int heap[], int *n, int val) 
{
    heap[*n] = val;
    (*n)++;
    heapifyUp(heap, *n - 1);
}
void replaceRoot(int heap[], int val, int n) 
{
    heap[0] = val;
    heapifyDown(heap, n, 0);
}
int kthLargestSubarraySum(int arr[], int n, int k) 
{
    int *prefix = (int *)malloc((n+1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i+1] = prefix[i] + arr[i];
    int heap[1000];
    int heapSize = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i+1; j <= n; j++) 
        {
            int sum = prefix[j] - prefix[i];
            if (heapSize < k) 
            {
                insertHeap(heap, &heapSize, sum);
            } else if (sum > heap[0]) 
            {
                replaceRoot(heap, sum, heapSize);
            }
        }
    }
    int result = heap[0];
    free(prefix);
    return result;
}
int main() 
{
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter k: ");
    scanf("%d", &k);
    int ans = kthLargestSubarraySum(arr, n, k);
    printf("The %d-th largest subarray sum is: %d\n", k, ans);
    return 0;
}
