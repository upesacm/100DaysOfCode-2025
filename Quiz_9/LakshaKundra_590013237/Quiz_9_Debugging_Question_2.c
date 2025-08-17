//the bug is 
//This array is 1-indexed

//answer 2
//In a Max Heap, the root holds the maximum. When deleting, we must remove the root. To maintain the complete binary tree structure, we move the last element into the root position.

//correct code 
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

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
