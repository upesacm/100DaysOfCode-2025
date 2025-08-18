//1.int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
//int size = 6;
//2.The maximum element is always at the root (heap[1]).If we just removed it, we’d have a “hole” at the root.
//To maintain the complete binary tree structure, we:Move the last element to the root (heap[1] = heap[size]).Decrease size.
//Call heapifyDown so the new root sinks to its correct position.
//3.
#include <stdio.h>

void heapifyDown(int heap[], int size, int index)
{
    while (1)
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
            index = largest;  // continue sinking
        }
        else
        {
            break; // already heapified
        }
    }
}

void deleteMax(int heap[], int *size)
{
    if (*size == 0)
        return;

    // Move last element to root
    heap[1] = heap[*size];
    (*size)--;

    // Restore heap property
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 6;

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
