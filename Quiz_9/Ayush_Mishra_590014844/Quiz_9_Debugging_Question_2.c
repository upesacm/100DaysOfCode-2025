#include <stdio.h>

#define MAX 99

void heapifyDown(int heap[], int size, int index)
{
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left <= size && heap[left] > heap[largest])
        largest = left;
    if (right <= size && heap[right] > heap[largest])
        largest = right;

    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, size, largest);
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
    {
        printf("Heap is empty, cannot delete\n");
        return;
    }

    heap[1] = heap[*size];
    (*size)--;
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[MAX] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6;

    deleteMax(heap, &size);

    printf("Heap after deletion: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}
