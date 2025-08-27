#include <stdio.h>
#include <stdlib.h>
#define MAX 1000  
typedef struct 
{
    int arr[MAX];
    int size;
} MinHeap;
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleUp(MinHeap *heap, int index) 
{
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] > heap->arr[index]) {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}
void bubbleDown(MinHeap *heap, int index) 
{
    int left, right, smallest;
    while (1) 
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;
        if (left < heap->size && heap->arr[left] < heap->arr[smallest])
            smallest = left;
        if (right < heap->size && heap->arr[right] < heap->arr[smallest])
            smallest = right;
        if (smallest != index) 
        {
            swap(&heap->arr[index], &heap->arr[smallest]);
            index = smallest;
        } 
        else 
        {
            break;
        }
    }
}
void insert(MinHeap *heap, int value) 
{
    if (heap->size == MAX) 
    {
        printf("Heap is full!\n");
        return;
    }
    heap->arr[heap->size] = value;
    bubbleUp(heap, heap->size);
    heap->size++;
}
int extractMin(MinHeap *heap) 
{
    if (heap->size <= 0) 
    {
        printf("Heap is empty!\n");
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    bubbleDown(heap, 0);
    return root;
}
void printHeap(MinHeap *heap) 
{
    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) 
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}
int main() 
{
    MinHeap heap;
    heap.size = 0;
    int choice, value;
    while (1) 
    {
        printf("\n--- Min-Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Print Heap\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&heap, value);
                break;
            case 2:
                value = extractMin(&heap);
                if (value != -1)
                    printf("Extracted Min = %d\n", value);
                break;
            case 3:
                printHeap(&heap);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
