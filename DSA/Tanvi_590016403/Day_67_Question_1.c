#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------- Problem 1: Largest Number from Array ----------
int compare(const void* a, const void* b) {
    char ab[50], ba[50];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab); // custom comparator
}

void largestNumber(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    printf("\nLargest Number formed: ");
    for (int i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

// ---------- Problem 2: Ropes with Minimum Cost ----------
typedef struct {
    int* heap;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->heap = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* h, int i) {
    while (i && h->heap[(i - 1) / 2] > h->heap[i]) {
        swap(&h->heap[i], &h->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap* h, int i) {
    int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

    if (left < h->size && h->heap[left] < h->heap[smallest])
        smallest = left;
    if (right < h->size && h->heap[right] < h->heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapifyDown(h, smallest);
    }
}

void insertHeap(MinHeap* h, int val) {
    h->heap[h->size++] = val;
    heapifyUp(h, h->size - 1);
}

int extractMin(MinHeap* h) {
    if (h->size == 0) return 0;
    int root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapifyDown(h, 0);
    return root;
}

void minCostRopes(int ropes[], int n) {
    MinHeap* h = createHeap(n);
    for (int i = 0; i < n; i++) insertHeap(h, ropes[i]);

    int cost = 0;
    while (h->size > 1) {
        int first = extractMin(h);
        int second = extractMin(h);
        int newRope = first + second;
        cost += newRope;
        insertHeap(h, newRope);
    }
    printf("\nMinimum cost to connect ropes: %d\n", cost);
}

// ---------- Problem 3: Max Non-overlapping Meetings ----------
typedef struct {
    int start, end;
} Meeting;

int compareMeetings(const void* a, const void* b) {
    Meeting* m1 = (Meeting*)a;
    Meeting* m2 = (Meeting*)b;
    return m1->end - m2->end; // sort by end time
}

void maxMeetings(int start[], int end[], int n) {
    Meeting meetings[n];
    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    qsort(meetings, n, sizeof(Meeting), compareMeetings);

    int count = 1;
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; i++) {
        if (meetings[i].start >= lastEnd) {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    printf("\nMaximum number of non-overlapping meetings: %d\n", count);
}

// ---------- Main Function ----------
int main() {
    // Problem 1
    int arr[] = {3, 30, 34, 5, 9};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    largestNumber(arr, n1);

    // Problem 2
    int ropes[] = {4, 3, 2, 6};
    int n2 = sizeof(ropes) / sizeof(ropes[0]);
    minCostRopes(ropes, n2);

    // Problem 3
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n3 = sizeof(start) / sizeof(start[0]);
    maxMeetings(start, end, n3);

    return 0;
}
