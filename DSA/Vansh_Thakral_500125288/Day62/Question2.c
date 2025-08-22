#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int val;
    int dist;
} Node;

typedef struct {
    Node *arr;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->arr = (Node*)malloc(capacity * sizeof(Node));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapifyDown(MaxHeap* heap, int idx) {
    int largest = idx;
    int left = 2*idx+1, right = 2*idx+2;
    if (left < heap->size && heap->arr[left].dist > heap->arr[largest].dist)
        largest = left;
    if (right < heap->size && heap->arr[right].dist > heap->arr[largest].dist)
        largest = right;
    if (largest != idx) {
        swap(&heap->arr[idx], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

void heapifyUp(MaxHeap* heap, int idx) {
    while (idx > 0 && heap->arr[(idx-1)/2].dist < heap->arr[idx].dist) {
        swap(&heap->arr[idx], &heap->arr[(idx-1)/2]);
        idx = (idx-1)/2;
    }
}

void push(MaxHeap* heap, Node node) {
    if (heap->size < heap->capacity) {
        heap->arr[heap->size] = node;
        heap->size++;
        heapifyUp(heap, heap->size-1);
    } else if (node.dist < heap->arr[0].dist) {
        heap->arr[0] = node;
        heapifyDown(heap, 0);
    }
}

void kClosest(int arr[], int n, int target, int k) {
    MaxHeap* heap = createHeap(k);
    for (int i = 0; i < n; i++) {
        Node node = {arr[i], abs(arr[i] - target)};
        push(heap, node);
    }

    printf("K closest: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i].val);
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    kClosest(arr1, 5, 3, 2); 

    int arr2[] = {5, 6, 7, 8, 9};
    kClosest(arr2, 5, 7, 3); 
    return 0;
}
  
