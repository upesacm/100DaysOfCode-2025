#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} Node;

void swap(Node *a, Node *b) { Node t = *a; *a = *b; *b = t; }

void heapify(Node heap[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l].freq > heap[largest].freq) largest = l;
    if (r < n && heap[r].freq > heap[largest].freq) largest = r;
    if (largest != i) { swap(&heap[i], &heap[largest]); heapify(heap,n,largest); }
}

Node extractMax(Node heap[], int *n) {
    Node root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}

void insertHeap(Node heap[], int *n, Node node) {
    int i = (*n)++;
    heap[i] = node;
    while (i && heap[(i-1)/2].freq < heap[i].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

char* rearrangeString(char *s) {
    int n = strlen(s), freq[256] = {0};
    for (int i = 0; i < n; i++) freq[(int)s[i]]++;

    Node heap[n]; int size = 0;
    for (int i = 0; i < 256; i++) if (freq[i]) {
        heap[size].ch = i; heap[size].freq = freq[i]; size++;
    }
    for (int i = size/2-1; i >= 0; i--) heapify(heap, size, i);

    char *res = malloc(n+1); int idx = 0;
    Node prev = {'#',0};
    while (size > 0) {
        Node cur = extractMax(heap,&size);
        res[idx++] = cur.ch;
        if (prev.freq > 0) insertHeap(heap,&size,prev);
        cur.freq--; prev = cur;
    }
    res[idx] = '\0';
    return (idx == n) ? res : "";
}

int main() {
    printf("Rearranged: %s\n", rearrangeString("aab"));   // "aba"
    printf("Rearranged: %s\n", rearrangeString("aaab"));  // ""
    return 0;
}
