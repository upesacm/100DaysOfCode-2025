#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& heap, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void heapifyUp(vector<int>& heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i] > heap[parent]) {
            swap(heap[i], heap[parent]);
            i = parent;
        } else break;
    }
}

void insertHeap(vector<int>& heap, int val) {
    heap.push_back(val);
    heapifyUp(heap, heap.size() - 1);
}

void deleteRoot(vector<int>& heap) {
    if (heap.empty()) return;
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(heap, heap.size(), 0);
}

int main() {
    vector<int> heap;

    insertHeap(heap, 20);
    insertHeap(heap, 15);
    insertHeap(heap, 8);
    deleteRoot(heap);

    for (int num : heap) cout << num << " ";
    cout << endl;

    return 0;
}
