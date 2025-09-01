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
    while (i > 0 && heap[(i-1)/2] > heap[i]) 
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}
int extractMin(int heap[], int *n) 
{
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}
void insertHeap(int heap[], int *n, int val) 
{
    heap[*n] = val;
    (*n)++;
    heapifyUp(heap, *n - 1);
}
int minCostToConnectRopes(int ropes[], int n) 
{
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyDown(ropes, n, i);
    int totalCost = 0;
    while (n > 1) 
    {
        int first = extractMin(ropes, &n);
        int second = extractMin(ropes, &n);
        int cost = first + second;
        totalCost += cost;
        insertHeap(ropes, &n, cost);
    }
    return totalCost;
}
int main() 
{
    int ropes[] = {4, 3, 2, 6};
    int n = sizeof(ropes)/sizeof(ropes[0]);
    int result = minCostToConnectRopes(ropes, n);
    printf("Minimum total cost to connect ropes: %d\n", result);
    return 0;
}
