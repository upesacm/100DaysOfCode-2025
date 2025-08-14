#include <vector>
#include <queue>
using namespace std;
void sortKSortedArray(vector<int>& arr, int k) {
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int idx = 0;
    for (int i = 0; i <= k && i < n; ++i) {
        minHeap.push(arr[i]);
    }
    for (int i = k + 1; i < n; ++i) {
        arr[idx++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }
    while (!minHeap.empty()) {
        arr[idx++] = minHeap.top();
        minHeap.pop();
    }
}
