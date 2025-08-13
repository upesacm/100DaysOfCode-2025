#include <vector>
#include <climits>
using namespace std;
class MinHeap {
private:
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    void bubbleUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    void bubbleDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        if (left < heap.size() && heap[left] < heap[minIndex])
            minIndex = left;
        if (right < heap.size() && heap[right] < heap[minIndex])
            minIndex = right;
        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            bubbleDown(minIndex);
        }
    }
public:
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size() - 1);
    }
    int extractMin() {
        if (heap.empty()) return INT_MAX;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            bubbleDown(0);
        }
        return minVal;
    }
    int getMin() {
        return heap.empty() ? INT_MAX : heap[0];
    }    
    bool isEmpty() {
        return heap.empty();
    }
    int size() {
        return heap.size();
    }
};
