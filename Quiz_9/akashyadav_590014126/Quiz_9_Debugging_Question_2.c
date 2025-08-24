#include <stdio.h>

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
        return;

    heap[1] = heap[*size];

    (*size)--;

    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35};
    int size = 6;

    printf("Initial heap: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    deleteMax(heap, &size);

    printf("Heap after deleting the max element: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}

//There is no bug in the provided code related to array indexing or the size variable's initialization. The heap [50, 30, 40, 10, 20, 35] contains 6 elements, and int size = 6; correctly reflects this.
//We replace the root with the last element to ensure the heap's complete binary tree structure is maintained and to achieve O(1) time complexity for the removal. This method avoids shifting all subsequent elements, which would be an O(n) operation. 