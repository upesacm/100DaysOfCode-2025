#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}
void heapifyDown(int heap[], int n, int i) 
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) 
    {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}
void heapifyUp(int heap[], int i) 
{
    int parent = (i - 1) / 2;
    if (i > 0 && heap[i] < heap[parent]) 
    {
        swap(&heap[i], &heap[parent]);
        heapifyUp(heap, parent);
    }
}
int extractMin(int heap[], int *n) 
{
    if (*n <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}
void insertHeap(int heap[], int *n, int key) 
{
    heap[*n] = key;
    (*n)++;
    heapifyUp(heap, *n - 1);
}
int minCostRopes(int ropes[], int n) 
{
    int heap[1000];  
    int heapSize = 0;
    for (int i = 0; i < n; i++)
        insertHeap(heap, &heapSize, ropes[i]);
    int totalCost = 0;
    while (heapSize > 1) 
    {
        int first = extractMin(heap, &heapSize);
        int second = extractMin(heap, &heapSize);
        int cost = first + second;
        totalCost += cost;
        insertHeap(heap, &heapSize, cost);
    }
    return totalCost;
}
int main() 
{
    int n;
    printf("Enter number of ropes: ");
    scanf("%d", &n);
    int ropes[n];
    printf("Enter lengths of ropes: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ropes[i]);
    int result = minCostRopes(ropes, n);
    printf("Minimum cost to connect ropes: %d\n", result);
    return 0;
}
