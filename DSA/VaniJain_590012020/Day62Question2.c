#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct 
{
    int value;
    int distance;
} Node;
void swap(Node *a, Node *b) 
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyDown(Node heap[], int n, int i) 
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left].distance > heap[largest].distance)
        largest = left;
    if (right < n && heap[right].distance > heap[largest].distance)
        largest = right;
    if (largest != i) 
    {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}
void heapifyUp(Node heap[], int i) 
{
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i].distance > heap[parent].distance) 
    {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
void insertHeap(Node heap[], int *n, Node item) 
{
    heap[*n] = item;
    (*n)++;
    heapifyUp(heap, *n - 1);
}
Node extractMax(Node heap[], int *n) 
{
    Node root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}
void findKClosest(int arr[], int n, int k, int target) 
{
    Node heap[1000];
    int heapSize = 0;
    for (int i = 0; i < n; i++) 
    {
        Node item;
        item.value = arr[i];
        item.distance = abs(arr[i] - target);
        if (heapSize < k) 
        {
            insertHeap(heap, &heapSize, item);
        } 
        else if (item.distance < heap[0].distance) 
        {
            extractMax(heap, &heapSize);
            insertHeap(heap, &heapSize, item);
        }
    }
    printf("The %d closest numbers to %d are: ", k, target);
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", heap[i].value);
    }
    printf("\n");
}
int main() 
{
    int n, k, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter target: ");
    scanf("%d", &target);
    printf("Enter k: ");
    scanf("%d", &k);\
    findKClosest(arr, n, k, target);
    return 0;
}
