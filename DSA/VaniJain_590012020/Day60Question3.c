#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000
typedef struct 
{
    int element;
    int frequency;
} HeapNode;
typedef struct 
{
    HeapNode arr[MAX_SIZE];
    int size;
} MinHeap;
void swap(HeapNode *a, HeapNode *b) 
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(MinHeap *heap, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < heap->size && heap->arr[left].frequency < heap->arr[smallest].frequency)
        smallest = left;
    if (right < heap->size && heap->arr[right].frequency < heap->arr[smallest].frequency)
        smallest = right;

    if (smallest != i) 
    {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}
void insertHeap(MinHeap *heap, HeapNode node, int k) 
{
    if (heap->size < k) 
    {
        heap->arr[heap->size] = node;
        int i = heap->size++;
        while (i != 0 && heap->arr[(i - 1) / 2].frequency > heap->arr[i].frequency) 
        {
            swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    } 
    else if (node.frequency > heap->arr[0].frequency) 
    {
        heap->arr[0] = node;
        minHeapify(heap, 0);
    }
}
int main() 
{
    int n, k;
    int arr[MAX_SIZE];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter k (number of most frequent elements): ");
    scanf("%d", &k);
    int visited[MAX_SIZE] = {0};
    HeapNode freqArr[MAX_SIZE];
    int freqCount = 0;
    for (int i = 0; i < n; i++) 
    {
        if (visited[i])
            continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] == arr[j]) 
            {
                visited[j] = 1;
                count++;
            }
        }
        freqArr[freqCount].element = arr[i];
        freqArr[freqCount].frequency = count;
        freqCount++;
    }
    MinHeap heap;
    heap.size = 0;
    for (int i = 0; i < freqCount; i++) 
    {
        insertHeap(&heap, freqArr[i], k);
    }
    printf("Top %d most frequent elements:\n", k);
    for (int i = 0; i < heap.size; i++) 
    {
        printf("Element: %d, Frequency: %d\n", heap.arr[i].element, heap.arr[i].frequency);
    }
    return 0;
}
