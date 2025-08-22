#include <vector>
#include <climits>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void bubbleUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int largest = i;
            int l = left(i);
            int r = right(i);
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Insert a value into the max-heap
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }

    // Delete root (max element) and return it
    int deleteRoot() {
        if (heap.empty()) return INT_MIN; // or throw
        int rootVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            siftDown(0);
        }
        return rootVal;
    }

    // Current heap contents (by reference)
    const vector<int>& data() const { return heap; }

    bool isEmpty() const { return heap.empty(); }
    int size() const { return (int)heap.size(); }
};
