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



// Tasks:
// 1. Identify the bug in array indexing when calling deleteMax.
// 2. Why do we replace the root with the last element before heapifying down?
// to cheack and maintain the heap property
// 3. Debug the code for correct deletion in all cases.