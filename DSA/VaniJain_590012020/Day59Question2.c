#include <stdio.h>
#include <stdlib.h>
#define MAX 1000  
typedef struct {

    int arr[MAX];
    int size;
} MaxHeap;
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleUp(MaxHeap *heap, int index) 
{
    while (index > 0) 
    {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] < heap->arr[index]) 
        {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } 
        else 
        {
            break;
        }
    }
}
void bubbleDown(MaxHeap *heap, int index) 
{
    int left, right, largest;
    while (1) 
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;
        if (left < heap->size && heap->arr[left] > heap->arr[largest])
            largest = left;
        if (right < heap->size && heap->arr[right] > heap->arr[largest])
            largest = right;
        if (largest != index) 
        {
            swap(&heap->arr[index], &heap->arr[largest]);
            index = largest;
        }
        else 
        {
            break;
        }
    }
}
void insert(MaxHeap *heap, int value) 
{
    if (heap->size == MAX) 
    {
        printf("Priority Queue is full!\n");
        return;
    }
    heap->arr[heap->size] = value;
    bubbleUp(heap, heap->size);
    heap->size++;
}
int extractMax(MaxHeap *heap) 
{
    if (heap->size <= 0) 
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    bubbleDown(heap, 0);
    return root;
}
int peekMax(MaxHeap *heap) 
{
    if (heap->size <= 0) 
    {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return heap->arr[0];
}
void printHeap(MaxHeap *heap) 
{
    printf("Priority Queue elements: ");
    for (int i = 0; i < heap->size; i++) 
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}
int main() 
{
    MaxHeap heap;
    heap.size = 0;
    int choice, value;
    while (1) 
    {
        printf("\n--- Priority Queue (Max-Heap) Menu ---\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Peek Max\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
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
                value = extractMax(&heap);
                if (value != -1)
                    printf("Extracted Max = %d\n", value);
                break;
            case 3:
                value = peekMax(&heap);
                if (value != -1)
                    printf("Maximum Element = %d\n", value);
                break;
            case 4:
                printHeap(&heap);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
