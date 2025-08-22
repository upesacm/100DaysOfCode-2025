#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    int freq;
} HeapNode;

typedef struct {
    HeapNode* nodes;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->nodes = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    while (index > 0 && heap->nodes[parent(index)].freq > heap->nodes[index].freq) {
        swap(&heap->nodes[index], &heap->nodes[parent(index)]);
        index = parent(index);
    }
}

void heapifyDown(MinHeap* heap, int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap->size && heap->nodes[left].freq < heap->nodes[minIndex].freq) {
        minIndex = left;
    }
    
    if (right < heap->size && heap->nodes[right].freq < heap->nodes[minIndex].freq) {
        minIndex = right;
    }
    
    if (index != minIndex) {
        swap(&heap->nodes[index], &heap->nodes[minIndex]);
        heapifyDown(heap, minIndex);
    }
}

void insertMinHeap(MinHeap* heap, int value, int freq) {
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size].value = value;
        heap->nodes[heap->size].freq = freq;
        heapifyUp(heap, heap->size);
        heap->size++;
    } else if (freq > heap->nodes[0].freq) {
        heap->nodes[0].value = value;
        heap->nodes[0].freq = freq;
        heapifyDown(heap, 0);
    }
}

int compareFrequencies(const void* a, const void* b) {
    return ((HeapNode*)b)->freq - ((HeapNode*)a)->freq;
}

int* topKFrequent(int arr[], int n, int k, int* resultSize) {
    if (k <= 0 || n < k) {
        *resultSize = 0;
        return NULL;
    }
    
    int maxUnique = n;
    HeapNode* freq = (HeapNode*)malloc(maxUnique * sizeof(HeapNode));
    int uniqueCount = 0;
    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (freq[j].value == arr[i]) {
                freq[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[uniqueCount].value = arr[i];
            freq[uniqueCount].freq = 1;
            uniqueCount++;
        }
    }
    
    if (k > uniqueCount) {
        k = uniqueCount;
    }
    
    MinHeap* heap = createMinHeap(k);
    
    for (int i = 0; i < uniqueCount; i++) {
        insertMinHeap(heap, freq[i].value, freq[i].freq);
    }
    
    int* result = (int*)malloc(k * sizeof(int));
    *resultSize = k;
    for (int i = k - 1; i >= 0; i--) {
        result[i] = heap->nodes[0].value;
        heap->nodes[0] = heap->nodes[heap->size - 1];
        heap->size--;
        heapifyDown(heap, 0);
    }
    
    free(freq);
    free(heap->nodes);
    free(heap);
    return result;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int* readInputArray(int* n) {
    printf("Enter the elements of the array separated by spaces: ");
    char line[1000];
    fgets(line, sizeof(line), stdin);
    
    int* arr = NULL;
    int capacity = 0;
    *n = 0;
    
    char* token = strtok(line, " ");
    while (token != NULL) {
        if (*n >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            arr = (int*)realloc(arr, capacity * sizeof(int));
        }
        arr[(*n)++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    return arr;
}

int main() {
    int n, k;
    int* arr = readInputArray(&n);
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int resultSize;
    int* result = topKFrequent(arr, n, k, &resultSize);
    
    if (result) {
        printf("Output: ");
        printArray(result, resultSize);
        free(result);
    } else {
        printf("Invalid input or no result.\n");
    }
    
    free(arr);
    return 0;
}
