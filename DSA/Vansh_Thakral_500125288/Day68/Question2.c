#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256


typedef struct {
    char ch;
    int freq;
} Node;


void swap(Node *a, Node *b) {
    Node temp = *a; *a = *b; *b = temp;
}

void heapify(Node heap[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && heap[l].freq > heap[largest].freq) largest = l;
    if (r < n && heap[r].freq > heap[largest].freq) largest = r;
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

Node extractMax(Node heap[], int *n) {
    Node root = heap[0];
    heap[0] = heap[*n-1];
    (*n)--;
    heapify(heap, *n, 0);
    return root;
}

void insertHeap(Node heap[], int *n, Node newNode) {
    heap[*n] = newNode;
    int i = (*n)++;
    while (i && heap[(i-1)/2].freq < heap[i].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

char* rearrangeString(char *s) {
    int freq[MAX] = {0}, n = strlen(s);
    for (int i=0; s[i]; i++) freq[(int)s[i]]++;

    Node heap[MAX]; int size = 0;
    for (int i=0; i<MAX; i++) {
        if (freq[i] > 0) {
            heap[size].ch = i;
            heap[size].freq = freq[i];
            size++;
        }
    }

    for (int i=size/2-1; i>=0; i--) heapify(heap, size, i);

    char *result = (char*)malloc((n+1) * sizeof(char));
    int idx = 0;

    Node prev = {'#', -1};

    while (size > 0) {
        Node curr = extractMax(heap, &size);
        result[idx++] = curr.ch;

        if (prev.freq > 0) insertHeap(heap, &size, prev);

        curr.freq--;
        prev = curr;
    }

    result[idx] = '\0';

    if (idx != n) {
        free(result);
        return strdup(""); 
    }
    return result;
}

int main() {
    char s1[] = "aab";
    printf("%s\n", rearrangeString(s1)); 

    char s2[] = "aaab";
    printf("%s\n", rearrangeString(s2));

    return 0;
}

