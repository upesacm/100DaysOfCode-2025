#include <stdio.h>
#include <stdlib.h>

// Structure for (element, frequency)
typedef struct {
    int element;
    int freq;
} Item;

// Min-Heap for top-k frequent items
void swap(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

void heapifyDown(Item heap[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < n && heap[left].freq < heap[smallest].freq)
        smallest = left;
    if (right < n && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}

void heapifyUp(Item heap[], int i) {
    while (i > 0 && heap[(i-1)/2].freq > heap[i].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insertHeap(Item heap[], int *size, Item val, int k) {
    if (*size < k) {
        heap[*size] = val;
        (*size)++;
        heapifyUp(heap, *size - 1);
    } else if (val.freq > heap[0].freq) {
        heap[0] = val;
        heapifyDown(heap, *size, 0);
    }
}

// Frequency count using array (works for small inputs, extendable with hashmap)
typedef struct {
    int element;
    int freq;
} Freq;

int main() {
    int n, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    // Count frequencies (O(n^2) simple way, can be optimized with hash)
    Freq freqArr[n];
    int freqSize = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < freqSize; j++) {
            if (freqArr[j].element == arr[i]) {
                freqArr[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freqArr[freqSize].element = arr[i];
            freqArr[freqSize].freq = 1;
            freqSize++;
        }
    }

    // Min-Heap for top-k
    Item heap[k];
    int heapSize = 0;

    for (int i = 0; i < freqSize; i++) {
        Item it;
        it.element = freqArr[i].element;
        it.freq = freqArr[i].freq;
        insertHeap(heap, &heapSize, it, k);
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].element);
    printf("\n");

    return 0;
}
