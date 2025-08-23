#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void bubbleUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void bubbleDown(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            bubbleDown(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0);
        return minVal;
    }
};

int main() {
    MinHeap h;
    h.insert(3);
    h.insert(2);
    h.insert(15);
    cout << h.extractMin() << endl; // Output: 2

    MinHeap h2;
    h2.insert(10);
    h2.insert(5);
    h2.insert(20);
    h2.insert(8);
    cout << h2.extractMin() << ", " << h2.extractMin() << endl; // Output: 5, 8
}
