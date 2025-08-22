#include <vector>
using namespace std;
static void siftDown(vector<int>& arr, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest == i) break;
        swap(arr[i], arr[largest]);
        i = largest;
    }
}
void convertMinToMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        siftDown(arr, n, i);
    }
}
