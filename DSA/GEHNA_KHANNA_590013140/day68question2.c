#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int freq;
} Node;

void heapify(Node *heap, int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && heap[l].freq > heap[largest].freq) largest = l;
    if (r < n && heap[r].freq > heap[largest].freq) largest = r;
    if (largest != i) {
        Node tmp = heap[i]; heap[i] = heap[largest]; heap[largest] = tmp;
        heapify(heap, n, largest);
    }
}

void buildHeap(Node *heap, int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(heap, n, i);
}

Node extractMax(Node *heap, int *n) {
    Node max = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return max;
}

void insertHeap(Node *heap, int *n, Node val) {
    int i = (*n)++;
    heap[i] = val;
    while (i > 0 && heap[(i-1)/2].freq < heap[i].freq) {
        Node tmp = heap[i]; heap[i] = heap[(i-1)/2]; heap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

int main(void) {
    char str[100];
    scanf("%s", str);
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) freq[(unsigned char)str[i]]++;

    Node heap[256];
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap[size].ch = (char)i;
            heap[size].freq = freq[i];
            size++;
        }
    }
    buildHeap(heap, size);

    char result[200] = "";
    Node prev = {'#', 0};
    while (size > 0) {
        Node curr = extractMax(heap, &size);
        int len = strlen(result);
        result[len] = curr.ch;
        result[len+1] = '\0';
        curr.freq--;

        if (prev.freq > 0) insertHeap(heap, &size, prev);
        prev = curr;
    }

    // Check validity
    for (int i = 1; i < strlen(result); i++) {
        if (result[i] == result[i-1]) {
            printf("\n"); // impossible
            return 0;
        }
    }
    printf("%s\n", result);
    return 0;
}
