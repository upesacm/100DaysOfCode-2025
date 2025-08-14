#include <stdio.h>

#define MAX 100

typedef struct {
    int val;
    int freq;
} Node;

Node heap[MAX];
int heapSize = 0;

void swap(Node *a, Node *b) {
    Node t = *a; *a = *b; *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].freq > heap[i].freq) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < heapSize && heap[l].freq < heap[smallest].freq) smallest = l;
    if (r < heapSize && heap[r].freq < heap[smallest].freq) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(Node node) {
    heap[heapSize] = node;
    heapSize++;
    heapifyUp(heapSize - 1);
}

Node pop() {
    Node root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

int main() {
    int n, k;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);

    int freq[MAX * 2] = {0}; 
    for (int i = 0; i < n; i++) freq[arr[i] + MAX]++;

    for (int i = 0; i < MAX * 2; i++) {
        if (freq[i] > 0) {
            Node node = {i - MAX, freq[i]};
            push(node);
            if (heapSize > k) pop();
        }
    }

    int result[k];
    for (int i = k - 1; i >= 0; i--) {
        result[i] = pop().val;
    }

    for (int i = 0; i < k; i++) printf("%d ", result[i]);
    printf("\n");
    return 0;
}
