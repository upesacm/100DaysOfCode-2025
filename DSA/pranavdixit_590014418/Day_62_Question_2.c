#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int dist;
} Pair;

void swap(Pair *a, Pair *b) { Pair t=*a; *a=*b; *b=t; }

void heapify(Pair arr[], int n, int i) {
    int largest = i, l=2*i+1, r=2*i+2;
    if (l<n && arr[l].dist > arr[largest].dist) largest=l;
    if (r<n && arr[r].dist > arr[largest].dist) largest=r;
    if (largest!=i) { swap(&arr[i], &arr[largest]); heapify(arr,n,largest); }
}

void buildMaxHeap(Pair arr[], int n) {
    for (int i=n/2-1; i>=0; i--) heapify(arr,n,i);
}

void kClosest(int arr[], int n, int target, int k) {
    Pair heap[k]; int size=0;
    for (int i=0; i<n; i++) {
        int dist = abs(arr[i]-target);
        if (size < k) {
            heap[size++] = (Pair){arr[i], dist};
            if (size==k) buildMaxHeap(heap,k);
        } else if (dist < heap[0].dist) {
            heap[0] = (Pair){arr[i], dist};
            heapify(heap,k,0);
        }
    }
    printf("K closest numbers: ");
    for (int i=0; i<k; i++) printf("%d ", heap[i].num);
    printf("\n");
}

int main() {
    int arr1[] = {1,2,3,4,5};
    kClosest(arr1,5,3,2); // Output: 2 4

    int arr2[] = {5,6,7,8,9};
    kClosest(arr2,5,7,3); // Output: 6 7 8
    return 0;
}
