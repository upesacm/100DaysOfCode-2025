#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && heap[l].freq > heap[largest].freq) largest = l;
    if (r < n && heap[r].freq > heap[largest].freq) largest = r;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

void buildHeap(CharFreq heap[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(heap, n, i);
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    int freq[26] = {0}, len = strlen(str);
    for (int i = 0; i < len; i++) freq[str[i] - 'a']++;

    CharFreq heap[26];
    int heapSize = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            heap[heapSize].ch = 'a' + i;
            heap[heapSize].freq = freq[i];
            heapSize++;
        }
    }

    buildHeap(heap, heapSize);
    char result[100];
    int idx = 0;
    CharFreq prev = {'#', 0};

    while (heapSize > 0) {
        CharFreq curr = heap[0];
        heap[0] = heap[--heapSize];
        heapify(heap, heapSize, 0);

        result[idx++] = curr.ch;
        curr.freq--;

        if (prev.freq > 0) {
            heap[heapSize++] = prev;
            buildHeap(heap, heapSize);
        }
        prev = curr;
    }

    result[idx] = '\0';
    if (idx == len)
        printf("Rearranged string: %s\n", result);
    else
        printf("Not possible to rearrange\n");

    return 0;
}
