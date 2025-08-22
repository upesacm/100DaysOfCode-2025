1) Bug in the heapifyUp loop condition

Your loop is while (index > 1), which keeps moving index upward even when no swap is needed. That means you start comparing (and potentially swapping) other nodes instead of continuing to bubble up the newly inserted value.
Fix: Include the heap-order test in the loop condition (or break when it fails):

while (index > 1 && heap[index/2] < heap[index]) { ... }

2) Why must we swap before moving index to parent?

index is supposed to “follow” the inserted element as it climbs up. If you move index to the parent without swapping, index stops pointing at the inserted value and you’ll compare the wrong node on the next iteration. Swapping first keeps index tracking the inserted value correctly.

3) Debugged & corrected code

Here’s a clean, correct version using early-stop logic:

#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    while (index > 1 && heap[index / 2] < heap[index]) {
        int parent = index / 2;
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        index = parent; 
    }
}

void insert(int heap[], int *size, int value)
{
    (*size)++;
    heap[*size] = value;      
    heapifyUp(heap, *size);  
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20}; // 1-indexed: heap[1..5] in use
    int size = 5;

    insert(heap, &size, 60);

    for (int i = 1; i <= size; i++) {
        printf("%d ", heap[i]);
    }
    return 0;
}
