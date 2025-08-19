#include <stdio.h>
#define MAX 100
int heap[MAX];
int heapSize = 0;
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int i) 
{
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) 
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void insert(int val) 
{
    if (heapSize == MAX) 
    {
        printf("Heap overflow!\n");
        return;
    }
    heap[heapSize] = val;
    heapifyUp(heapSize);
    heapSize++;
}
void heapifyDown(int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left] > heap[largest])
        largest = left;

    if (right < heapSize && heap[right] > heap[largest])
        largest = right;

    if (largest != i) 
    {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}
int extractMax() 
{
    if (heapSize <= 0) 
    {
        printf("Heap underflow!\n");
        return -1;
    }
    if (heapSize == 1) 
    {
        heapSize--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return root;
}
void displayHeap() 
{
    printf("Heap elements: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, val;
    while (1) 
    {
        printf("\n1. Insert\n2. Delete Max\n3. Display Heap\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                val = extractMax();
                if (val != -1)
                    printf("Deleted Max = %d\n", val);
                break;
            case 3:
                displayHeap();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
