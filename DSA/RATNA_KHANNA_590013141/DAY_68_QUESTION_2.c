#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int freq;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapify(Node arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l].freq > arr[largest].freq) largest = l;
    if (r < n && arr[r].freq > arr[largest].freq) largest = r;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

Node extractMax(Node arr[], int *n) {
    Node root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

void insertHeap(Node arr[], int *n, Node key) {
    arr[*n] = key;
    int i = *n;
    (*n)++;
    while (i && arr[(i - 1) / 2].freq < arr[i].freq) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void rearrange(char str[]) {
    int n = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < n; i++) freq[(int)str[i]]++;
    Node heap[256];
    int heapSize = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i]) {
            heap[heapSize].ch = (char)i;
            heap[heapSize].freq = freq[i];
            heapSize++;
        }
    }
    for (int i = heapSize / 2 - 1; i >= 0; i--) heapify(heap, heapSize, i);
    char result[n + 1];
    int idx = 0;
    Node prev = {'#', 0};
    while (heapSize > 0) {
        Node curr = extractMax(heap, &heapSize);
        result[idx++] = curr.ch;
        curr.freq--;
        if (prev.freq > 0) insertHeap(heap, &heapSize, prev);
        prev = curr;
    }
    result[idx] = '\0';
    if (idx != n) printf("Output: \"\"\n");
    else printf("Output: \"%s\"\n", result);
}

int main() {
    char str[1000];
    printf("Enter string: ");
    scanf("%s", str);
    rearrange(str);
    return 0;
}
