#include <stdio.h>
#define MAX 99
void heapifyUp(int heap[], int index)
{
    while (index > 1 && heap[index / 2] < heap[index])
    {
        int parent = index / 2;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent;
    }
}

void insert(int heap[], int *size, int value)
{
    if (*size >= MAX - 1)
    {
        printf("Heap overflow cannot insert more elements\n");
        return;
    }

    (*size)++;
    heap[*size] = value;
    heapifyUp(heap, *size);
}

int main()
{
    int heap[MAX] = {0, 50, 30, 40, 10, 20}; // 1-indexed
    int size = 5;

    insert(heap, &size, 60);

    printf("Heap after insertion: ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");

    return 0;
}
