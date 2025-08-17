#include <stdio.h>

void heapifyUp(int heap[], int index)
{
    // BUG 1: Condition was while(index > 1). That's correct,
    // but "index = parent" should happen ONLY if swap occurs,
    // otherwise it leads to unnecessary re-checks.
    // Fixed: Move index update inside swap block.
    while (index > 1)
    {
        int parent = index / 2;

        // If child is greater than parent → swap
        if (heap[parent] < heap[index])
        {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // BUG 2: Must move index up only after swap
            index = parent;
        }
        else
        {
            // If no swap, break early
            break;
        }
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
    // Max Heap (1-indexed representation)
    int heap[100] = {0, 50, 30, 40, 10, 20}; 
    int size = 5;

    insert(heap, &size, 60);

    // Expected output: 60 50 40 10 20 30
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}

/*
Tasks Answers:
1. Bug: heapifyUp loop always updated index = parent, even without swap → wrong.
2. Swap must occur before moving up, otherwise comparisons happen with wrong elements.
3. Debugged by moving index update inside the swap block and adding break if no swap needed.
*/
