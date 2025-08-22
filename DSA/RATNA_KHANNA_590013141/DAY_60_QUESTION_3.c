#include <stdio.h>
#include <stdlib.h>

struct Element {
    int value;
    int freq;
};

void swap(struct Element *a, struct Element *b) {
    struct Element t = *a; *a = *b; *b = t;
}

void minHeapify(struct Element heap[], int size, int i) {
    int smallest = i, left = 2*i+1, right = 2*i+2;
    if (left < size && heap[left].freq < heap[smallest].freq) smallest = left;
    if (right < size && heap[right].freq < heap[smallest].freq) smallest = right;
    if (smallest != i) { swap(&heap[i], &heap[smallest]); minHeapify(heap, size, smallest); }
}

void insertHeap(struct Element heap[], int *size, struct Element val, int k) {
    if (*size < k) {
        heap[*size] = val;
        (*size)++;
        for (int i = (*size)/2 - 1; i >= 0; i--) minHeapify(heap, *size, i);
    } else if (val.freq > heap[0].freq) {
        heap[0] = val;
        minHeapify(heap, *size, 0);
    }
}

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter value of k: ");
    scanf("%d", &k);

    int unique[n], freq[n], uCount = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uCount; j++) {
            if (unique[j] == arr[i]) {
                freq[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[uCount] = arr[i];
            freq[uCount] = 1;
            uCount++;
        }
    }

    struct Element heap[k];
    int heapSize = 0;
    for (int i = 0; i < uCount; i++) {
        struct Element e = {unique[i], freq[i]};
        insertHeap(heap, &heapSize, e, k);
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i].value);
    }
    printf("\n");
    return 0;
}
