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
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
    int size = 7; // corrected size
    deleteMax(heap, &size);
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

/*
Task Question Answer:
1. Bug: size was initialized as 6 instead of 7, causing last element to be ignored.
2. Root is replaced with last element to maintain complete binary tree structure before reordering.
3. Fixed by setting initial size = 7 so deleteMax and heapifyDown handle all elements correctly.
*/
