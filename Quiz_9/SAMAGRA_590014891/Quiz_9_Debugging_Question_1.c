#include <stdio.h>

// Function to restore Max Heap property after insertion
void heapifyUp(int heap[], int index)
{
    while (index > 1)  // Correct condition since we are using 1-indexed heap
    {
        int parent = index / 2;

        // Task 1: Bug was that index was moved up even if no swap happened
        // Fixed: Only move index up when a swap occurs, otherwise break

        if (heap[parent] < heap[index])
        {
            // Swap child with parent if heap property is violated
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            // Task 2: We must swap first to restore heap property,
            // then move index to parent for further checking.
            index = parent;  
        }
        else
        {
            // If parent is already larger, heap property satisfied → stop
            break;
        }
    }
}

// Function to insert an element into the Max Heap
void insert(int heap[], int *size, int value)
{
    (*size)++;              // Increase heap size
    heap[*size] = value;    // Place new element at the end
    heapifyUp(heap, *size); // Restore heap property by moving up
}

int main()
{
    // Initial heap: 1-indexed representation
    int heap[100] = {0, 50, 30, 40, 10, 20};
    int size = 5;

    // Insert a new element (60) into the Max Heap
    insert(heap, &size, 60);

    // Task 3: Debugged code now correctly maintains Max Heap property
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }
    return 0;
}
