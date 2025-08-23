#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void replaceRoot(vector<int>& heap, int newElement) {
    if (heap.empty()) return;
    heap[0] = newElement;
    heapify(heap, heap.size(), 0);
}

int main() {
    vector<int> heap = {50, 30, 20, 15, 10, 8, 16};
    int newElement = 25;

    replaceRoot(heap, newElement);

    for (int num : heap) cout << num << " ";
    cout << endl;
    return 0;
}
