//Bug in array indexing when calling deleteMax
//int heap[100] = {0, 50, 30, 40, 10, 20, 35}; // 1-indexed
//int size = 6;
//This array has 6 valid elements (index 1–6), but you initialized 7 numbers (0 dummy + 6 values).
//	•	size should actually be 7, not 6.
//	•	Otherwise, the last element (35) is ignored and heap structure becomes inconsistent.
//Fix  int size = 7; 

//2. Why replace root with last element before heapifying down?
//	•	In a Max Heap, the root is the maximum element.
//	•	To delete it:
//	1.	Replace the root with the last element (to keep heap complete/balanced).
//	2.	Reduce heap size by 1.
//	3.	Call heapifyDown → this pushes the new root down until heap property is restored.

//If we didn’t replace with the last element, the heap would either have a hole at the top or become unbalanced.



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
        
    heap[1] = heap[*size];
    (*size)--;

    
    heapifyDown(heap, *size, 1);
}

int main()
{
    int heap[100] = {0, 50, 30, 40, 10, 20, 35}; 
    int size = 7; 

    deleteMax(heap, &size);

    for (int i = 1; i <= size; i++)
    {
        printf("%d ", heap[i]);
    }

    return 0;
}
