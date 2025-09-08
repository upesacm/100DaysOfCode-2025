#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure for a frequency entry
typedef struct {
    char ch;
    int freq;
} CharFreq;

// A structure for Max Heap
typedef struct {
    CharFreq* arr;
    int size;
    int capacity;
} MaxHeap;

void swap(CharFreq* a, CharFreq* b) {
    CharFreq temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MaxHeap* heap, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left].freq > heap->arr[largest].freq) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right].freq > heap->arr[largest].freq) {
        largest = right;
    }

    if (largest != i) {
        swap(&heap->arr[i], &heap->arr[largest]);
        heapify(heap, largest);
    }
}

void insertHeap(MaxHeap* heap, CharFreq item) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = item;

    while (i != 0 && heap->arr[(i - 1) / 2].freq < heap->arr[i].freq) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

CharFreq extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        CharFreq empty = {'\0', 0};
        return empty;
    }
    CharFreq root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Rearrange Characters (Greedy Frequency)
char* rearrangeString(char* s) {
    int freq[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        freq[s[i] - 'a']++;
    }

    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->capacity = 26;
    heap->size = 0;
    heap->arr = (CharFreq*)malloc(heap->capacity * sizeof(CharFreq));

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            CharFreq item;
            item.ch = 'a' + i;
            item.freq = freq[i];
            insertHeap(heap, item);
        }
    }

    char* result = (char*)malloc((strlen(s) + 1) * sizeof(char));
    int res_idx = 0;

    CharFreq prev = {'#', -1};

    while (heap->size > 0) {
        CharFreq current = extractMax(heap);
        result[res_idx++] = current.ch;
        current.freq--;

        if (prev.freq > 0) {
            insertHeap(heap, prev);
        }
        prev = current;
    }
    result[res_idx] = '\0';

    if (res_idx != strlen(s)) {
        return "";
    }

    return result;
}

int main() {
    // Example 1
    char s1[] = "aab";
    printf("Rearranged string: %s\n", rearrangeString(s1));

    // Example 2
    char s2[] = "aaab";
    printf("Rearranged string: %s\n", rearrangeString(s2));

    return 0;
}
