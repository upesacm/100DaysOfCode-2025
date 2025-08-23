#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 26


typedef struct {
    char ch;
    int freq;
} CharFreq;


void heapify(CharFreq heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left].freq > heap[largest].freq)
        largest = left;
    if (right < n && heap[right].freq > heap[largest].freq)
        largest = right;

    if (largest != i) {
        CharFreq temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}


void buildHeap(CharFreq heap[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(heap, n, i);
}


CharFreq extractMax(CharFreq heap[], int *n) {
    CharFreq max = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return max;
}


void insertHeap(CharFreq heap[], int *n, CharFreq item) {
    heap[(*n)++] = item;
    int i = *n - 1;
    while (i > 0 && heap[(i - 1)/2].freq < heap[i].freq) {
        CharFreq temp = heap[i];
        heap[i] = heap[(i - 1)/2];
        heap[(i - 1)/2] = temp;
        i = (i - 1)/2;
    }
}


char* rearrangeString(char* str) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;

    CharFreq heap[MAX_CHAR];
    int heapSize = 0;

    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            heap[heapSize].ch = 'a' + i;
            heap[heapSize].freq = freq[i];
            heapSize++;
        }
    }

    buildHeap(heap, heapSize);

    char* result = (char*)malloc(len + 1);
    int idx = 0;
    CharFreq prev = {'#', 0};

    while (heapSize > 0) {
        CharFreq curr = extractMax(heap, &heapSize);
        result[idx++] = curr.ch;
        curr.freq--;

        if (prev.freq > 0)
            insertHeap(heap, &heapSize, prev);

        prev = curr;
    }

    result[idx] = '\0';

    if (idx != len) {
        free(result);
        return "";
    }

    return result;
}

int main() {
    char input1[] = "aab";
    char input2[] = "aaab";

    printf("Rearranged (\"%s\"): %s\n", input1, rearrangeString(input1));  
    printf("Rearranged (\"%s\"): %s\n", input2, rearrangeString(input2)); 

    return 0;
}
