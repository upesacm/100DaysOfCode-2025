#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int value;   
    int arrIdx;  
    int elemIdx; 
} HeapNode;
void swap(HeapNode *a, HeapNode *b) 
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(HeapNode heap[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left].value < heap[smallest].value)
        smallest = left;
    if (right < n && heap[right].value < heap[smallest].value)
        smallest = right;
    if (smallest != i) 
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}
void mergeKSortedArrays(int **arr, int *sizes, int k) 
{
    HeapNode heap[k];
    int totalSize = 0;
    for (int i = 0; i < k; i++) 
    {
        heap[i].value = arr[i][0];
        heap[i].arrIdx = i;
        heap[i].elemIdx = 0;
        totalSize += sizes[i];
    }
    for (int i = (k/2) - 1; i >= 0; i--)
        heapify(heap, k, i);
    int *result = (int *)malloc(totalSize * sizeof(int));
    int resIdx = 0;
    while (1) 
    {
        HeapNode root = heap[0];
        result[resIdx++] = root.value;
        if (root.elemIdx + 1 < sizes[root.arrIdx]) 
        {
            heap[0].value = arr[root.arrIdx][root.elemIdx + 1];
            heap[0].arrIdx = root.arrIdx;
            heap[0].elemIdx = root.elemIdx + 1;
        } 
        else 
        {
            heap[0].value = __INT_MAX__;
        }
        heapify(heap, k, 0);
        if (heap[0].value == __INT_MAX__)
            break;
    }
    printf("Merged sorted array: ");
    for (int i = 0; i < resIdx; i++)
        printf("%d ", result[i]);
    printf("\n");
    free(result);
}
int main() 
{
    int k;
    printf("Enter number of sorted arrays (k): ");
    scanf("%d", &k);
    int *sizes = (int *)malloc(k * sizeof(int));
    int **arr = (int **)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) 
    {
        printf("Enter size of array %d: ", i + 1);
        scanf("%d", &sizes[i]);
        arr[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter %d sorted elements: ", sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    mergeKSortedArrays(arr, sizes, k);
    for (int i = 0; i < k; i++)
        free(arr[i]);
    free(arr);
    free(sizes);
    return 0;
}
