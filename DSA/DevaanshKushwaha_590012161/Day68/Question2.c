#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

void swap(CharFreq *a, CharFreq *b) {
    CharFreq temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(CharFreq heap[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l].freq > heap[largest].freq) largest = l;
    if (r < n && heap[r].freq > heap[largest].freq) largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

CharFreq extractMax(CharFreq heap[], int *n) {
    CharFreq root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}

void insertHeap(CharFreq heap[], int *n, CharFreq item) {
    heap[*n] = item;
    int i = *n;
    (*n)++;
    while (i != 0 && heap[(i - 1) / 2].freq < heap[i].freq) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

char* rearrangeString(char *str) {
    int freq[256] = {0};
    int n = strlen(str);

    for (int i = 0; i < n; i++) freq[(int)str[i]]++;

    CharFreq heap[256];
    int heapSize = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap[heapSize].ch = (char)i;
            heap[heapSize].freq = freq[i];
            heapSize++;
        }
    }

    for (int i = heapSize / 2 - 1; i >= 0; i--) heapify(heap, heapSize, i);

    char *result = (char*)malloc(n + 1);
    int idx = 0;

    CharFreq prev = {'#', 0};

    while (heapSize > 0) {
        CharFreq curr = extractMax(heap, &heapSize);
        result[idx++] = curr.ch;

        if (prev.freq > 0) insertHeap(heap, &heapSize, prev);

        curr.freq--;
        prev = curr;
    }

    result[idx] = '\0';

    if (idx != n) {
        free(result);
        return "";
    }
    return result;
}

int main() {
    char str1[] = "aab";
    char str2[] = "aaab";

    printf("Input: %s → Output: %s\n", str1, rearrangeString(str1));
    printf("Input: %s → Output: %s\n", str2, rearrangeString(str2));

    return 0;
}
