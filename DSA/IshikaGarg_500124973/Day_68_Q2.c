#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} Node;

// Swap function
void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down
void heapify(Node heap[], int n, int i) {
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < n && heap[left].freq > heap[largest].freq) largest = left;
    if (right < n && heap[right].freq > heap[largest].freq) largest = right;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

// Build max heap
void buildHeap(Node heap[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(heap, n, i);
}

// Extract max
Node extractMax(Node heap[], int *n) {
    Node root = heap[0];
    heap[0] = heap[--(*n)];
    heapify(heap, *n, 0);
    return root;
}

// Insert
void insert(Node heap[], int *n, Node key) {
    int i = (*n)++;
    heap[i] = key;
    while (i && heap[(i-1)/2].freq < heap[i].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

char* rearrangeString(char* str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) freq[str[i]]++;

    Node heap[256]; 
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            heap[n].ch = i;
            heap[n].freq = freq[i];
            n++;
        }
    }

    buildHeap(heap, n);

    char* result = (char*)malloc(strlen(str)+1);
    int idx = 0;

    Node prev = {'#', 0};

    while (n > 0) {
        Node current = extractMax(heap, &n);
        result[idx++] = current.ch;

        if (prev.freq > 0) insert(heap, &n, prev);

        current.freq--;
        prev = current;
    }

    result[idx] = '\0';
    if (idx != strlen(str)) return ""; // Impossible case
    return result;
}

int main() {
    char s1[] = "aab";
    char s2[] = "aaab";

    printf("Rearranged: %s\n", rearrangeString(s1)); // "aba"
    printf("Rearranged: %s\n", rearrangeString(s2)); // ""
    return 0;
}

