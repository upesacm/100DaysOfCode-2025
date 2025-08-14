#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapifyUp(int arr[], int n, int isMax) {
    int i = n - 1;
    while (i > 0) {
        int p = (i - 1) / 2;
        if ((isMax && arr[i] > arr[p]) || (!isMax && arr[i] < arr[p])) {
            swap(&arr[i], &arr[p]);
            i = p;
        } else break;
    }
}

void heapifyDown(int arr[], int n, int i, int isMax) {
    int l = 2 * i + 1, r = 2 * i + 2, target = i;
    if (l < n && ((isMax && arr[l] > arr[target]) || (!isMax && arr[l] < arr[target]))) target = l;
    if (r < n && ((isMax && arr[r] > arr[target]) || (!isMax && arr[r] < arr[target]))) target = r;
    if (target != i) {
        swap(&arr[i], &arr[target]);
        heapifyDown(arr, n, target, isMax);
    }
}

void insert(int arr[], int *n, int val, int isMax) {
    arr[(*n)++] = val;
    heapifyUp(arr, *n, isMax);
}

int extract(int arr[], int *n, int isMax) {
    int root = arr[0];
    arr[0] = arr[--(*n)];
    heapifyDown(arr, *n, 0, isMax);
    return root;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int maxHeap[1000], minHeap[1000], maxSize = 0, minSize = 0;
    printf("Enter stream: ");
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (maxSize == 0 || num <= maxHeap[0]) insert(maxHeap, &maxSize, num, 1);
        else insert(minHeap, &minSize, num, 0);

        if (maxSize > minSize + 1) insert(minHeap, &minSize, extract(maxHeap, &maxSize, 1), 0);
        else if (minSize > maxSize) insert(maxHeap, &maxSize, extract(minHeap, &minSize, 0), 1);

        if (maxSize == minSize) printf("%.1f ", (maxHeap[0] + minHeap[0]) / 2.0);
        else printf("%.1f ", (float)maxHeap[0]);
    }
    return 0;
}
